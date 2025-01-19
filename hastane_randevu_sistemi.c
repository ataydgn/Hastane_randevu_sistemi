//
//  main.c
//  Hastane_randev_sistemi
//
//  Created by Ata yavuz Aydoğan on 15.01.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Doktor{
    char Doktor_adi[20];
    char Doktor_soyadi[20];
    char Doktor_bolum[20];
};

struct Randevu{
    char tarih[20];
    char doktor_adi[20];
    char doktor_soyadi[20];
    char doktor_bolumu[20];
    int Tc;
};

struct Hasta{
    int Tc;
    char ad[20];
    int yas;
    char parola[30];
};

struct Hasta girisYapanKullanici;

int found = 0;

void Randevu_Al(int doktor_sayisi,struct Doktor doktorlar[]){
    FILE *dosya;
    struct Randevu randevu;

        printf("\nRandevu almak istediğiniz tarihi giriniz GG/AA/YYYY : ");
        scanf("%19s",randevu.tarih);
        printf("\nRandevu almak istediğiniz Doktoru seçiniz : ");
        scanf("%19s",randevu.doktor_adi);
        printf("\nDoktorun soyadını giriniz : ");
        scanf("%19s",randevu.doktor_soyadi);
        printf("\nDoktorun Bölümünü seçiniz : ");
        scanf("%19s",randevu.doktor_bolumu);
        
        
        randevu.Tc = girisYapanKullanici.Tc;
    
    
    dosya = fopen("/Users/atayavuzaydogan/Desktop/randevular.txt", "a");
    if (dosya == NULL) {
        perror("Dosya açılamadı");
        return;
    }
    
    fprintf(dosya, "%d %s %s %s %s\n", randevu.Tc, randevu.doktor_adi,randevu.doktor_soyadi, randevu.doktor_bolumu, randevu.tarih);
    fclose(dosya);
    
    printf("\nRandevunuz başarıyla alındı!\n");
}
    

void Randevu_listele(void){
    if (girisYapanKullanici.Tc == 0) {
         printf("Lütfen önce giriş yapın.\n");
         return;
     }

     FILE *dosya;
     struct Randevu randevu;
     int randevuBulundu = 0;

     dosya = fopen("/Users/atayavuzaydogan/Desktop/randevular.txt", "r");
     if (dosya == NULL) {
         perror("Dosya açılamadı");
         return;
     }

     printf("\n%s adlı kullanıcının randevuları:\n", girisYapanKullanici.ad);
     printf("-------------------------------------------------\n");

    while (fscanf(dosya, "%d %s %s %s %s", &randevu.Tc, randevu.doktor_adi,randevu.doktor_soyadi, randevu.doktor_bolumu, randevu.tarih) != EOF) {
         if (randevu.Tc == girisYapanKullanici.Tc) {
             printf("Doktor: %s %s\n", randevu.doktor_adi,randevu.doktor_soyadi);
             printf("Bölüm: %s\n", randevu.doktor_bolumu);
             printf("Tarih: %s\n", randevu.tarih);
             printf("-------------------------------\n");
             randevuBulundu = 1;
         }
     }

     if (!randevuBulundu) {
         printf("Henüz almış olduğunuz randevunuz yok.\n");
     }

     fclose(dosya);
 }


void Doktor_goruntule(int doktor_sayisi, struct Doktor doktorlar[]){
    printf("\nMevcut Doktorlar :\n");
    
    for (int i = 0; i < doktor_sayisi; i++) {
        printf("Doktorun adı: %s %s\n ",doktorlar[i].Doktor_adi,doktorlar[i].Doktor_soyadi);
        printf("Doktorun Bölümü : %s\n",doktorlar[i].Doktor_bolum);
        printf("------------------\n");
    }
}

