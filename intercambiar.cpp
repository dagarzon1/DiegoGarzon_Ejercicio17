#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void cambia(Album A, Album B);
int minim(Album x, Album y);
class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool Esta_lleno(void);
  int Dar_sobres_comprados(void);
  int Dar_n_repetidas(void);
  bool Tengo_lamina(int lamina);
  void Agregar_lamina(int lamina);
  int* Dar_repetidas(void);
  void cambiar(void);
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  n_sobres_comprados++;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
}
bool Album::Esta_lleno(void)
{
	bool lleno=false;
	int j=0;
	for(int i=0;i<n_total;i++)
	{
	if(album[i]==1)
		{
		j++;
		}
	}
	if(j==n_total)
	{
	lleno=true;
	}
	return lleno;
}
int Album::Dar_sobres_comprados(void)
{
	return n_sobres_comprados;
}
int Album::Dar_n_repetidas(void)
{
	return n_repetidas;
}
bool Album::Tengo_lamina(int lamina)
{
	bool la_tengo=false;
	if (album[lamina]==1)
	{
	la_tengo=true;
	}
	return la_tengo;
}
void Album::Agregar_lamina(int lamina)
{
	album[lamina]=1;
}
int* Album::Dar_repetidas(void)
{
	return repetidas;
}
void Album::cambiar(void)
{
	n_repetidas--;
	n_en_album++;
}



Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados = 0;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

int main(){
  srand(time(0));
  Album A(670);
  Album B(670);
  cambia(A,B);
}
int minim(Album x, Album y)
{
  int minimo=  y.Dar_n_repetidas();
  if(x.Dar_n_repetidas()<y.Dar_n_repetidas())
	{
	  minimo= x.Dar_n_repetidas();			
	}
  return minimo;
}

void cambia(Album A, Album B)
{
int n=0;
while (!A.Esta_lleno() || !B.Esta_lleno())
  {
  A.CompraSobre(5);
  B.CompraSobre(5);
  int mn;
  mn=minim(A,B);
  for(int j=0;j<mn;j++)
{
  for(int i=0;i<670;i++)
	{
	 if(!A.Tengo_lamina(i) && B.Dar_repetidas()[i]!=0)
		{
			 for(int k=0;k<670;k++)
			{
			 if(!B.Tengo_lamina(k) && A.Dar_repetidas()[k]!=0)
				{
				 A.Agregar_lamina(B.Dar_repetidas()[i]);
				 B.Dar_repetidas()[i]--;
				 B.Agregar_lamina(A.Dar_repetidas()[k]);
				 B.Dar_repetidas()[k]--;
				 B.cambiar();
				 A.cambiar();
				}		
			}	 
		}
	 
	}
  }
n++;
}
cout<<n<<endl;
}


