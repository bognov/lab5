#include <iostream>
#include "stdafx.h"
#include "class.h"
#include <string>

using namespace std;


void vehicle::setspeed(int a)
{
	maxspeed = a;
}

void vehicle::setweight(int a)
{
	weight = a;
}

void vehicle::getinfo()
{
	cout << length << endl;
	cout << width << endl;
	cout << hight << endl;
	cout << maxspeed << endl;
	cout << weight << endl;
}

void vehicle::setsize(int a, int b, int c)
{
	length = a;
	width = b;
	hight = c;
}


/*===========================================================
=============================================================*/



void car::setplaces(int a)
{
	numplaces = a;
}

void car::getinfo(engine& m)
{
	cout << endl;
	cout << "lenth " << length << endl;
	cout << "width " << width << endl;
	cout << "hight " << hight << endl;
	cout << "weight " << weight << endl;
	cout << "places " << numplaces << endl;
	cout << "max speed " << maxspeed << endl;
	m.getinfo1();
	cout << endl << "===========================" << endl << endl;
}

/*===========================================================
=============================================================*/


void train::setwagons(int a)
{
	numwagons = a;
}

void train::getinfo(wagon& m)
{
	cout << endl;
	cout << "lenth " << length << endl;
	cout << "width " << width << endl;
	cout << "hight " << hight << endl;
	cout << "weight " << weight << endl;
	cout << "max speed " << maxspeed << endl;
	m.getinfo1();
	cout << endl << "===========================" << endl << endl;
}


/*==============================================================
================================================================*/


void express::setplaces(int a)
{
	numplaces = a;
}

void express::getinfo()
{
	cout << endl;
	cout << "lenth " << length << endl;
	cout << "width " << width << endl;
	cout << "hight " << hight << endl;
	cout << "weight " << weight << endl;
	cout << "places " << numplaces << endl;
	cout << "max speed " << maxspeed << endl;
	cout << endl << "===========================" << endl << endl;
}


/*====================================================================
======================================================================*/

void train::wagon::setnumber(int a)
{
	number = a;
}

void train::wagon::setplaces(int a)
{
	numplaces = a;
}

void train::wagon::getinfo1()
{
	cout << "wagon number " << number << endl; 
	cout << "number of places " << numplaces << endl;
}

/*===================================================================
=====================================================================*/

void car::engine::sethp(int a)
{
	hp = a;
}

void car::engine::setvolume(int a)
{
	volume = a;
}

void car::engine::getinfo1()
{
	cout << "hp " << hp << endl;
	cout << "volume " << volume << endl;
}

/*===================================================================
=====================================================================*/

List::~List()
{
	vehicle *r;
	while (head)
	{
		r = head;
		head = head->next;
		delete r;
	}
}

void List::Insert(vehicle *p)
{

	vehicle *r;
	r = head;
	head = p;
	p->next = r;
}

void List::Show(void)
{
	vehicle *r;
	r = head;
	while (r)
	{
		r->getinfo();
		cout << "==========================" << endl;
		r = r->next;
	}
}

/*===================================================================
=====================================================================*/

void kontroller::cost(List *a)
{
	vehicle *r;
	int k = 0;
	r = (*a).head;
	while (r)
	{
		k = k + (*r).cost;
		r = r->next;
	}
	cout << "cost of all transport = " << k;
}

void kontroller::sort(List *a)
{
	int k = 0;
	vehicle *p;
	vehicle **tmp = new vehicle*[k];
	p = a->head;
	while (p) // переносим данные из списка в массив
	{
		tmp[k] = p;
		p = p->next;
		k++;
	}

	int i, j;
	for (i = 0; i < k; i++) // сортировка массива
		for (j = i + 1; j < k-1; j++)
			if ((*tmp[i]).oil > (*tmp[j]).oil) swap(tmp[i], tmp[j]);

	for (i = 0; i < k; i++)
	{
		(*tmp[i]).name;
		cout << (*tmp[i]).oil << endl;
	}
}

void kontroller::speed(List *a, int k, int t)
{
	vehicle *r;
	r = (*a).head;
	while (r)
	{
		if (((*r).maxspeed >= k) && ((*r).maxspeed <= t))
			cout << (*r).name[0];
		r = r->next;
	}
}