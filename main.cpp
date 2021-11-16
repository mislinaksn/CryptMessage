#include <iostream>
#include "user.h"
#include <windows.h>
#include <stdlib.h>

void girisanimasyonu(){
	cout<<"============================================================="<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n|_________                        __                   __   |"<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n\n|\\_   ___ \\_______ ___.__._______/  |_  ____ ___  ____/  |_ |"<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n\n\n|/    \\  \\/\\_  __ <   |  |\\____ \   __\\/ __ \\\\  \\/  /\\   __\\\\|"<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n\n\n\n|\\     \\____|  | \\/\\___  ||  |_> >  | \\  ___/ >    <  |  |  |"<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n\n\n\n\n| \\______  /|__|   / ____||   __/|__|  \\___  >__/\\_ \\ |__|  |"<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n\n\n\n\n\n|        \\/        \\/     |__|             \\/      \\/       |"<<endl;
	Sleep(140);
	system ("CLS");
cout<<"\n\n\n\n\n\n\n============================================================="<<endl;
	Sleep(140);
	system ("CLS");

cout<<"============================================================="<<endl;
cout<<"|_________                        __                   __   |"<<endl;
cout<<"|\\_   ___ \\_______ ___.__._______/  |_  ____ ___  ____/  |_ |"<<endl;
cout<<"|/    \\  \\/\\_  __ <   |  |\\____ \   __\\/ __ \\\\  \\/  /\\   __\\\\|"<<endl;
cout<<"|\\     \\____|  | \\/\\___  ||  |_> >  | \\  ___/ >    <  |  |  |"<<endl;
cout<<"| \\______  /|__|   / ____||   __/|__|  \\___  >__/\\_ \\ |__|  |"<<endl;
cout<<"|        \\/        \\/     |__|             \\/      \\/       |"<<endl;
cout<<"============================================================="<<endl;	
	Sleep(300);
	system ("CLS");	
	Sleep(300);	
cout<<"============================================================="<<endl;
cout<<"|_________                        __                   __   |"<<endl;
cout<<"|\\_   ___ \\_______ ___.__._______/  |_  ____ ___  ____/  |_ |"<<endl;
cout<<"|/    \\  \\/\\_  __ <   |  |\\____ \   __\\/ __ \\\\  \\/  /\\   __\\\\|"<<endl;
cout<<"|\\     \\____|  | \\/\\___  ||  |_> >  | \\  ___/ >    <  |  |  |"<<endl;
cout<<"| \\______  /|__|   / ____||   __/|__|  \\___  >__/\\_ \\ |__|  |"<<endl;
cout<<"|        \\/        \\/     |__|             \\/      \\/       |"<<endl;
cout<<"============================================================="<<endl;
	Sleep(300);
	system ("CLS");	
	Sleep(300);	
cout<<"============================================================="<<endl;
cout<<"|_________                        __                   __   |"<<endl;
cout<<"|\\_   ___ \\_______ ___.__._______/  |_  ____ ___  ____/  |_ |"<<endl;
cout<<"|/    \\  \\/\\_  __ <   |  |\\____ \   __\\/ __ \\\\  \\/  /\\   __\\\\|"<<endl;
cout<<"|\\     \\____|  | \\/\\___  ||  |_> >  | \\  ___/ >    <  |  |  |"<<endl;
cout<<"| \\______  /|__|   / ____||   __/|__|  \\___  >__/\\_ \\ |__|  |"<<endl;
cout<<"|        \\/        \\/     |__|             \\/      \\/       |"<<endl;
cout<<"============================================================="<<endl;
}

int main(){
	
	User obje[5];
	
    obje[0].setKullanici("tuba");
	obje[0].setSifre("cryptext100");
	obje[0].karistir1();
	obje[0].karistir2();	
	obje[0].RegisterUserDosya();
	obje[0].AllUserDosya();
	obje[0].setarraysira(2);	
	
	obje[1].setKullanici("enes");
	obje[1].setSifre("1234Enes");
	obje[1].karistir1();
	obje[1].karistir2();
	obje[1].RegisterUserDosya();
	obje[1].AllUserDosya();
	obje[1].setarraysira(1);
	
    obje[2].setKullanici("mert");
	obje[2].setSifre("123mert123");
	obje[2].karistir1();
	obje[2].karistir2();	
	obje[2].RegisterUserDosya();
	obje[2].AllUserDosya();
	obje[2].setarraysira(2);
	
    obje[3].setKullanici("mislina");
	obje[3].setSifre("mislina12345..");
	obje[3].karistir1();
	obje[3].karistir2();	
	obje[3].RegisterUserDosya();
	obje[3].AllUserDosya();
	obje[3].setarraysira(2);
	
    obje[4].setKullanici("selim");
	obje[4].setSifre("inf212");
	obje[4].karistir1();
	obje[4].karistir2();	
	obje[4].RegisterUserDosya();
	obje[4].AllUserDosya();
	obje[4].setarraysira(2);
	
			
	girisanimasyonu();
	
		
		BASTAN:
	cout<<"Sisteme giris icin kullanici adi giriniz: "<<endl;
	string tempname;
	cin>>tempname;
	cout<<"sifre giriniz: "<<endl;
	string tempsifre;
	cin>>tempsifre;
	int id;
	int bulunamadi=0;
	bool giris=false;
	
	for(int dongu=0;dongu<5;dongu++){
		if(tempname==obje[dongu].getKullanici() && tempsifre==obje[dongu].getSifre()){
			giris=true;
			cout<<"giris yapildi. yonlendiriliyorsunuz."<<endl<<endl;
			id=dongu;
		}
		else{bulunamadi++;	}
	}	
		if(bulunamadi==5){
			cout<<"Hatali giris,program kapatiliyor..."<<endl;
			return 0;
		}		
		if(giris==true){
			SECIM:
			cout<<"Hangi islemi yapmak istersiniz: "<<endl<<"1-Mesaj gonder\n"<<"2-Mesaj ac\n"<<"3-Tum mesaj kutusunu goster\n"<<"4-Cikis\n"<<"5-Ekrani temizleme"<<endl;
			int menusecim;
			cin>>menusecim;
			try {
			if(menusecim==1){
				obje[id].mesaj_gonder(obje);
				goto SECIM;
			}
			else if(menusecim==2){
				obje[id].mesaj_ac(obje);
				goto SECIM;
			}
			else if(menusecim==3){
	cout<<endl<<endl<<"Sayin "<<obje[id].getKullanici()<<" , Mesaj kutunuz asagidaki gibidir."<<endl;
	for(int a=0;a<10;a++){
	obje[id].mesajkutusu[a].printmesaj();
	cout<<endl;
	}
	goto SECIM;
			}
			else if(menusecim==4){
				goto BASTAN;
			}
			else if(menusecim==5){
				system ("CLS");
				goto SECIM;
			}
			else{
				throw menusecim;
			}				
			}
			catch(int menusecim){
				cout<<menusecim<<" gecerli bir giris opsiyonu degildir."<<endl;
				goto SECIM;
			}

		/*   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught \n";
   }
    */	//hata yakalama
		}
		
		
	
	
	system("pause");
	return 0;
}
