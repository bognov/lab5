#include "stdafx.h"
#include <iostream>


class vehicle
{ 
protected:
	int length;
	int width;
	int hight;
	int weight;
public:
	char name[10];
	int oil;
	int maxspeed;
	int cost;
	vehicle *next;
	virtual void setsize(int, int, int);
	virtual void setspeed(int);
	virtual void setweight(int);
	void getinfo();
	friend class List;
};

class car :
	public vehicle
{
public:
	class engine
	{
	public:
		int hp;
		int volume;
		engine(int a, int b)
		{
			sethp(a);
			setvolume(b);
		};
		void sethp(int);
		void setvolume(int);
		void getinfo1();
	};
	car(int m[3], int a[2], int n, int o, char *na, int c)
	{
		setsize(m[0], m[1], m[2]);
		setspeed(a[0]);
		setweight(a[1]);
		setplaces(n);
		oil = o;
		*name = *na;
		cost = c;
	};
	int numplaces;
	void setplaces(int);
	void getinfo(engine& m);
};

class train :
	public vehicle
{
public:
	class wagon
	{
	public:
		int number;
		int numplaces;
		void setnumber(int);
		void setplaces(int);
		void getinfo1();
	};
	train(int m[3], int a[2], int n, int o, char *na, int c)
	{
		setsize(m[0], m[1], m[2]);
		setspeed(a[0]);
		setweight(a[1]);
		setwagons(n);
		oil = o;
		*name = *na;
		cost = c;
	};
	int numwagons;
	void getinfo(wagon& m);
	void setwagons(int);
};

class express :
	public vehicle
{
	int numplaces;
public:
	express(int m[3], int a[2], int n, int o, char *na, int c)
	{
		setsize(m[0], m[1], m[2]);
		setspeed(a[0]);
		setweight(a[1]);
		setplaces(n);
		oil = o;
		*name = *na;
		cost = c;
	};
	void setplaces(int);
	void getinfo();
};

class List 
{ 
public: List()
{
	head = 0; 
}  
~List();  
static void Show(void);
void Insert(vehicle *);
public:  
	static vehicle *head; 
};  

class kontroller
{
public:
	void cost(List *a);
	void sort(List *a);
	void speed(List *a, int k, int t);
};