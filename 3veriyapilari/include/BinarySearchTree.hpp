#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cmath>

#include <iostream>
using namespace std;

struct Dugum{
	int veri;
	Dugum *sol;
	Dugum *sag;
	Dugum(const int& vr,Dugum *sl=NULL,Dugum *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;
	}
};

class BinarySearchTree{
	private:
		Dugum *root;
		
		void AraveEkle(Dugum *&alt_Dugum, const int &yeni){
			if(alt_Dugum == NULL) alt_Dugum = new Dugum(yeni);
			else if(yeni < alt_Dugum->veri)
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni > alt_Dugum->veri)
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayn� eleman var.
		}
		bool AraveSil(Dugum *&alt_Dugum,const int &yeni)
		{			
			if(alt_Dugum == NULL) return false; //Eleman yok
			if(alt_Dugum->veri == yeni)
				return DugumSil(alt_Dugum);
			else if(yeni < alt_Dugum->veri)
				return AraveSil(alt_Dugum->sol,yeni);
			else
				return AraveSil(alt_Dugum->sag,yeni);
		}
		bool DugumSil(Dugum *&alt_Dugum)
		{			
			Dugum *silinecekDugum = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
			else{
				silinecekDugum = alt_Dugum->sol;
				Dugum *ebeveynDugum = alt_Dugum;
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
		void Inorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<alt_Dugum->veri<<" ";
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<alt_Dugum->veri<<" ";
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);				
				cout<<alt_Dugum->veri<<" ";
			}
		}		
		int Yukseklik(Dugum *alt_Dugum){
			if(alt_Dugum == NULL) return -1; // Ortada d���m yoksa y�kseklik anlams�zd�r. Kodun �al��mas� ad�na -1 verilmektedir.
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		public:
			bool tekrarOlustur;
			BinarySearchTree(){
				root = NULL;
				tekrarOlustur=false;
			}
			bool Bosmu() const{
				return root == NULL;
			}
			void Ekle(const int &yeni)
			{
				AraveEkle(root,yeni);
			}
			void Sil(const int &veri)
			{
				if(AraveSil(root,veri) == false); //throw ElemanYok();
			}
			
			void maksCikar() {
				Dugum* gezici=root;
				while(gezici->sag!=NULL)gezici=gezici->sag;
				Sil(gezici->veri);
				tekrarOlustur=true;
			}
			void minCikar() {
				Dugum* gezici=root;
				while(gezici->sol!=NULL)gezici=gezici->sol;
				Sil(gezici->veri);
				tekrarOlustur=true;
			}
			void Inorder() const{
				Inorder(root);
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
			~BinarySearchTree(){
				Temizle();
			}		
};

#endif