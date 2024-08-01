#include"StudentManager.h"
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<fstream>

using namespace std;
int main()
{
	node* head = (node *)malloc(sizeof(node));
	head->next = NULL;
	
	loadFiles(head);
	//printInfo(head);
	//system("pause");
	//system("cls");


	//pushNode(head);
	//pushNode(head);
	//pushNode(head);

	//////savefiles test
	//char  a[] = { "tom" };
	//node* node1 = (node*)malloc(sizeof(node));
	//
	//node1->stu.ID = 1; 
	//strcpy_s( node1->stu.name, a);
	//node1->stu.score = 21;
	//head->next = node1;
	//


	//char  b[] = { "jek" };
	//node* node2 = (node*)malloc(sizeof(node));
	//
	//node2->stu.ID = 2;
	//strcpy_s(node2->stu.name, b); 
	//node2->stu.score = 221;
	//

	//char  c[] = { "bod" };
	//node* node3 = (node*)malloc(sizeof(node));
	//
	//node3->stu.ID = 3;
	//strcpy_s(node3->stu.name, c);	 
	//node3->stu.score = 22;

	//char  d[] = { "dys" };
	//node* node4 = (node*)malloc(sizeof(node));

	//node4->stu.ID = 4;
	//strcpy_s(node4->stu.name, d);
	//node4->stu.score = 22;



	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = NULL;
	//

	//FILE* file;
	//errno_t err= fopen_s(&file, "./stu.info", "a");
	//node* move = head->next;
	//while (move != NULL) {
	//	if (fwrite(&move->stu, sizeof(Stu), 1, file) != 1) {
	//		printf("Error when saving %s", move->stu.name);
	//	}
	//	move = move->next;
	//}
	//fclose(file);
	//


	//FILE* file1;
	//errno_t err1= fopen_s(&file1, "./stu.info", "r+");
	//
	//move = head;
	//node* fresh = (node*)malloc(sizeof(node));
	//fresh->next = NULL;
	//while (fread(&fresh->stu, sizeof(Stu), 1, file1) != 1) {
	//	move->next = fresh;
	//	fresh = (node*)malloc(sizeof(node));
	////	fresh->next = NULL;

	//}
	//free(fresh);
	//fclose(file1);
	//cout << "Read Successfully!" << endl;
	//system("pause");
	//system("cls");




	//printInfo(head);
	//system("pause");
	//system("cls");


	//saveFiles(head);

	//loadFiles(head);

	//printInfo(head);
	//system("pause");
	//system("cls");




	while (1)
	{
		welcome();
		char c = _getch();


		switch (c)
		{
		case '1'://录入学生信息
			pushNode(head);
			
			break;
		case '2':  //打印学生信息
			printInfo(head);
			break;
		case '3':  //统计学生人数
			countNum(head);
			break;
		case '4':  //查找学生信息
			findStu(head);
			break;
		case '5':  //修改学生信息
			modifyStudent(head);
			break;
		case '6':  //删除学生信息
			deleteStudent(head);
			break;
		case '7':  //按成绩排序
			sortByScore(head);
			break;
		case '8':  //退出系统
			system("cls");
			exit(0);
			break;
		case '9':  //清空
			clearData(head);
			break;
		case '10':  //按编号排序
			sortByID(head);
			break;
		default:
			break;
		}
		
		system("pause");
		system("cls");
	}
	

	return 0;	
}

