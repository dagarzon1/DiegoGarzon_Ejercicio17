#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool Esta_lleno(void);
  int Dar_sobres_comprados(void);
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
  int n;
  while (!A.Esta_lleno())
  {
  A.CompraSobre(5);
  n = A.Dar_sobres_comprados();
  }
  cout<<n<<endl;
}
