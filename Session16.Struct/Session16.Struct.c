// Session16.Struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
#include<string.h>

typedef struct {
	char firstName[10];
	char midName[20];
	char lastName[10];
}FullName;

typedef struct {
	int id;
	FullName name;
	float salary;
	char address[20];
	char phoneNumber[20];

} Employee;


void getEmployeeInfo(Employee* e);

void showEmployeeInfo(Employee e);

void searchByName(const Employee* employees, size_t n, Employee* result, size_t* found, const char* name);

int searchById(const Employee* employees, size_t n, int id);

void searchBySalary(const Employee* employees, size_t n, Employee* result, size_t* found,const float salary);

void showListEmployee(const Employee* employees, size_t n);

void menu();
 

int main() {

	menu();


	return 0;
}

void menu() {
	int choice = 0;

	Employee employees[100];

	size_t n = 0;

	do {
		printf("\n=========================== Management Employees ====================================");
		printf("\n1. Insert new employee in list.");
		printf("\n2. Display all of employees in listed.");
		printf("\n3. Search information's employee by  first name.");
		printf("\n4. Search information's employee by salary.");
		printf("\n5. Search inforamtion's employee by ID.");
		printf("\\n.0. Exit.");
		printf("\n====================================================================================\n");

		printf("\nYour choice? ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
		{
			printf("\nThanks for using.");
			break;
		}
		case 1:
		{
			Employee e;
			getEmployeeInfo(&e);
			employees[n++] = e;
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			showListEmployee(employees, n);
			break;
		}
		case 3:
		{
			size_t numberOfResult = 0;
			Employee result[100];

			char name[10];
			printf("\nEnter the first name that you want to search in listed: ");
			scanf("%s", name);

			searchByName(employees, n, result, &numberOfResult, name);

			if (numberOfResult > 0) {
				printf("\nEmloyees have name: %s \n", name);

				showListEmployee(result, numberOfResult);
			}
			else {
				printf("\nDon't find employee has name: %s in listed. Please try again!", name);
			}
			break;

		}
		case 4:
		{
			size_t numberOfResult = 0; 
			Employee result[100];

			float salary;

			printf("\nEnter salary: ");
			scanf("%f", &salary);

			searchBySalary(employees, n, result, &numberOfResult, salary);

			if (numberOfResult > 0) {

				printf("\nEmployees have salary >= %.2f \n", salary);

				showListEmployee(result, numberOfResult);

			}
			else {
				printf("\nDon't find employee has salary >=  %.2f in listed. Please try again!", salary);
			}
			break;

		}
		case 5:
		{
			int id;
			printf("\nEnter the Id's employee that you want to search in listed: ");
			scanf("%d", &id);

			int index = searchById(employees, n, id);

			if (index == -1) {
				printf("\nDon't find employee has Id: %d in listed.", id);
			}
			else {
				printf("\n Find employee Id: %d \n", id);

				printf("%-10s%-10s%-20s%-20s%-15s%-15s%-10s\n", "ID", "Last", "Mid", "First Name", "Addres",
					"Phone number", "Salary");

				showEmployeeInfo(employees[index]);
				
			}
			
			break;
		}
		default:
		{
			printf("\nInvalid choice. Please try again!");
			break;
		}
		}

	} while (choice != 0);


}


void getEmployeeInfo(Employee* e) {

	printf("\nEnter ID: ");
	scanf("%d", &e->id);

	printf("\nEnter the last name: ");
	scanf("%s", e->name.lastName);

	printf("\nEnter the mid name: ");
	scanf("%*c%19[^\n]", e->name.midName);

	printf("\nEnter the first name: ");
	scanf("%s", e->name.firstName);


	printf("\nEnter address: ");
	scanf("%*c%19[^\n]", e->address);

	printf("\nEnter phone number: ");
	scanf("%s", e->phoneNumber);

	printf("\nEnter salary: ");
	scanf("%f", &e->salary);



}

void showEmployeeInfo(Employee e) {

	printf("%-10d%-10s%-20s%-20s%-15s%-15s%-8.2f\n", e.id, e.name.lastName, e.name.midName,
		e.name.firstName, e.address, e.phoneNumber, e.salary);
}

void searchByName(const Employee* employees, size_t n, Employee* result, size_t* found, const char* name) {
	
	for (size_t i = 0; i < n; i++) {
		if (strcmp(employees[i].name.firstName, name) == 0) {
			result[*(found)++] = employees[i];
		}
	}
}

int searchById(const Employee* employees, size_t n, int id) {
	for (size_t i = 0; i < n; i++) {
		if (employees[i].id == id) {
			return i;
		}
	}
	return -1;
}

void searchBySalary(const Employee* employees, size_t n, Employee* result, size_t* found, const float salary) {
	
	for (size_t i = 0; i < n; i++) {
		if (employees[i].salary >= salary) {
			result[*(found)++] = employees[i];
		}
	}

}

void showListEmployee(const Employee* employees, size_t n) {
	if (n > 0) {
		puts("====================================================="
			"List Emloyee"
			"=====================================================");

		printf("%-10s%-10s%-20s%-20s%-15s%-15s%-10s\n", "ID", "Last", "Mid", "First Name", "Addres",
			"Phone number", "Salary");
		for (size_t i = 0; i < n; i++) {

			puts("---------------------------------------------------"
				"--------------------------------------------------------");

			showEmployeeInfo(employees[i]);
		}
	
	}
	else {
		printf("\nThe list is empty.");
	}

}


