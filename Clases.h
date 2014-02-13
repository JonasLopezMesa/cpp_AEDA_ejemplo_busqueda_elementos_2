#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//CLASE VECTOR


class vectorT
{
private:
	int * v_;
	int sz_;
public:
	vectorT();
	~vectorT();
	bool read (ifstream & is);
	void write();
	int buscar(int x);
private:
	int buscar1(int i, int d, int x);
};

vectorT::vectorT() : v_(NULL), sz_(0) {}
vectorT::~vectorT()
{
	if (v_ != NULL) {
		delete [] v_;
		v_ = NULL;
	}
	sz_ = 0;
}

bool vectorT::read(ifstream & is)
{
	cout << "read" << endl;
	cout << "-------------------------" << endl;
	if (is.eof())
		return false;
	int sz;
	is >> sz;
	if (! is.good())
		return false;
	if ( v_ != NULL) {
		delete[]v_;
		v_ = NULL;
	}
	sz_ = sz;
	cout << "Tamaño:   ";
	cout << sz_ << endl;
	v_ = new int[sz];
	for (int i = 0; i < sz_; i++) {
		is >> v_[i];
		cout << v_[i] << endl;
	}
	return true;
}
void vectorT::write(void)
{
	cout << sz_ << endl;
	for (int i = 0; i < sz_; i++) {
		cout << v_[i] << "  ";
	}
	cout << endl;
}
int vectorT::buscar(int x)
{
	return buscar1(0, sz_-1,x);
}

int vectorT::buscar1(int i, int d, int x)
{
	int centro;
	if (i <= d) {
		centro = (i + d) / 2;
		if (v_[centro] == x){
			return centro;
		}
		else {
			if (v_[centro] > x)
				return buscar1(i, centro - 1, x);
			else {
				return buscar1 (centro + 1, d, x);
			}
		}
	}
	else {
		return -1;
	}
}


	
//CLASE SLL_ITEM

class sll_item
{
private:
	sll_item* next_;
	vectorT dato_;
public:
	sll_item(const vectorT & dato);
	~sll_item();
	void write();
	void setnext(sll_item* n);
	sll_item* getnext();
	void setDato(vectorT d);
	vectorT& getDato();
	int buscar(int x);
	
};

sll_item::sll_item(const vectorT & dato) : dato_(dato), next_(NULL) {}
//destructor
sll_item::~sll_item()
{
	next_ = NULL;	
}

void sll_item::setnext(sll_item* n)
{
	next_ = n;
}

sll_item* sll_item::getnext()
{
	return next_;
}

void sll_item::setDato(vectorT d)
{
	dato_ = d;
}

vectorT& sll_item::getDato()
{
	return dato_;
}

void sll_item::write()
{
	getDato().write();
}
int sll_item::buscar(int x)
{
	return dato_.buscar(x);
}


//CLASE SLL

class sll
{
private:
	sll_item* inicio_;
public:
	sll();
	~sll();
	void read(const char* file);
	void imprimir();
	void buscar(int x);
	void insert_b(sll_item* i);
	
};

sll::sll() : inicio_(NULL) {}

sll::~sll() 
{
	sll_item* aux = NULL;
	while (inicio_ != NULL) {
		aux = inicio_;
		inicio_ = inicio_->getnext();
		delete aux;
	}
}
void sll::insert_b(sll_item* i)					//insertar por el principio
{
	i->setnext(inicio_);
	inicio_ = i;
}
void sll::read(const char* name)
{
	ifstream is(name);
	cout << name << endl;
	cout << is << endl;
	if (is.is_open()){
		bool correcto = true;
		vectorT v;
		do {
			correcto = v.read(is);
			if(correcto) {
				sll_item* nodo = new sll_item(v);
				insert_b(nodo);
			}
		} while (correcto);
	}
	else {
		cout << "ERROR0: No se ha podido abrir el archivo" << endl;
	}

	is.close();
}
			
void sll::imprimir()
{

		int i = 1;
		sll_item* aux = inicio_;
		while (aux != NULL) {
			cout << "Tamaño:   ";
			aux->write();
			aux = aux->getnext();
			
			i++;
		}
		

}
void sll::buscar(int x)
{
	cout << inicio_->buscar(x);
	cout << endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	

