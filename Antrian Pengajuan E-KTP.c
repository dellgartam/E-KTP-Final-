#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include"subroutines.h"

#define TRUE 1
#define FALSE 0

typedef struct{
            int data[100];char data1[100][20];
            char data2[100][30];char data3[100][15];
            int depan;int belakang;}
Queue;Queue antrian;Queue nokk;Queue nama;

int pilihan, data, i, j,n;
char data1[20], data2[30], data3[15];

int antrianKosong(){
    if (antrian.belakang==-1)
        return TRUE;
    else
        return FALSE;}
        
int antrianTerisi(){
    if(antrian.belakang==100)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(int data, char data1[20], char data2[30]){
    if(antrianKosong()==TRUE){
        antrian.depan=antrian.belakang=0;
        nama.depan=nama.belakang=0;
    	nokk.depan=nokk.belakang=0;
	}
    else{
    	antrian.belakang++;
        nama.belakang++;
        nokk.belakang++;    
	}
	
    antrian.data[antrian.belakang]=data;
    for(i=0;i<20;i++){
        nama.data1[nama.belakang][i]=data1[i];}
    for(i=0;i<15;i++){
		nokk.data2[nokk.belakang][i]=data2[i];}
    printf("\n\t\t\t    ======DATA TERSIMPAN===== ");   
    jadwal(data);delay(3000);
}     
		
int Dequeue(){
    if(antrianKosong()==FALSE){
        int i,e ;char a[20], b[30];
        e=antrian.data[antrian.depan];
        for(i=0;i<20;i++){
            a[i]=nama.data1[nama.depan][i];}
            
        for(i=antrian.depan;i<antrian.belakang;i++){
            antrian.data[i]=antrian.data[i+1];
            for(j=0;j<20;j++){
				nama.data1[i][j]=nama.data1[i+1][j];}
            for(j=0;j<15;j++){
				nokk.data2[i][j]=nokk.data2[i+1][j];}}
        antrian.belakang--;
        nama.belakang--;
        nokk.belakang--;
		kop();
		printf("\n\t\tAntrian %i dengan nama %s\n", e, a);
		printf("\n\t\tSilahkan masuk counter rekam data!\n\n\n");delay(3000);
        return e;
        return a[20];}
    else{
        kop();
		printf("\n\n\n\n\n\n\t\t\t  ======ANTRIAN KOSONG===== ");}
}

void buat(){
    antrian.depan=antrian.belakang=-1;
    nama.depan=nama.belakang=-1;
    nokk.depan=nokk.belakang=-1;
}
    
 
int main(){
	system("color 03");system("mode 81, 30");				//warna tulisan,warna background,ukuran layar output
	int but=1;int butmax=4;unsigned char ch;int n;int a=1;buat();
	judul();delay(4000);system("CLS");petunjuk();delay(4000);system("CLS");
	back:
	while(but!=-1){
		if(but>butmax){
			but=1;} 										//nilai but berputar dari 1 ke 4 dan kembali lagi ke 1
		else if(but<1){
			but=butmax;}							
		system("CLS");menu(but);ch=getch();
		if (ch==0){											//initial read input char dari keyboard
			ch=getch();} 
		if (ch==72){										//decrement nilai button bila ditekan panah ke atas
			but--;}
		else if (ch==80){									//increment nilai button bila ditekan panah ke bawah
			but++;}		  
		if(ch==77){											//memilih opsi bila ditekan panah kanan
			system("CLS");
		switch (but){
            case 1 :
				system("CLS");kop();
				printf("\n\t\tAntrian			: %i\n", a);data=a;
                printf("\n\t\tNama Lengkap		: "); scanf("%[^\n]",&data1);fflush(stdin);
				printf("\n\t\tNomor Kartu Keluarga	: "); scanf("%s",&data2);fflush(stdin);
                savefile(data,data1,data2);
				Enqueue(data, data1, data2);a++;break;
            case 2 :
                system("CLS");
				Dequeue();delay(1000);break;
	        case 3 :	
				system("CLS");
                if(antrianKosong()==1){
                    kop();
					printf("\n\n\n\n\n\n\t\t\t  ======ANTRIAN KOSONG===== ");delay(2000);break;}
                kop();
				puts("\nAntrian       Nomor KK      	 Nama           	Jadwal rekam id");
                for(i=antrian.depan;i<=antrian.belakang;i++){
                    printf("%i       	%s        %s  ", antrian.data[i], nokk.data2[i], nama.data1[i]);
                    n=antrian.data[i];cetak(n);}delay(2000);
                //buka data keseluruhan sumber dari file 
					int tombol=1,tombolmax=2;
					unsigned char ch;FILE *f;char s[5000];char c[1000];
					while(tombol!=-1){
						if(tombol>tombolmax){
							tombol=1;} 							//nilai but berputar dari 1 ke 2 dan kembali lagi ke 1
						else if(tombol<1){
							tombol=tombolmax;}							
							system("cls");menureadfile(tombol);ch=getch();
						if (ch==0){								//initial read input char dari keyboard
							ch=getch();} 
						if (ch==72){							//decrement nilai button bila ditekan panah atas
							tombol--;}
						else if (ch==80){						//increment nilai button bila ditekan panah bawah
							tombol++;}		  
						if(ch==77){								//memilih opsi bila ditekan panah kanan
						system("CLS");
						switch (tombol){
							case 1: kop();printf("\nAntrian\tNama\t\tNomor KK\n");
								    f=fopen("Pengajuan.txt", "r");
								    if(!f)
								    return 1;
								    while (fgets(s,1000,f)!=NULL) {
								        printf("%s", s);
								    }
								    fclose(f);delay(2000);
									break;
							case 2 : goto back;break;
							}
						}		
					}getche();break;
            case 4 :
				kop();
				printf("\n\n\n\n\n\n\n\t\t\t  ======TERIMA KASIH===== ");delay(1000);exit(0);break;}
			}
	}
getche();
return 0;
}



