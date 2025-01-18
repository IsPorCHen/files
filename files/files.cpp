#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

FILE* openFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        wprintf(L"Не удалось открыть файл\n");
        exit(1);
    }
    return file;
}

void readAndPrintData(FILE* file) {
    wchar_t fio[100], position[50], Otch[50], job[20], birthdate[20], address[200], phone[20];

    while (fwscanf(file, L"%ls %ls %ls %ls %ls %ls %ls", fio, position, Otch, job, birthdate, address, phone) != EOF) {
        wcout << L"ФИО: " << fio << L" " << position << L" " << Otch << endl;
        wcout << L"Должность: " << job << endl;
        wcout << L"Дата рождения: " << birthdate << endl;
        wcout << L"Адрес: " << address << endl;
        wcout << L"Телефон: " << phone << endl;
        wcout << L"----------------------------" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const char* filename = "Bagazh.txt";

    FILE* file = openFile(filename);

    readAndPrintData(file);

    fclose(file);

    return 0;
}
