// LR5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// V4

#include <iostream>
#include <string>

using namespace std;

class Shape 
{
private:
	string Name;
public:
	void SetName(string s);
	string GetName();
	virtual float area() = 0; 

	static float SumArea(Shape* F[]);

	virtual void Dx(float dx) = 0;            //перемещение
	virtual void Mult(float t) = 0;           //масштабирование
	virtual string Show() = 0;                //характеристики
	virtual string showAtr() = 0;             //атрибуты
};

void Shape::SetName(string s)
{
	Name = s;
}
string Shape::GetName()
{
	return Name;
}
float Shape::SumArea(Shape* F[])
{
	float sum = 0;
	for (int i = 0; i < sizeof(F); i++)
	{
		sum += F[i]->area();
	}
	return sum;
}


class T
{
public:
	float x = 0;
	float y = 0;
};


class Triangle : public Shape 
{
private:
	T a;
	T b;
	T c;
public:
	Triangle();
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
	float getAb();
	float getAc();
	float getBc();

	float area();
	float perimetr();
	bool tr();

	float cosA();
	float cosB();
	float cosC();
	float height();

	bool operator > (Triangle* C);
	bool operator==(Triangle* C);
	bool operator<(Triangle* C);

	void Dx(float dx);
	void Mult(float t);
	string Show();
	string showAtr();
};

Triangle::Triangle()
{
	T a, b, c;
}
Triangle:: Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	a.x = x1; a.y = y1;
	b.x = x2; b.y = y2;
	c.x = x3; c.y = y3;
}
float Triangle::getAb()
{
	return sqrt((a.x - b.x)* (a.x - b.x) + (a.y - b.y)* (a.y - b.y));
}
float Triangle::getAc()
{
	return sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
}
float Triangle::getBc()
{
	return sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
}
float Triangle::area()
{
	float a = getAb();
	float b = getBc();
	float t = cosA();
	return 0.5 * a * b * t;
}
float Triangle::perimetr()
{
	float a = getAb();
	float b = getBc();
	float c = getAc();
	return (a + b + c);
}
bool Triangle::tr()
{
	float a = getAb();
	float b = getBc();
	float c = getAc();
	if ((a + b > c) && (a + c > b) && (b + c > a)) 
		return true;
	else return false;
}
float Triangle::cosA()
{
	float a = getAb();
	float b = getBc();
	float c = getAc();
	return (b * b + c * c - a * a) / (2 * b * c);
}
float Triangle::cosB()
{
	float a = getAb();
	float b = getBc();
	float c = getAc();
	return (a * a + c * c - b * b) / (2 * a * c);
}
float Triangle::cosC()
{
	float a = getAb();
	float b = getBc();
	float c = getAc();
	return (a * a + b * b - c * c) / (2 * a * b);
}
float Triangle::height()
{
	float a = getAb();
	float b = getBc();
	float c = getAc();
	float p = perimetr() / 2;
	return (2 / a) * sqrt(p * (p - a) * (p - b) * (p - c));
}
bool Triangle::operator>(Triangle* C)
{
	return perimetr() > C->perimetr();
}
bool Triangle::operator==(Triangle* C)
{
	return perimetr() == C->perimetr();
}
bool Triangle::operator<(Triangle* C)
{
	return perimetr() < C->perimetr();
}
void Triangle::Dx(float dx)
{
	a.x += dx; a.y += dx;
	b.x += dx; b.y += dx;
	c.x += dx; c.y += dx;
}
void Triangle::Mult(float t)
{
	a.x *= t; a.y *= t;
	b.x *= t; b.y *= t;
	c.x *= t; c.y *= t;
}
string Triangle::Show()
{
	return GetName() + ", площадь = " + to_string(area()) + ", периметр = " + to_string(perimetr()) + +"\n"
		"cosA = " + to_string(cosA()) + ", cosB = " + to_string(cosB()) + ", cosC = " + to_string(cosC()) 
		+ ", высота = " + to_string(height());
}
string Triangle::showAtr()
{
	return GetName() + ",  Точка a. Координата x = " + to_string(a.x) + ", координата y = " + to_string(a.y) + "\n"
		+ "Точка b. Координата x = " + to_string(b.x) + ", координата y = " + to_string(a.y) + "\n" 
		+ "Точка c. Координата x =" + to_string(b.x) + ", координата y = " + to_string(a.y) + "\n"
		+ "Сторона ab = " + to_string(getAb()) + ", сторона ac = " + to_string(getAc()) + ", сторона bc = " + to_string(getBc());
}



class Circle : public Shape 
{
private:
	float Radius;
	T X;
public:
	Circle();
	void SetRad(float r);
	float getRad();
	void SetCenter(float x, float y);

	float area();
	float lenght();
	float diameter();
	float sectorArea(float a);

	bool operator > (Circle* C);
	bool operator==(Circle* C);
	bool operator<(Circle* C);

	void Dx(float dx);
	void Mult(float t);
	string Show();
	string showAtr();
};

