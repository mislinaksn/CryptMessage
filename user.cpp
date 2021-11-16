#include "user.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
	//	string kullaniciadi;
	//	string sifre;
	//	int array1[128];
	//	int array2[128];
	//	int key;
using namespace std;

User::User(){
	this->kullaniciadi="default";
	this->sifre="default";
	this->arraysira=0;
	this->resetarray1();
	this->resetarray2();
}

User::User(string a,string b){
	this->kullaniciadi=a;
	this->sifre=b;
	this->resetarray1();
	this->resetarray2();
}

User::User(const User& other){
	this->kullaniciadi=other.kullaniciadi;
	this->sifre=other.sifre;
for(int i=0;i<128;i++){
    this->array1[i]=other.array1[i];
    this->array2[i]=other.array2[i];   	
	}
	this->arraysira=other.arraysira;
}

User& User::operator=(const User& other){
	this->kullaniciadi=other.kullaniciadi;
	this->sifre=other.sifre;
for(int i=0;i<128;i++){
    this->array1[i]=other.array1[i];
    this->array2[i]=other.array2[i];   	
	}
	this->arraysira=other.arraysira;	
	return *this;
}


User User::operator+(const User& other){
	User nesne;
	
	nesne.kullaniciadi= this->kullaniciadi + other.kullaniciadi ;
	nesne.sifre= this->sifre + other.sifre ;
	nesne.arraysira= this->arraysira + other.arraysira ;
	for(int i=0;i<128;i++){
		nesne.array1[i] = this->array1[i] + other.array1[i];
		nesne.array2[i] = this->array2[i] + other.array2[i];
	}
	return nesne;
	
}

ostream& operator<<(ostream& out, const User& obje){
	//BU FONKSÝYONU MESAJ KUTUSU GÖRÜNTÜLEMEK ÝÇÝN KULLANACAÐIZ!!!
}

string User::getKullanici(){
	return this->kullaniciadi;
}

string User::getSifre(){
	return this->sifre;
}

/*int User::getkey(){
	return this->key;
}

void User::setkey(int key){
	this->key=key;
}*/

void User::setKullanici(string a){
	this->kullaniciadi=a;
}

void User::setSifre(string b){
	this->sifre=b;
}

void User::setarraysira(int a){
	this->arraysira=a;
}

void User::resetarray1(){
		for(int i=0;i<128;i++){
			array1[i]=i;
		}
	}
	
void User::resetarray2(){
		for(int i=0;i<128;i++){
			array2[i]=i+128;
		}
	}

int User::getarray1(int j){
	return array1[j];
}

int User::getarray2(int j){
	return array2[j];
}

void User::AllUserDosya(){ //bütün kullanycylaryn oldu?u dosyaya kullanycy ady, ?ifresi ve arraylerinin yazylamsy
	
	fstream file;
	file.open("all_user.dat", ios::app);
	if(!file.is_open()) { cout << "Dosya acilamadi..."; exit(0);	}
	
	file << kullaniciadi << endl;
	file << sifre << endl;
	
	for(int i=0; i<128; i++){
	file << array1[i] << " ";	
	}
	file << endl;
	for(int i=0; i<128; i++){
	file << array2[i] <<" ";
    }
	file << endl;
	
	file.close();
	
}

void User::RegisterUserDosya(){ //girilen kullanycy ady ve ?ifresinin sisteme kayytly olup olmady?ynyn kontrolü için kullanycy ve ?ifresinin ayry bir dosyada tatulmasy
	
	fstream file;
	file.open("register_user.dat", ios::app);
	if(!file.is_open()) { cout << "Dosya acilamadi..."; exit(0);	}
	
	file << kullaniciadi << endl;
	file << sifre << endl;
	
	file.close();
}

bool kullanici_ara(string kullanici){ //kullanycy tarafyndan girilen kullanici adi ve sifresinin sistemde olup olmadiginin kontrolü
	
	fstream file;
	file.open("register_user.dat", ios::in);

	
	string line,ad,key;

	
	if(file.is_open()){
	
		while(getline(file,line)){ // bilgiler dosyadan satyr satyr okuma yapylyyor
			if(kullanici==line){ 
			cout << "Kullanici adi ve sifre bulunmustur."<< endl; //kullanycy bulunmustur dönütü saglanyyor.
			return true;
		}
			
	}
        cout << "Girdiginiz bilgilerle kullanici eslesmesi saglanamamistir." << endl;
		return false;	
}
}
void User::karistir1(){
	random_shuffle(&array1[0],&array1[128]);
}
void User::karistir2(){
	random_shuffle(&array2[0],&array2[128]);
}


