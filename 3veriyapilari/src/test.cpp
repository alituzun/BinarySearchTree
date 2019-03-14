#include "AnaAgac.hpp"
#include <ctime>

int main(){
	string sayi;
	srand(time(0));
	cout<<"Sayi gir :";
	cin>>sayi;
	AnaAgac *agacim=new AnaAgac();
	for(int j=0;sayi[j]!='\0';j++)
	{
		BinarySearchTree *agac = new BinarySearchTree();
		for(int i=0;(sayi[j] - '0')!= agac->Yukseklik();i++)
		{
			agac->Ekle(rand() % 1000);
		}
		agacim->Ekle(agac);
	}
	int sec=0;
	do{
		agacim->Inorder();
		cout<<"1. Agaclardan Maksimum Degeri Cikar"<<endl;
		cout<<"2. Agaclardan Minimum Degeri Cikar"<<endl;
		cout<<"3. Tum Agaclari Level Order Yazdir"<<endl;
		cout<<"4. Cikis"<<endl;
		cout<<"=>";
		cin>>sec;
		switch(sec){
			case 1:
			{
				agacim->maksCikar();
				break;
			}
			case 2:
			{
				agacim->minCikar();
				break;
			}
			case 3:
			{
				agacim->Preorder();
				break;
			}
		}
	}while(sec != 4);
	
	

	
	/*agacim->Inorder();
	agacim->maksCikar();
	agacim->Preorder();
	cout<<endl<<"Yukseklik :";
	cout<<agacim->Yukseklik();*/
	/*cout<<endl<<"Preorder :";
	agac->Preorder();
	cout<<endl<<"Postorder :";
	agac->Postorder();
	cout<<endl<<endl;
	agac->Sil(15);
	cout<<"Kok silindikten sonra:"<<endl;
	cout<<"Inorder :";
	agac->Inorder();
	cout<<endl<<"Preorder :";
	agac->Preorder();
	cout<<endl<<"Postorder :";
	agac->Postorder();
	cout<<endl<<endl;*/
	delete agacim;
	return 0;
}