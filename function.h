#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
using namespace std;

/*--------Variabel Bebas--------*/
string username, password, filename;
int highscore; 
/*------------------------------*/

void Menu_Masuk();

void brain();

int main();

void Scene(char X[], int *jumlah){ /*fungsi untuk mengeluarkan scene dan menghitung jumlah bintang*/
	*jumlah = 0;
	int v;

	srand(time(NULL));
	for(int i=0; i<15; i++){
		v = rand() % 6;
		cout << X[v] << " ";
		if(X[v] == '*'){
			*jumlah = *jumlah + 1;		 
		}
	}
}

/* pembuatan file eksternal */
void NewHighScore (){
	ifstream baca; //menginputkan data dari file eksternal ke program
	ofstream tulis; //mengginputkan data dari program ke file eksternal
	string data;
	int nscore;
	
	filename = username+".txt"; //menyimpan nama file ke variabel filename 
	baca.open(filename.c_str()); //membuka file sesuai dengan nama username
	
	/*perulangan pembacaan data dalam file eksternal*/
	for(int i=0; i<3; i++){
		baca >> data; //membaca data yang diinputkan
	}
	
	nscore = atoi(data.c_str()); //mengubah string ke integer
	baca.close(); //menutup fungsi yang membaca file eksternal
	
	 /*menuliskan ke file eksternal*/
	if (highscore > nscore){
		tulis.open(filename.c_str());
		tulis << username << endl; 
		tulis << password << endl;
		tulis << highscore;
		tulis.close();
	}
}

/*biar bisa berfungsi gotoxy*/
/*mengatur koordinat*/
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void kunci(){
	char c;
	password = ""; //password = null
	while(c != '\r'){ //perulangan sampai 'Enter'
        c = getch(); //mengambil karakter yang diinputkan
     if(c == '\b'){   //jika 'Backspace' ditekan
        if(password.size() != 0){  //jika password ada isinya, hapus isinya          
           cout << "\b \b";
           password.erase(password.size() - 1, 1); //fungsi menghapus password (karakter terakhir)
        }
        continue; //melanjutkan while
    }else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        password += c; //banyak jumlah karakter password
        cout << "*";
    }else
        continue;
    }    
}

void Daftar(){
	system("cls");
	brain();
	
	/*mengatur koordinat*/
	gotoxy(0,15);cout << "Username 	: "; 
	gotoxy(0,16);cout << "Password 	: "; 
	gotoxy(20,15);cin >> username;
	gotoxy(20,16); kunci();
	
	/*menulis ke file eksternal*/
	ofstream tulis;
	
	highscore = 0;
	filename = username+".txt";
	tulis.open(filename.c_str());
	tulis << username << endl;
	tulis << password << endl;
	tulis << highscore;
	tulis.close();
	
	system("cls");
	Menu_Masuk(); //kembali ke menu masuk

}

void Masuk(){
	system("cls");
	brain();
	
	cout<<endl<<endl;
	gotoxy(0,15);cout << "Username 	: "; 
	gotoxy(0,16);cout << "Password 	: "; 
	gotoxy(20,15);cin >> username;
	gotoxy(20,16); kunci();
	
	ifstream baca;
	
	filename = username+".txt";//membuat file external sesuai username
	baca.open(filename.c_str());
	
	string tempUsername, tempPassword, tempHighscore;
	
	baca >> filename;
	tempUsername = filename;
	baca >> filename;
	tempPassword = filename;
	baca >> filename;
	tempHighscore = filename;
	
	if(username == tempUsername && password == tempPassword){
		system("cls");
		cout << "Hallo " << tempUsername << "!, Login Berhasil!" << endl;
		cout << "Username	: ";
		cout << tempUsername << endl;
		cout << "Highscore	: "<< tempHighscore;
		cout << endl;
		
		cout << "\nMari bermain" << endl;
		system("pause");
	}else{
		system("cls");
		cout << "Login Gagal!" << endl;
		if(username!=tempUsername){
			cout << "Username ";
		}else if(password!=tempPassword){
			cout << "Password ";
		}
		cout << "Salah!" << endl;
		system("pause");
		system("cls");
		
		Menu_Masuk();
	}
	baca.close();
}

void Menu_Masuk(){
	system("cls");
	brain();
	cout<<endl<<endl;
	
	string pilihan;

	cout<<"--- REGISTER OR LOGIN ---"<<endl;
	cout<<"[1] Daftar"<<endl;
	cout<<"[0] Masuk"<<endl;
	cout<<"[9] Kembali"<<endl;
	cout<<endl;
	cout<<"Pilihan : ";
	cin>>pilihan;
	system("CLS");

	if(pilihan == "1"){
		Daftar();
		system("cls");
	}else if(pilihan == "0"){
		Masuk();
		system("cls");
	}else if (pilihan == "9"){
		main();
	}else{
		cout << "tolong lihat pilihannya" << endl;
		Sleep(2000);
		system("cls");
		Menu_Masuk();
	}
}

