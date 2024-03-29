#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

int pilih; void pilihan();
void insert_data();
void hapus_data();
void cetak_data();

struct node{
 int nomorinduk;
 char nama [40];
 char gender [20];
 float nilai;
 node *prev, *next;
};

node *baru, *head=NULL, *tail=NULL,*help,*del;

int main(){
 do{
  system("cls");
  cout<<"\tLIN. DOUBLY LINKED LIST"<<endl;
  cout<<"\t=========================="<<endl;
  cout<<"\t1. INSERT DATA"<<endl;
  cout<<"\t2. HAPUS DATA"<<endl;
  cout<<"\t3. CETAK DATA"<<endl;
  cout<<"\t4. EXIT"<<endl;
  cout<<"\tPilihan (1 - 4) : ";
  cin>>pilih;
  cout<<endl<<endl;
  pilihan();
  cout<<"==============================="<<endl;
 }
 while(pilih!=4);
}

void pilihan(){
 if(pilih==1)
 insert_data();
 else if(pilih==2)
 hapus_data();
 else if(pilih==3)
 cetak_data();
 else
 {
  cout<<"EXIT";
  cout<<"\nSampai Jumpa lagi"<<endl;
 }
}

void buat_baru(){
 baru = new(node);
 cout<<"Masukkan Nomor Induk : ";cin>>baru->nomorinduk;
 cout<<"Masukkan Nama : ";cin>>baru->nama;
 cout<<"Masukkan Gender : ";cin>>baru->gender;
 cout<<"Masukkan Nilai : ";cin>>baru->nilai;
 cout<<"\n\t---Data telah dimasukkan---";
 cout<<"\n\nPRESS ENTER TO CONTINUE...";
 getch();
 baru->prev=NULL;
 baru->next=NULL;
}

void insert_data(){
 buat_baru();
 if(head==NULL)
 {
  head=baru;
  tail=baru;
 }
 else
 {
  baru->next=head;
  head->prev=baru;
  head=baru;
 }
 cout<<endl<<endl;
}

void hapus_data(){
 int hapus,nomorinduk;
 if(head==NULL)
 {
  cout<<"\nLinked List kosong, \nPenghapusan tidak dapat dilakukan"<<endl;
 }
 else
 {
  hapus=head->nomorinduk;
  cout<<"\nData yang dihapus adalah ";
  cin>>nomorinduk;
  del = head;
  head = head->next;
  delete del;
 }
}

void cetak_data(){
 if (head==NULL)
 cout<<"\nData tidak dapat ditemukan!"<<endl; 
 else
 {
  help=head;
  while(help!=NULL)
  {
   cout<<" Nomor Induk : "<<help->nomorinduk;
   cout<<" Nama : "<<help->nama;
   cout<<" Gender : "<<help->gender;
   cout<<" Nilai : "<<help->nilai<<endl;
   help=help->next;
  }
 }
getch();
}