Circle::Circle()
{
	Radius = 0;
}
void Circle::SetRad(float r)
{
	Radius = r;
}
float Circle::getRad()
{
	return Radius;
}
void Circle::SetCenter(float a, float b)
{
	X.x = a;
	X.y = b;
}
float Circle::area()
{
	return Radius * Radius * 3.1415;
}
float Circle::lenght()
{
	return 2 * Radius * 3.1415;
}
float Circle::diameter()
{
	return 2 * Radius;
}
float Circle::sectorArea(float a)
{
	return (3.1415 * Radius * Radius * a) / 360;
}
bool Circle::operator>(Circle* C)
{
	return lenght() > C->lenght();
}
bool Circle::operator==(Circle* C)
{
	return lenght() == C->lenght();
}
bool Circle::operator<(Circle* C)
{
	return lenght() < C->lenght();
}
void Circle::Dx(float dx)
{
	X.x += dx; X.y += dx;
}
void Circle::Mult(float t)
{
	Radius *= t;
}
string Circle::Show()
{
	return GetName() + ", радиус = " + to_string(Radius) + ", диаметр = " + to_string(diameter()) 
		+ ", площадь = " + to_string(area()) + ", длина окружности = " + to_string(lenght());
}
string Circle::showAtr()
{
	return GetName() + ", координаты радиуса: x = " + to_string(X.x) + ", y = " + to_string(X.y) + "; радиус = " + to_string(Radius);
}



int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle* Tr = new Triangle(1, 5, 8, 15, 12, 3);
	Circle* C = new Circle;
	Shape* F[5]; 

	Tr->SetName("Треугольник 1");/*
	cout << Tr->GetName() << endl;
	cout << "Сторона ab: " << Tr->getAb() << endl;
	cout << "Сторона ac: " << Tr->getAc() << endl;
	cout << "Сторона bc: " << Tr->getBc() << endl;
	if (Tr->tr())
		cout << "Треугольник невырожденный" << endl;
	else cout << "Треугольник вырожденный" << endl;
	cout << "Периметр: " << Tr->perimetr() << endl;
	cout << "Площадь: " << Tr->area() << endl;
	cout << "Высота: " << Tr->height() << endl;
	cout << "Косинус А: " << Tr->cosA() << endl;
	cout << "Косинус B: " << Tr->cosB() << endl;
	cout << "Косинус C: " << Tr->cosC() << endl;
	cout << endl;*/


	C->SetName("Окружность 1"); 
	C->SetRad(5);/*
	cout << C->GetName() << endl;
	cout << "Радиус: " << C->getRad() << endl;
	cout << "Площадь: " << C->area() << endl;
	cout << "Диаметр: " << C->diameter() << endl;
	cout << "Длина окружность: " << C->lenght() << endl;
	cout << "Введите угол для вычисления площади сектора: ";
	float n;
	cin >> n;
	cout << "Площадь сектора с центальным углом " << n << " : " << C->sectorArea(n) << endl;
	cout << endl;*/

	Triangle* Tr1 = new Triangle(-0.1, -2.4, 3.1, 2.7, 1.8, 3.9);
	Tr1->SetName("Треугольник 2");
	Circle* C1 = new Circle;
	C1->SetRad(7.5);
	C1->SetCenter(3.5, 6.7);
	C1->SetName("Окружность 2");
	Circle* C2 = new Circle;
	C2->SetRad(3.8);
	C2->SetName("Окружность 3");

	F[0] = Tr;
	F[1] = C;
	F[2] = Tr1;
	F[3] = C1;
	F[4] = C2;

	cout << "Массив объектов типа Shape: " << endl << endl;
	for (int i = 0; i < 5; i++)
		cout << F[i]->Show() << endl << endl;
	cout << endl << endl << endl;


	if (Tr->operator<(Tr1))
		cout << Tr->GetName() << ", периметр "  << Tr->perimetr() << " < " << Tr1->GetName() << ", периметр " << Tr1->perimetr() << endl;
	if(Tr->operator>(Tr1))
		cout << Tr->GetName() << ", периметр " << Tr->perimetr() << " > " << Tr1->GetName() << ", периметр " << Tr1->perimetr() << endl;
	else if(Tr->operator==(Tr1))
		cout << Tr->GetName() << ", периметр " << Tr->perimetr() << " = " << Tr1->GetName() << ", периметр " << Tr1->perimetr() << endl;

	if (C->operator<(C1))    
		cout << C->GetName() << ", длина окружности " << C->lenght() << " < " << C1->GetName() << ", длина окружности " << C1->lenght() << endl;
	if (C->operator>(C1))
		cout << C->GetName() << ", длина окружности " << C->lenght() << " > " << C1->GetName() << ", длина окружности " << C1->lenght() << endl;
	else if (C->operator==(C1))
		cout << C->GetName() << ", длина окружности " << C->lenght() << " = " << C1->GetName() << ", длина окружности " << C1->lenght() << endl;
	cout << endl << endl << endl;

	
	cout << "Сумма площадей массива фигур = ";
	for (int i = 0; i < 1; i++)
		cout << F[i]->SumArea(F) << endl;
	cout << endl << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << F[i]->showAtr() << endl << endl;
	}

	cout << "Перемещение фигур (смещение координат на 4 единицы): " << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		F[i]->Dx(4.0);
		cout << F[i]->showAtr() << endl << endl;
	}
	cout << endl << endl << endl;

	cout << "Масштабирование фигур (увеличение сторон в 2 раза):" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		F[i]->Mult(2.0);
		cout << F[i]->showAtr() << endl << endl;
	}
	cout << endl << endl << endl;

	cout << "Введите угол для вычисления площади сектора: ";
	float n;
	cin >> n;
	cout << "Площадь сектора " << C->GetName() << " с центальным углом " << n << " : " << C->sectorArea(n) << endl << endl << endl;
}