void User::mesaj_gonder(User obj[5]){
	
	cout << "Mesaj gondereceginiz kisinin adini giriniz: " << endl;
	
	string a;
	cin>>a;
	int sira;
	
	
	for(int abc=0;abc<5;abc++){
	
		if(obj[abc].getKullanici()==a){
			sira=abc;
			cout << abc <<endl;
		}
	}
	
	
	
	if(kullanici_ara(a)==true){
		
		cout<<"Gondereceginiz mesaji giriniz: "<<endl;
		string b;
		
		fflush(stdin);
		getline(cin,b);
				
        char * tab2 = new char [b.length()+1];
        strcpy (tab2, b.c_str());
        
        int h,c=strlen(tab2);
        char sifrelenmis[c];
        
    for(int z=0;z<c; z++){
    	h=(int)tab2[z];
    	if(h<=127)
		{
    	sifrelenmis[z]=(char)getarray1(h);
		}
		else
		{
    	sifrelenmis[z]=(char)obj[sira].getarray2(h);			
		}
	}

	char gonderi[c];
	for(int u;u<c;u++){
		gonderi[u]=sifrelenmis[u];
	}
	
	int y=0;
	
	obj[sira].mesajkutusu[y].gelenkisi=this->arraysira;
	
	while(y<10){
		if(obj[sira].mesajkutusu[y].isitdefault()==true){

			        
			for(int m=0;m<c;m++){
				obj[sira].mesajkutusu[y].setmesaj(m,gonderi[m]);
				
			}

			
			break;
		}
		
		else{
			cout << "Mesaj atamasi yapilamadi..." << endl;
		}
		
	y++;	
	}
	
	}
	else{
		cout << "Mesaj gonderilemez " << endl;
	}
}

void User::mesaj_ac(User obj[5]){
	int mesajsira;
	int tempint;
	bool tekrar=true;
	
	while(tekrar=true){
		if(tekrar==true){
		cout << "Acmak istediginiz mesajin numarasini giriniz: " << endl;
		cin  >> tempint;	
		mesajsira=tempint-1;
		string tempo=this->mesajkutusu[mesajsira].p;
	    int sz=tempo.length()+1;
	    char desifrelenmis[sz];
		if(this->mesajkutusu[mesajsira].isitdefault()==true){  cout<<"goruntulemek istediginiz siradaki mesaj bostur..."<<endl<<this->mesajkutusu[mesajsira].p<<endl; 	}
		else{
		int temp=this->mesajkutusu[mesajsira].gelenkisi;
		//obj[temp]
		
		char * tab2 = new char [this->mesajkutusu[mesajsira].p.length()+1];
        strcpy (tab2, this->mesajkutusu[mesajsira].p.c_str());
		
int n;
int size=strlen(tab2);

     int konum,konum2;
     int l;
     
     for(l=0;l<size; l++){
    	n=(int)tab2[l];
    if(n<=127){
    for(int ara=0;ara<=127;ara++){
	if(obj[temp].getarray1(ara)==n){
	konum=ara;
	break;
	}
	}
    	desifrelenmis[l]=(char)konum;	
		}
    	else{
    for(int arama=0;arama<=127;arama++){
	if(this->getarray2(arama)==n){
	konum2=arama;
	break;
	}
	}
    	desifrelenmis[l]=(char)konum2;
		}
	}   		
	
	    int z;
		for(z=0;z<l;z++){
			cout<<desifrelenmis[z];
		}
		cout<<endl;
		
		}
		}
	cout<<"Baska mesaj acmak ister misiniz?"<<endl<<"Evet icin 1,Hayir icin 0 tuslayiniz: "<<endl;
	int tekrarsecim;
	cin>>tekrarsecim;
	if(tekrarsecim==1){tekrar=true;	}
	else if(tekrarsecim==0){tekrar=false; break;	}	
		
	}
		
}