void b(){
cout<<"d8888b. d88888b d8b   db  .d8b.  d8888b.\n";
cout<<"88  `8D 88'     888o  88 d8' `8b 88  `8D\n";
cout<<"88oooY' 88ooooo 88V8o 88 88ooo88 88oobY'\n";
cout<<"88~~~b. 88~~~~~ 88 V8o88 88~~~88 88`8b  \n";
cout<<"88   8D 88.     88  V888 88   88 88 `88.\n";
cout<<"Y8888P' Y88888P VP   V8P YP   YP 88   YD\n";
}

void s(){
cout<<".d8888.  .d8b.  db       .d8b.  db   db\n";
cout<<"88'  YP d8' `8b 88      d8' `8b 88   88\n";
cout<<"`8bo.   88ooo88 88      88ooo88 88ooo88\n";
cout<<"  `Y8b. 88~~~88 88      88~~~88 88~~~88\n";
cout<<"db   8D 88   88 88booo. 88   88 88   88\n";
cout<<"`8888Y' YP   YP Y88888P YP   YP YP   YP\n";
}

void o(){
cout<<" d888b   .d8b.  .88b  d88. d88888b    .d88b.  db    db d88888b d8888b.\n";
cout<<"88' Y8b d8' `8b 88'YbdP`88 88'       .8P  Y8. 88    88 88'     88  `8D\n";
cout<<"88      88ooo88 88  88  88 88ooooo   88    88 Y8    8P 88ooooo 88oobY'\n";
cout<<"88  ooo 88~~~88 88  88  88 88~~~~~   88    88 `8b  d8' 88~~~~~ 88`8b  \n";
cout<<"88. ~8~ 88   88 88  88  88 88.       `8b  d8'  `8bd8'  88.     88 `88.\n";
cout<<" Y888P  YP   YP YP  YP  YP Y88888P    `Y88P'     YP    Y88888P 88   YD\n";                                                                 
}

/* rekursif loading bar (5 detik) */
void balok(int a){
	char b = 219; //karakter bar
	if(a == 0){
		
	}else{
		cout << b;
		Sleep(200);
		balok(a-1);
	}
}

void t(){
	int time = 250;
		
		system("cls");
		
		cout<<"T ";
		Sleep(time);
		cout<<"E ";
		Sleep(time);
		cout<<"R ";
		Sleep(time);
		cout<<"I ";
		Sleep(time);
		cout<<"M ";
		Sleep(time);
		cout<<"A ";
		Sleep(time);
		cout<<" ";
		Sleep(time);
		cout<<"K ";
		Sleep(time);
		cout<<"A ";
		Sleep(time);
		cout<<"S ";
		Sleep(time);
		cout<<"I " ;
		Sleep(time);
		cout<<"H ";
		Sleep(time);
		cout<<endl;
	
}

void brain(){
	cout<<"########::'########:::::'###::::'####:'##::: ##:::::'######::'##::::'##::::'###::::'##:::::::'##:::::::'########:'##::: ##::'######:::'########:\n";
	cout<<"##.... ##: ##.... ##:::'## ##:::. ##:: ###:: ##::::'##... ##: ##:::: ##:::'## ##::: ##::::::: ##::::::: ##.....:: ###:: ##:'##... ##:: ##.....::\n";
	cout<<"##:::: ##: ##:::: ##::'##:. ##::: ##:: ####: ##:::: ##:::..:: ##:::: ##::'##:. ##:: ##::::::: ##::::::: ##::::::: ####: ##: ##:::..::: ##:::::::\n";
	cout<<"########:: ########::'##:::. ##:: ##:: ## ## ##:::: ##::::::: #########:'##:::. ##: ##::::::: ##::::::: ######::: ## ## ##: ##::'####: ######:::\n";
	cout<<"##.... ##: ##.. ##::: #########:: ##:: ##. ####:::: ##::::::: ##.... ##: #########: ##::::::: ##::::::: ##...:::: ##. ####: ##::: ##:: ##...::::\n";
	cout<<"##:::: ##: ##::. ##:: ##.... ##:: ##:: ##:. ###:::: ##::: ##: ##:::: ##: ##.... ##: ##::::::: ##::::::: ##::::::: ##:. ###: ##::: ##:: ##:::::::\n";
	cout<<"########:: ##:::. ##: ##:::: ##:'####: ##::. ##::::. ######:: ##:::: ##: ##:::: ##: ########: ########: ########: ##::. ##:. ######::: ########:\n";
	cout<<"........:::..:::::..::..:::::..::....::..::::..::::::......:::..:::::..::..:::::..::........::........::........::..::::..:::......::::........:\n";
}

void aturan(){
		cout<<"=====ATURAN PERMAINAN=====\n";
		cout<<"1. Loginlah terlebih dahulu\n";
		cout<<"2. Jika Anda belum mempunyai akun, lakukanlah register\n";
		cout<<"3. Pilih angka 1 jika ingin memulai permainan\n";
		cout<<"\n\n";
		cout<<"=====Cara Bermaian=====\n";
		cout<<"1. Ingatlah jumlah karakter * pada tiap scene\n";
		cout<<"2. Jawablah jumlah karakter * yang ditanyakan pada saat bermain\n";
		cout<<"3. Permaian akan berakhir jika jumlah karakter * yang ditanyakan salah\n\n";
		
		system("pause");
		system("cls");
}

