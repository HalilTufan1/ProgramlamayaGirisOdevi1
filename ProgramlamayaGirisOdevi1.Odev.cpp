/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1
**				ÖĞRENCİ ADI...............:Halil Tufan
**				ÖĞRENCİ NUMARASI.:g211210027
**				DERS GRUBU…………:2.öğretim A grubu
****************************************************************************/

//Kulanılacak olan kodların kütüphanelerinin tanımlanması
#include <iostream>
#include <locale.h>
#include <string>
#include <cctype>

using namespace std;

//Şehir isimlerinin baş harflerinin büyük olması sebebiyle çıkan hatadan dolayı büyük harflerin küçültülmesini sağlayan fonksiyon
string ToLower(string cumle)
{
	string lower = "";

	for (int indis = 0; indis < cumle.length(); indis++)
	{
		lower += tolower(cumle[indis]);
	}

	return lower;
}

//Türkçe karakterde girilen şehir isimlerinin karakterlerini İngilizce harf karakterlerine dönüşmesini sağlayan fonksiyon
string TRtoEN(string TRform)
{
	char turkishChars[] = { 'ı', 'ğ', 'İ', 'Ğ', 'ç', 'Ç', 'ş', 'Ş', 'ö', 'Ö', 'ü', 'Ü' };
	char englishChars[] = { 'i', 'g', 'I', 'G', 'c', 'C', 's', 'S', 'o', 'O', 'u', 'U' };

	int length_turkishChars = 12;

	string ENform = "";

	for (int indisTR = 0; indisTR < TRform.length(); indisTR++)
	{
		bool isEnglishChar = true;

		for (int indisChar = 0; indisChar < length_turkishChars; indisChar++)
		{
			if (TRform[indisTR] == turkishChars[indisChar])
			{
				ENform += englishChars[indisChar];
				isEnglishChar = false;
			}
		}

		if (isEnglishChar)
		{
			ENform += TRform[indisTR];
		}
	}

	return ENform;
}


int main()

