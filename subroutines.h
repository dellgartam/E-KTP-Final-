#include<stdio.h>

void menu(int tom){
	int i=0,j=0,a;
	char arah[6]={' ',' ',' ',' ',' ',' '};
	arah[tom]='>';
		printf("\n\t\t==============================================");
		printf("\n\t\t\tPROGRAM ANTRIAN PENGAJUAN E-KTP");
		printf("\n\t\t==============================================");
		printf("\n\t\t%c%c 1. Pengajuan pembuatan E-KTP",arah[1],arah[1]);
		printf("\n\t\t%c%c 2. Panggilan pengajuan pembuatan E-KTP",arah[2],arah[2]);
		printf("\n\t\t%c%c 3. Daftar antrian pengajuan E-KTP",arah[3],arah[3]);
		printf("\n\t\t%c%c 4. Keluar",arah[4],arah[4]);
}

void judul(){
    printf("\n\t\t==============================================");
	printf("\n\t\t\tPROGRAM ANTRIAN PENGAJUAN E-KTP");
	printf("\n\t\t==============================================");
	printf("\n\n\n\t\t\t\t     Oleh :");
	printf("\n\n\t\t\t   Fadhel P Gartam - 1606951254");
	printf("\n\t\t\t   Michael S Bonardo - 1506672666");
	}
	
void petunjuk()
{	printf("\n\t\t==============================================");
	printf("\n\t\t\tPROGRAM ANTRIAN PENGAJUAN E-KTP");
	printf("\n\t\t==============================================");
	printf("\n\t\t______________________________________________");
	printf("\n\t\t\t  PETUNJUK PENGGUNAAN PROGRAM");
	printf("\n\t\t______________________________________________");
	printf("\n\n\t\tGunakan panah arah atas dan bawah pada keyboard\n\n\t\tuntuk memilih menu.");
	printf("\n\n\t\tTekan panah arah kanan pada keyboard untuk memilih\n\n\t\tmenu.");
	printf("\n\n\t\tTekan panah arah kiri pada keyboard untuk kembali.\n");
	printf("\n\t\t______________________________________________");
	}
void kop(){
	printf("\n\t\t==============================================");
	printf("\n\t\t\tPROGRAM ANTRIAN PENGAJUAN E-KTP");
	printf("\n\t\t==============================================\n");
}

void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int jadwal(int n){
#include<stdio.h>

int x;int menit=0;int jam=9;int day=1;int tanggal=1;int minggu=1;int bulan=1; int tahun=2018;//nilai awal tanggal dan bulan perekaman data diri
void hari(int x);void month(int x);
	
	for( x=1;x<n;x++){
		menit=menit+20;
		if(menit>=60){
			jam=jam+1;menit=0;}
		
		if(jam>=15){
			day=day+1;tanggal=tanggal+1;jam=9;}
		
		if (day>5){
			minggu=minggu+1;day=1;}
			
		if (tanggal>=31){
			bulan=bulan+1;tanggal=1;}
			
		if (bulan==2){
			if (tanggal>=28){
			bulan=bulan+1;tanggal=1;}}//bukan tahun kabisat
	
		if (bulan>=12){
			tahun=tahun+1;bulan=1;}
	}
	printf("\n\t\t==============================================");
	printf("\n\t\tJadwal rekam identitas diri anda,\n");
	printf("\n\t\tHari,Tanggal	: ");
	hari(day);printf(" %d ",tanggal);month(bulan);printf(" %d\n",tahun);
	printf("\n\t\tWaktu 		: Pukul %d.%d WIB\n",jam,menit);
}


void hari(int x){
	switch(x){
	case 1:	printf("Senin,");break;
	case 2:	printf("Selasa,");break;
	case 3:	printf("Rabu,");break;
	case 4:	printf("Kamis,");break;
	case 5: printf("Jumat,");break;}	
}

void month(int x){
	switch(x){
	case 1:	printf(" Januari");break;
	case 2:	printf(" Februari");break;
	case 3:	printf(" Maret");break;
	case 4:	printf(" April");break;
	case 5: printf(" Mei");break;
	case 6:	printf(" Juni");break;
	case 7:	printf(" Juli");break;
	case 8: printf(" Agustus");break;
	case 9:	printf(" September");break;
	case 10:printf(" Oktober");break;
	case 11:printf(" November");break;
	case 12:printf(" Desember");break;}
}

void cetak(n){
int x;int menit=0;int jam=9;int day=1;int tanggal=1;int minggu=1;int bulan=1; int tahun=2018;//nilai awal tanggal dan bulan perekaman data diri

	for( x=1;x<n;x++){
		menit=menit+20;
		if(menit>=60){
			jam=jam+1;menit=0;}
		
		if(jam>=15){
			day=day+1;tanggal=tanggal+1;jam=9;}
		
		if (day>5){
			minggu=minggu+1;day=1;}
			
		if (tanggal>=31){
			bulan=bulan+1;tanggal=1;}
			
		if (bulan==2){
			if (tanggal>=28){
			bulan=bulan+1;tanggal=1;}}//bukan tahun kabisat
	
		if (bulan>=12){
			tahun=tahun+1;bulan=1;}}
	hari(day);printf(" %d ",tanggal);month(bulan);printf(" %d",tahun);printf(" Pukul %d.%d WIB\n",jam,menit);
}

void savefile(int antrian,char nama[20],char nokk[30]){
	FILE *out=fopen("Pengajuan.txt","a");
	fprintf(out,"\n%d\t\t%s\t%s\n",antrian,nama,nokk);
	fclose(out);
	}
	
void menureadfile(int pilihan){
	char arah1[3]={' ',' ',' '};
	arah1[pilihan]='>';
	kop();
	printf("\n\t\tLihat keseluruhan data pendaftar?");
	printf("\n\t\t%c%c 1. Buka",arah1[1],arah1[1]);
	printf("\n\t\t%c%c 2. Kembali",arah1[2],arah1[2]);
}

	

