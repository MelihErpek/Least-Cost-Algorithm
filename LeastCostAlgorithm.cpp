
#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>


int ureticiSayisi;
int tuketiciSayisi;
int** array;
int** yedekArray;
int *Talep;
int *Arz;
int *YasakTalep;
int *YasakArz;
int yasakTalepSayısı= 0;
int yasakArzSayısı = 0;
int girdi;
int girdi2;
int enKucuk = 99999;
int enKucukTalep;
int enKucukArz;
int Pb = 0;
int iYasakTalep = 0;
int iYasakArz = 0;
int toplamTalep = 0;
int toplamArz = 0;
bool yazdirilsinMi = false;
std ::string maliyetDenklemi;
void yasakTalepEkle(int index)
{
	
	YasakTalep[iYasakTalep] = index;
	iYasakTalep++;
	yasakTalepSayısı++;
}
void yasakArzEkle(int index)
{
	
	YasakArz[iYasakArz] = index;
	iYasakArz++;
	yasakArzSayısı++;
}
void input()
{
	std :: cout << "Uretici Firma Sayisi Giriniz" << std :: endl;
	std :: cin >> ureticiSayisi;
	std:: cout << "Tuketici Firma Sayisi Giriniz" << std:: endl;
	std:: cin >> tuketiciSayisi;
	tuketiciSayisi++;
	ureticiSayisi++;
	Talep = new int[tuketiciSayisi];
	Arz = new int[ureticiSayisi];
	YasakTalep = new int[tuketiciSayisi];
	YasakArz = new int[ureticiSayisi];
}
void arrayOlustur()
{
	array =  new int*[ureticiSayisi];
	for (int i = 0; i < ureticiSayisi; ++i) {
		array[i] = new int[tuketiciSayisi];
	}

	yedekArray = new int*[ureticiSayisi];
	for (int i = 0; i < ureticiSayisi; ++i) {
		yedekArray[i] = new int[tuketiciSayisi];
	}

}
void maliyetleriOlustur()
{
		for (int i = 0; i < ureticiSayisi-1; i++)
		{
			for (int k = 0; k < tuketiciSayisi-1; k++)
			{
				std::cout << "Satir " << i + 1 << " "  << "Sutun " << k + 1 <<" = ";
				std::cin >> girdi;
				array[i][k] = girdi;
				yedekArray[i][k] = girdi;
			}
		}
}
void talepveArzOlustur()
{
	for (int i = 0; i < tuketiciSayisi-1; i++)
	{
		std::cout << i+1 << ". Talep =";
		std::cin >> girdi2;
		Talep[i] = girdi2;
	}
	for (int i = 0; i < ureticiSayisi-1; i++)
	{
		std::cout << i+1 << ". Arz =";
		std::cin >> girdi2;
		Arz[i] = girdi2;
	}
}
bool talepArzEsitMi()
{
	for (int i = 0; i < tuketiciSayisi; i++)
	{
		toplamTalep = toplamTalep + Talep[i];
		
	}
	for (int i = 0; i < ureticiSayisi; i++)
	{
		toplamArz = toplamArz + Arz[i];
		
	}
	if (toplamArz == toplamTalep)
	{
		ureticiSayisi--;
		tuketiciSayisi--;
		return true;
	}
	else
	{
		if (toplamArz >= toplamTalep)
		{
			
			
			Talep[tuketiciSayisi-1] = (toplamArz - toplamTalep);
			for (int i = 0; i < ureticiSayisi; i++)
			{
				array[i][tuketiciSayisi - 1] = 0;
				yedekArray[i][tuketiciSayisi - 1] = 0;
			}
			ureticiSayisi--;
		}
		else
		{
			Arz[ureticiSayisi- 1] = (toplamTalep - toplamArz);
			for (int i = 0; i < tuketiciSayisi; i++)
			{
				array[ureticiSayisi-1][i] = 0;
				yedekArray[ureticiSayisi - 1][i] = 0;
			}
			tuketiciSayisi--;
		}
	}
}
void sayiYazdır(int maliyet)
{
	if (maliyet < 10)
	{
		std::cout << maliyet << "   ";
	}
	if (maliyet >= 10 && maliyet < 100)
	{
		std::cout << maliyet << "  ";
	}
	if (maliyet >=100)
	{
		std::cout << maliyet << " ";
	}
}
void yazdır()
{
	std::cout << "   ";
	for (int i = 1; i <= tuketiciSayisi; i++)
	{
		std ::cout << i << "   " ;
	}
	std::cout<< "A" << std::endl;
	for (int i = 0; i < ureticiSayisi; i++)
	{
		std::cout << i+1 << "  "  ;
		for (int k = 0; k < tuketiciSayisi; k++)
		{
			sayiYazdır(yedekArray[i][k]);
			//std::cout << yedekArray[i][k] << " ";
		}
		std::cout << Arz[i];
		std::cout << std::endl;
	}
	std::cout << "T"<< "  ";
	for (int k = 0; k < tuketiciSayisi; k++)
	{
		sayiYazdır(Talep[k]);
		//std::cout << Talep[k] << " ";
	}
	std::cout << std::endl;
}
void enKucuguBul()
{
	enKucuk = 9999;
	for (int i = 0; i < ureticiSayisi; i++)
	{
		for (int k = 0; k < tuketiciSayisi; k++)
		{
			if (array[i][k] < enKucuk)
			{
				enKucuk = array[i][k];
				enKucukTalep = i; // 0
				enKucukArz = k; // 1
			}
		}
	}
}
bool talepKontrol()
{
	for (int i = 0; i < tuketiciSayisi; i++)
	{
		if (YasakTalep[i] == enKucukArz)
		{
			array[enKucukTalep][enKucukArz] = 9999;
			return false;
		}
	}
	
	return true;
}
bool arzKontrol()
{
	for (int i = 0; i < ureticiSayisi; i++)
	{
		if (YasakArz[i] == enKucukTalep)
		{
			array[enKucukTalep][enKucukArz] = 9999;
			return false;
		}
	}

	return true;
}
void pbHesapla()
{
	if (Arz[enKucukTalep] >= Talep[enKucukArz])
	{
		if (talepKontrol())
		{
			Arz[enKucukTalep] = Arz[enKucukTalep] - Talep[enKucukArz];
			Pb = Pb +(array[enKucukTalep][enKucukArz] * Talep[enKucukArz]);
			std::string a = std::to_string(array[enKucukTalep][enKucukArz]);
			std::string b = std::to_string(Talep[enKucukArz]);
			Talep[enKucukArz] = 0;
			yasakTalepEkle(enKucukArz);
			array[enKucukTalep][enKucukArz] = 9999;
			if (Arz[enKucukTalep] == 0)
			{
				yasakArzEkle(enKucukTalep);
			}
			
			maliyetDenklemi =maliyetDenklemi + a + "*" + b ;
			yazdirilsinMi = true;
		}	
		else
		{
			enKucuguBul();
		}
	}
	else
	{
		if (arzKontrol())
		{
			Talep[enKucukArz] = Talep[enKucukArz] - Arz[enKucukTalep];
			Pb = Pb + (array[enKucukTalep][enKucukArz] * Arz[enKucukTalep]);
			std::string a = std::to_string(array[enKucukTalep][enKucukArz]);
			std::string b = std::to_string(Arz[enKucukTalep]);
			Arz[enKucukTalep] = 0;
			yasakArzEkle(enKucukTalep);
			array[enKucukTalep][enKucukArz] = 9999;
			if (Talep[enKucukArz] == 0)
			{
				yasakTalepEkle(enKucukArz);
			}
			maliyetDenklemi = maliyetDenklemi + a + "*" + b + "+";
			yazdirilsinMi = true;
		}
		else
		{
			enKucuguBul();
		}
	}
	
	
}

bool genelDongu()
{
	
	if (yasakTalepSayısı == (tuketiciSayisi) && yasakArzSayısı == (ureticiSayisi))
	{
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	
	input();
	arrayOlustur();
	maliyetleriOlustur();
	talepveArzOlustur();
	talepArzEsitMi();
	yazdır();
	std::cin.ignore();
	while (genelDongu() == false)
	{
		
		enKucuguBul();
		pbHesapla();
		
		if (yazdirilsinMi)
		{
			std::cin.ignore();
			std::cout << "-------------------------" << std::endl;
			yazdır();
			std::cout << "Maliyet Denklemi = " << maliyetDenklemi << std::endl;
			std::cout << "Para Birimi = " << Pb << std::endl;
			maliyetDenklemi = maliyetDenklemi + "+";
		}
		
		yazdirilsinMi = false;
	}
	std::cout << "Hesaplama Tamamlanmistir.";
}




