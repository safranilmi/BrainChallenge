#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Master.h"
#include "function.h"
using namespace std;

int main(){
	char scene[6]={'#','@','*','+','/','-'};
	int temp; //variabel untuk sembarang int
	int score = 0; //jumlah benar
	int hapus; //variabel untuk Del
	int no = 1; //variabel penghitung scene
	string pilihan;
	
	Queue Q;
	CreateEmpty(&Q);
	
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); //warna

	/*memutar musik*/
	 PlaySound(TEXT("sound\\ls.wav"),NULL,SND_ASYNC|SND_LOOP);
	
	/*tampilan amainnwal*/
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY); //warna
	 
	/*tampilan awal*/

	brain(); //tampilan brain challenge
	cout<<endl<<endl;
	
	cout<<"[1] Main"<<endl;
	cout<<"[0] Keluar"<<endl;
	cout<<"[9] Aturan Permainan"<<endl;
	cout<<endl;
	cout<<"Pilihan : ";
	cin>>pilihan;
	system("CLS");

	/*jika pilihan 1 berarti main*/
	if(pilihan == "1"){
		brain();
		cout<<endl<<endl;

		Menu_Masuk();
		
		/*mengeluarkmainnan 3 scene pertama*/
		/*memutar musik*/
	
		PlaySound(TEXT("sound\\op.wav"),NULL,SND_ASYNC|SND_LOOP); //memutar musik
		
		/*pemunculan 3 scene awal*/
		for(int i=1; i<=3; i++){
		
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
			cout << "scene " << i << endl;
		
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
			Scene(scene, &temp); //mengisi satu scene dengan karakter
			cout << endl;
			Add(&Q,temp); //menambah jumlah karakter *
			
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY); //pemberian warna
			
			cout<<"\nNote : Ingatlah jumlah * yang muncul pada scene ini\n";
			balok(25); //rekursif loading bar 25 bar dalam 5 detik
			
			system("cls");
		}

		/*menanyakan jumlah bintang*/
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		cout << "Berapa jumlah Bintang di scene " << no << " ?\n";
		
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY); //pemberian warna
		
		cin >> temp;
		system("cls");

		/*jika jawaban benar*/
		while(temp == InfoHead(Q)){

			PlaySound(TEXT("sound\\airhorn.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound
			
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY); //pemberian warna
			
			b(); //benar
			Sleep(2000); 												//lama waktu musik berjalan
			
			PlaySound(TEXT("sound\\op.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound

			no = no + 1;
			score = score + 10;	// Score bertambah 10 setiap jawaban benar
			Del(&Q,&hapus);	//menghapus node di queue
			system("cls");

			/*mengeluarkan scene baru*/
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			
			cout << "scene " << no+2 << endl;
			
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			Scene(scene, &temp); //mengeluarkan scene dan menghitung banyak *
			cout << endl;
			Add(&Q,temp); //memasukan jumlah * ke master Queue
			
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
			
			cout<<"\nNote : Ingatlah jumlah * yang muncul pada scene ini\n";
			balok(25); //loading bar 5 detik
																
			system("cls"); //membersihkan layar

			/*menanyakan lagi jumlah bintang*/
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			cout << "Berapa jumlah Bintang di scene " << no << " ?\n";
			
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
			
			cin >> temp;
			system("cls");
		}

		/*jika jawaban salah*/
		PlaySound(TEXT("sound\\buzzer.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound
		
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		
		s(); //salah
		Sleep(1500);
		system("cls");
		
		/*tampilan game over*/
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		
		PlaySound(TEXT("sound\\over.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound
		
		o(); //game over
		Sleep(2500);
		
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		cout  << "\n\nJawaban yang benar adalah ";
		
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		
		cout<< InfoHead(Q)<<endl;
				
		/*menunjukkamainnn jumlah jawaban benar*/
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY); //memberi warna
		
		cout << "Score Anda = ";
		
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY); //memberi warna
		
		cout << score << endl;
		
		/*Memperbaharui Highscore*/
		highscore = score;
		NewHighScore(); //mengganti score yang lama dengan score yang baru jika nilainya lebih besar dari nilai yang disimpan
		system("pause");
	}else if(pilihan == "0"){
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY); //memberi warna
		
		PlaySound(TEXT("sound\\y2.wav"),NULL,SND_ASYNC|SND_LOOP); //memberi lagu
		
		t(); //keluar (pilihan == 0)
		
		system("pause");
	}else if(pilihan == "9"){
		aturan(); //aturan main
		main(); //kembali ke menu awal
	}else{
		cout << "tolong lihat pilihannya" << endl;
		Sleep(2000);
		system("cls");
		main(); //kembali ke menu awal
	}
	return 0;
}