void Giris_Kontrol(void){
    struct Hasta girisKullanici ;
    struct Hasta mevcutKullanici;
    FILE *dosya;
    
    printf("Giriş yapınız:");
    printf("\nTc kimliğinizi giriniz : ");
    scanf("%d",&girisKullanici.Tc);
    printf("\nAdinizi giriniz : ");
    scanf("%19s",girisKullanici.ad);
    printf("\nYasinizi giriniz : ");
    scanf("%d",&girisKullanici.yas);
    printf("\nParolanızı giriniz : ");
    scanf("%29s",girisKullanici.parola);
    
    dosya = fopen("/Users/atayavuzaydogan/Desktop/kullanicilar.txt", "r");
    
    if (dosya == NULL) {
        perror("Dosya açılamadı");
    }
    
  
    
    while (fscanf(dosya," %d %s %d %s",&mevcutKullanici.Tc,mevcutKullanici.ad,&mevcutKullanici.yas, mevcutKullanici.parola) != EOF){
        if(mevcutKullanici.Tc == girisKullanici.Tc && strcmp(girisKullanici.ad, mevcutKullanici.ad) == 0 && mevcutKullanici.yas == girisKullanici.yas && strcmp(mevcutKullanici.parola,girisKullanici.parola) == 0){
            printf("Giriş Başarılı !\n");
            girisYapanKullanici = mevcutKullanici;
            found = 1;
            break;
            
        }
    }
    if (!found) {
        printf("Kullanıcı bilgileri hatalı. Lütfen tekrar deneyin veya kayıt olunuz.\n");
    }

    fclose(dosya);
}

void Kayıt_olustur(void){
    struct Hasta yeniKullanici;
    FILE *dosya;
    
    printf("\nTC kimliginizi giriniz : ");
    scanf("%d",&yeniKullanici.Tc);
    printf("\nAdinizi giriniz : ");
    scanf("%19s",yeniKullanici.ad);
    printf("\nYasinizi giriniz : ");
    scanf("%d",&yeniKullanici.yas);
    printf("\nParolanızı giriniz :");
    scanf("%29s",yeniKullanici.parola);
    
    dosya = fopen("/Users/atayavuzaydogan/Desktop/kullanicilar.txt", "a");
    if (dosya == NULL) {
        perror("Dosya açılamadı\n");
        return;
    }
    fprintf(dosya, "%d %s %d %s\n", yeniKullanici.Tc,yeniKullanici.ad,yeniKullanici.yas,yeniKullanici.parola);
        fclose(dosya);

        printf("Kayıt başarılı!\n");
    
}

void Hastane_giris(void){
    
    struct Doktor doktorlar[3] = {
        {"Ahmet", "Yılmaz", "Cerrahi"},
        {"Mehmet", "Kara", "Kardiyoloji"},
        {"Elif", "Celik", "Ortopedi"}
    };
    
    int secim;
    int doktor_sayisi = 3;
    
    while (1) {
        if (found == 0) {
            printf("Hastane Randevu Sistemi\n");
            printf("-------------------------\n");
            printf("1. Kayıt oluştur\n");
            printf("2. Giriş yap\n");
            printf("3. Çıkış \n");
            printf("Secimizi yapiniz : ");
            scanf("%d",&secim);
            printf("\n--------------------------\n");
            switch (secim) {
                case 1:
                    Kayıt_olustur();
                    break;
                    
                case 2:
                    Giris_Kontrol();
                    break;
                case 3:
                    printf("Çıkılıyor...\n");
                    return;
                default:
                    printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
                    break;
                    
            }
        }
        else {
            printf("Hastane Randevu Sistemi\n");
            printf("-------------------------\n");
            printf("1. Randevu al\n");
            printf("2. Doktorları Görüntüle\n");
            printf("3. Randevuları Listele\n");
            printf("4. Çıkış \n");
            printf("Secimizi yapiniz : ");
            scanf("%d",&secim);
            printf("\n--------------------------\n");

            switch (secim) {
                case 1:
                    Randevu_Al(doktor_sayisi,doktorlar);
                    break;
                case 2:
                    Doktor_goruntule(doktor_sayisi,doktorlar);
                    break;
                case 3:
                    Randevu_listele();
                    break;
                case 4:
                    printf("Çıkılıyor...\n");
                    return;
                default:
                    printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
                    break;
                    
            }
        }
    }
}

int main(void) {
    Hastane_giris();
    return 0;
}
