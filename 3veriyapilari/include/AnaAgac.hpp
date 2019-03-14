#ifndef ANAAGAC_HPP
#define ANAAGAC_HPP

#include "BinarySearchTree.hpp"

struct AnaAgacDugum{
	BinarySearchTree* veri;
	AnaAgacDugum *sol;
	AnaAgacDugum *sag;
	AnaAgacDugum(BinarySearchTree* vr,AnaAgacDugum *sl=NULL,AnaAgacDugum *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;
	}
};

class AnaAgac{
	private:
		AnaAgacDugum *root;
		
		void AraveEkle(AnaAgacDugum *&alt_Dugum, BinarySearchTree* yeni){
			if(alt_Dugum == NULL) alt_Dugum = new AnaAgacDugum(yeni);
			else if(yeni->Yukseklik() < alt_Dugum->veri->Yukseklik())
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni->Yukseklik() > alt_Dugum->veri->Yukseklik())
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayn� eleman var.
		}
		bool AraveSil(AnaAgacDugum *&alt_Dugum,BinarySearchTree* yeni)
		{			
			if(alt_Dugum == NULL) return false; //Eleman yok
			if(alt_Dugum->veri->Yukseklik() == yeni->Yukseklik())
				return DugumSil(alt_Dugum);
			else if(yeni->Yukseklik() < alt_Dugum->veri->Yukseklik())
				return AraveSil(alt_Dugum->sol,yeni);
			else
				return AraveSil(alt_Dugum->sag,yeni);
		}
		bool DugumSil(AnaAgacDugum *&alt_Dugum)
		{			
			AnaAgacDugum *silinecekDugum = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
			else{
				silinecekDugum = alt_Dugum->sol;
				AnaAgacDugum *ebeveynDugum = alt_Dugum;
				while(silinecekDugum->sag != NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				alt_Dugum->veri = silinecekDugum->veri;
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
		void Inorder(AnaAgacDugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<"Inorder :";
				alt_Dugum->veri->Inorder();
				cout<<endl;
				cout<<"Yukseklik :";
				cout<<alt_Dugum->veri->Yukseklik();
				cout<<endl;
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(AnaAgacDugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<"Preorder :";
				alt_Dugum->veri->Preorder();
				cout<<endl;
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(AnaAgacDugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);
				cout<<"Postorder :";			
				alt_Dugum->veri->Postorder();
				cout<<endl;
			}
		}		
		int Yukseklik(AnaAgacDugum *alt_Dugum){
			if(alt_Dugum == NULL) return -1; // Ortada d���m yoksa y�kseklik anlams�zd�r. Kodun �al��mas� ad�na -1 verilmektedir.
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		public:
			AnaAgac(){
				root = NULL;
			}
			bool Bosmu() const{
				return root == NULL;
			}
			void Ekle(BinarySearchTree* yeni)
			{
				AraveEkle(root,yeni);
			}
			void Inorder() const{
				Inorder(root);
			}

			void maksCikar() {
				maksCikar(root);
			}
			void maksCikar(AnaAgacDugum *alt_Dugum){
			if(alt_Dugum != NULL){
				maksCikar(alt_Dugum->sol);
				int tempYukseklik=alt_Dugum->veri->Yukseklik();
				alt_Dugum->veri->maksCikar();
				if(tempYukseklik!=alt_Dugum->veri->Yukseklik())
				{
					BinarySearchTree *agac = new BinarySearchTree();
					for(int i=0;tempYukseklik!= agac->Yukseklik();i++)
					{
						agac->Ekle(rand() % 1000);
					}
					delete alt_Dugum->veri;
					alt_Dugum->veri=agac;
				}
				maksCikar(alt_Dugum->sag);
				}
			}
			void minCikar(){
				minCikar(root);
			}
			void minCikar(AnaAgacDugum *alt_Dugum) {
			if(alt_Dugum != NULL){
				minCikar(alt_Dugum->sol);
				int tempYukseklik=alt_Dugum->veri->Yukseklik();
				alt_Dugum->veri->minCikar();
				if(tempYukseklik!=alt_Dugum->veri->Yukseklik())
				{
					BinarySearchTree *agac = new BinarySearchTree();
					for(int i=0;tempYukseklik!= agac->Yukseklik();i++)
					{
						agac->Ekle(rand() % 1000);
					}
					
					delete alt_Dugum->veri;
					alt_Dugum->veri=agac;
				}
				minCikar(alt_Dugum->sag);
				}
			}
			void Preorder() const{
				Preorder(root);
			}
			void Postorder() const{
				Postorder(root);
			}
			void Temizle(){
				while(!Bosmu()) DugumSil(root);
			}
			int Yukseklik(){
				return Yukseklik(root);
			}
			~AnaAgac(){
				Temizle();
			}		
};

#endif