{
	
	srand(time(NULL));

	setlocale(LC_ALL, "Turkish");


	string gec = "";

	string ilRandom[81];

	int indis[14] = { 0 };

	string iller[81] = { "İstanbul","Ankara","İzmir","Adana","Adıyaman","Afyonkarahisar","Ağrı","Aksaray","Amasya",

		"Antalya","Ardahan","Artvin","Aydın","Balıkesir","Bartın","Batman","Bayburt","Bilecik","Bingöl","Bitlis","Bolu",

		"Burdur","Bursa","Çanakkale","Çankırı","Çorum","Denizli","Diyarbakır","Düzce",

		"Edirne","Elazığ","Erzincan","Erzurum","Eskişehir","Gaziantep","Giresun","Gümüşhane","Hakkari","Hatay","Iğdır","Isparta","Kahramanmaraş",

		"Karabük","Karaman","Kars","Kastamonu","Kayseri","Kırıkkale","Kırklareli","Kırşehir","Kilis","Kocaeli","Konya","Kütahya","Malatya","Manisa",

		"Mardin","Mersin","Muğla","Muş","Nevşehir","Niğde","Ordu","Osmaniye","Rize","Sakarya","Samsun","Siirt","Sinop","Sivas","Şırnak","Tekirdağ","Tokat"

		,"Trabzon","Tunceli","Şanlıurfa","Uşak","Van","Yalova","Yozgat","Zonguldak" };

	int min = iller[0].length();

	//1. ilden 81.ile kadar tüm iller döngüye giriyor
	for (int i = 0; i < 81; i++)

	{

		//ilk tanımlanan ilin harf sayısı bir sonraki ilden büyükse küçük harf sayılı il min olarak tanımlanıyor
		if (min > iller[i].size())

			min = iller[i].size();

	}

	int max = iller[0].size();

	//1. ilden 81.ile kadar tüm iller döngüye giriyor
	for (int i = 0; i < 81; i++)

	{
		//ilk tanımlanan ilin harf sayısı bir sonraki ilden küçükse büyük harf sayılı il max olarak tanımlanıyor
		if (max < iller[i].size())

			max = iller[i].size();

	}

	cout << " min :" << min << endl;

	cout << " mak :" << max << endl;


	// Min ve Max degerleri arasi kadar doner
	for (int i = min; i < max; i++)

	{

		int control_dis = 0;

		cout << i << ",";
		

		// 100.000 deneme yapılacak, i kadar il arasindan indisleri esleşenler ile iller arasinda eşleşen bulmak için.
		if(i<6)
		
			//1'den 100000'e kadar indisler deneniyor
			for (int j = 0; j < 100000; j++)
			

		{

			int control_ic = 0;

			//Rastgele il secer
			for (int s = 0; s < i; s++)

			{
				int randomIndis = rand() % 81;

				ilRandom[s] = iller[randomIndis];

				//cout << ilRandom[s] << endl;

			}

			int ming = ilRandom[0].length();

			// En kucuk boyutlu ilin boyutunu bulur
			for (int k = 0; k < i; k++)

			{

				if (ming > ilRandom[k].length())

					ming = ilRandom[k].length();

			}

			// Bulunan boyut kadar doner ve her ilin indislerini kontrol eder
			for (int k = 0; k < ming; k++)

			{

				gec = "";

				// Illerin indislere karsilik gelen karakterleri toplar
				for (int t = 0; t < i; t++)

					gec = gec + ilRandom[t].at(k);

			

				// Cıkan sonuc ile illeri karsilastirir
				for (int x = 0; x < 81; x++)

				{
					string fixedIl = ToLower(TRtoEN(iller[x]));

					string fixedGec = ToLower(TRtoEN(gec));


					//bulunan ili başa yazdırır
					if (fixedIl == fixedGec)

					{

						cout << fixedGec << "..: ";

						for (int grup = 0; grup < i; grup++)
						{

							cout << ilRandom[grup] << ", ";

						}
						cout << endl;

						control_ic = control_dis = 1;

					}

				}

			}

			//il bulunursa döngüyü sonlandırır
			if (control_ic == 1)

				break;

		}
		//6 indislileri bulmasını uzun sürmesinden kaynaklı döngüyü azaltmaya yönelik
		if(i>=6)

		for (int j = 0; j < 50000; j++)


		{

			int control_ic = 0;

			//Rastgele il secer
			for (int s = 0; s < i; s++)

			{
				int randomIndis = rand() % 81;

				ilRandom[s] = iller[randomIndis];

				//cout << ilRandom[s] << endl;

			}

			int ming = ilRandom[0].length();

			// En kucuk boyutlu ilin boyutunu bulur
			for (int k = 0; k < i; k++)

			{

				if (ming > ilRandom[k].length())

					ming = ilRandom[k].length();

			}

			// Bulunan boyut kadar doner ve her ilin indislerini kontrol eder
			for (int k = 0; k < ming; k++)

			{

				gec = "";

				// Illerin indislere karsilik gelen karakterleri toplar
				for (int t = 0; t < i; t++)

					gec = gec + ilRandom[t].at(k);

				// Console a yazar
				//cout << gec << endl;

				// Cıkan sonuc ile illeri karsilastirir
				for (int x = 0; x < 81; x++)

				{
					string fixedIl = ToLower(TRtoEN(iller[x]));

					string fixedGec = ToLower(TRtoEN(gec));

					if (fixedIl == fixedGec)

					{

						cout << fixedGec << "..: ";

						for (int grup = 0; grup < i; grup++)
						{
							
							cout << ilRandom[grup] << ", ";
						}
						cout << endl;

						control_ic = control_dis = 1;

					}

				}

			}

			if (control_ic == 1)

				break;

		}

		//random seçilen ilin indisleri bulunamazsa bulunamadı yazdırılmasını sağlar
		if (control_dis == 0)

			cout << "bulunamadı" << endl;

	}



}