void welcome() {
	printf("*****************************************\n"); 
	printf("*\tStudent Management System\t*\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("*\t\t 请选择功能列表\t\t*\n");
	printf("*****************************************\n");
		printf("*\t\t1.录入学生信息\t\t*\n");
		printf("*\t\t2.打印学生信息\t\t*\n");
		printf("*\t\t3.统计学生人数\t\t*\n");
		printf("*\t\t4.查找学生信息\t\t*\n");
		printf("*\t\t5.修改学生信息\t\t*\n");
		printf("*\t\t6.删除学生信息\t\t*\n");
		printf("*\t\t7.按成绩排序\t\t*\n");
		printf("*\t\t8.退出系统\t\t*\n");
		printf("*\t\t9.清空数据\t\t*\n");
		printf("*\t\t10.按编号排序\t\t*\n");
		printf("*****************************************\n");
}
void pushNode(node* head) {
	node* move = head;
	while (move->next != NULL)
	{
		move = move->next;
	}

	node* newnode = (node *) malloc(sizeof(node));
	newnode->next = NULL;


	cout << "Enter Student ID " << endl;
	int id=0;
	cin >> id;
	node* tmp=head;
	while (tmp != NULL) {
		if (tmp->stu.ID == id) {
			cout << "Number is duplicated" << endl;
			return;
		}
		tmp = tmp->next;
	}
	free(tmp);
	newnode->stu.ID=id;

	cout << "Enter Student Name " << endl;
	cin >> newnode->stu.name;

	cout << "Enter Student Score " << endl;
	cin >> newnode->stu.score;

	move->next = newnode;
	saveFiles(head);
}

void printInfo(node* head) {
	node* move = head->next;
	while (move!= NULL) {
		printf("ID:%d\nName:%s\nScore:%d\n", move->stu.ID, move->stu.name, move->stu.score);
		move = move->next;
	}
}

void countNum(node* head) {
	node* move = head->next;
	int num=0;
	while (move != NULL) {
		num++;
		move = move->next;
	}
	if (num == 1) {
		printf("There is 1 student");
	}
	else if(num == 0){
		cout << "There is no student in list" << endl;
	}
	else {
		printf("There are %d students", num);
	}	
}

void findStu(node* head) {
	printf("The ID number of student you want to find: \n");
	int c;
	scanf_s("%d",&c);
	node* move = head->next;
	
		while (move != NULL) {
			if (c == move->stu.ID) {
				printf("ID:%d\nName:%s\nScore:%d\n", move->stu.ID, move->stu.name, move->stu.score);		
				return;
			}
			move = move->next;
		}
		printf("Couldnt Find!");
		system("pause");
		system("cls");
}

void saveFiles(node* head) {
	errno_t err;
	FILE* file;
	err = fopen_s(&file,"./stu.info", "w");
	if (file == NULL) {
		printf("unable to open file\n");
		return;
	}
	node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->stu, sizeof(Stu), 1, file) != 1) {
			printf("Error when saving %s", move->stu.name);
		}
		move = move->next;
	}
	fclose(file);
}

void loadFiles(node* head) {
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "./stu.info", "r");
	if (!file) {
		printf("Unable to read file");
		return;
	}	
	node* move = head;
	node* fresh= (node *)malloc(sizeof( node));
	fresh->next = NULL;
	rewind(file);
	while (fread(&fresh->stu, sizeof(Stu), 1, file) == 1) {//读取到数据后指针自动后移一位
		move->next = fresh;
		move = fresh;
		fresh = (node *)malloc(sizeof(node));// free space to contain next data
		fresh->next = NULL;
	}
	free(fresh);
	fclose(file);
	cout << "Read Successfully!" << endl;
	system("pause");
	system("cls");
}

void modifyStudent(node* head) {
	cout << "ID of the student you want to modify" << endl;
	int num=0;
	cin >> num;
	node* move = head;
	while (move!=NULL) {
		if (move->stu.ID == num) {
			cout << "Enter Student name" << endl<<"Enter Student score"<<endl;
			cin >> move->stu.name >> move->stu.score;
			cout << "Modified" << endl;
			break;
		}
		move = move->next;
	}
	if (move == NULL) {
		cout << "Couldnt Find" << endl;
	}
	saveFiles(head);
	system("pause");
	system("cls");
}

void deleteStudent(node* head) {
	cout << "ID of the student you want to modify" << endl;
	int num = 0;
	cin >> num;
	node* move = head;
	while (move->next != NULL) {
		if (move->next->stu.ID == num) {
			node* tmp=move->next;
			move->next = tmp->next;
			free(tmp);
			cout << "Deleted" << endl;
			break;
		}
		move = move->next;
	}
	if (move == NULL) {
		cout << "Couldnt Find" << endl;
	}
	saveFiles(head);
	system("pause");
	system("cls");
}

void sortByScore(node* head) {
	node* move = NULL;
	node* save = NULL;
	
	
	node* round = head->next;
	while (round != NULL) {
		move = head->next;
		while (move->next != save) {
			if (move->stu.score > move->next->stu.score) {
				Stu tmp = move->stu;
				move->stu = move->next->stu;
				move->next->stu = tmp;
			}
			move = move->next;
		}
		save = move;
		round = round->next;
	}
	printInfo(head);

}
void sortByID(node* head) {
	node* move = NULL;
	node* save = NULL;


	node* round = head->next;
	while (round != NULL) {
		move = head->next;
		while (move->next != save) {
			if (move->stu.ID > move->next->stu.ID) {
				Stu tmp = move->stu;
				move->stu = move->next->stu;
				move->next->stu = tmp;
			}
			move = move->next;
		}
		save = move;
		round = round->next;
	}
	printInfo(head);
}

void clearData(node* head) {
	node* move=head;
	move->next = NULL;
	printInfo(head);
	saveFiles(head);
}