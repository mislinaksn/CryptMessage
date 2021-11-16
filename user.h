#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class database{
	
	class User* kullanici;
	
	public:
	User&	readusers();
	
};
class Mesaj{
	public:
		
	string p;
    int gelenkisi;
	
	
	bool isitdefault(){
		if(p=="BOS_MESAJ"){
			return true;
		}
		else{
			return false;
		}
	}
	Mesaj(){
		p="BOS_MESAJ";
	}
	
	~Mesaj(){
		cout<<"dmm ile mesaj icin acilan hafiza temizlendi"<<endl;
	}
	
	void printmesaj(){
		cout<<p<<endl;
	}
	
	void setmesaj(int a,char b){

		p[a]=b;
		
	}
	
};


class User{
	
	friend ostream& operator<<(ostream& out, const User& obj);
	friend istream& operator>>(istream& in, User& obj);
	
	static int aktifkullanici;
	
	private:
		string kullaniciadi;
		string sifre;
		int array1[128];
		int array2[128];
		
		
		
	public:
		int arraysira;
		class Mesaj mesajkutusu[10];
	    //ctr
		User();
		User(string, string);
		User(const User& other);
		User& operator=(const User& other);
		User operator+(const User& other);
		
		//set functions
		void setKullanici(string);
		void setSifre(string);
		void setarraysira(int);
		//get functions
		string getKullanici();
		string getSifre();
		//

			
	    void mesaj_gonder(User obj[5]);
	    void mesaj_ac(User obj[5]);
	    void resetarray1();
	    void resetarray2();
	    int getarray1(int);
	    int getarray2(int);
	    void AllUserDosya();
        void RegisterUserDosya();
        friend bool kullanici_ara(string);
	    void karistir1();
	    void karistir2();
	    
};

#endif
