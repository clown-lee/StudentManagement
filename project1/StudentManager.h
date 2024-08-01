#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct _Stu
{
	int ID;
	char name[20];
	int score;
}Stu;


typedef struct _node
{
	Stu stu;
	struct _node* next;
}node;

void welcome();
void pushNode(node* head);
void printInfo(node* head);
void countNum(node* head);
void findStu(node* head);
void saveFiles(node* head);
void loadFiles(node* head);
void modifyStudent(node* head);
void deleteStudent(node* head);
void sortByScore(node* head);
void clearData(node* head);
void sortByID(node* head);