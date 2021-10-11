#include <iostream>

using namespace std;

int Default(int a, int k, char arr[], char* arr2, int *arr3, int* arr4) {

    cout << "Ви ввели: ";
    for (int i = 0; i < a; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl << "Індекси букв: ";
    for (int j = 0; j < a; j++) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] == arr2[j]) {
                arr3[j] = i;
            }
        }
    }
    for (int i = 0; i < a; i++) {
        cout << arr3[i] << " ";
    }

    for (int i = 0; i < a; i++) {
        arr4[i] = arr3[i];
    }
    
    return 0;
}

int Scrambler(int a, int k, char arr[], char* arr2, int* arr3, int* arr4, int* arr5) {
    cout << endl << "Індекси букв з першою k: ";
    for (int i = a; i > 0; i--) {
        arr3[i] = arr3[i - 1];
    }
    arr3[0] = k;
    for (int i = 0; i < a; i++) {
        cout << arr3[i] << " ";
    }

    cout << endl << "Індекси зашифрованого тексту: ";
    for (int i = 0; i < a; i++) {
        arr5[i] = arr3[i] + arr4[i];
        if (arr5[i] >= 26) {
            arr5[i] = arr5[i] - 26;
        }
    }
    for (int i = 0; i < a; i++) {
        cout << arr5[i] << " ";
    }

    cout << endl << "Зашифрований текст: ";
    for (int j = 0; j < a; j++) {
        for (int i = 0; i < 26; i++) {
            if (i == arr5[j]) {
                arr2[j] = arr[i];
                cout << arr2[j] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}

int Decoder(int a, int k, char arr[], char* arr2, int* arr3, int* arr4, int* arr5) {
    cout << endl << "Дешифровані індекси: ";
    if ((arr4[0] - k) < 0) {
        arr5[0] = arr4[0] - k + 26;
    }
    else {
        arr5[0] = arr4[0] - k;
    }
    for (int i = 0; i < a; i++) {
        if (arr3[i + 1] - arr5[i] < 0) {
            arr5[i + 1] = arr3[i + 1] - arr5[i] + 26;
        }
        else {
            arr5[i + 1] = arr3[i + 1] - arr5[i];
        }
    }
    for (int i = 0; i < a; i++) {
        cout << arr5[i] << " ";
    }

    cout << endl << "Розшифрований текст: ";
    for (int j = 0; j < a; j++) {
        for (int i = 0; i < 26; i++) {
            if (arr5[j] == i) {
                arr2[j] = arr[i];
                cout << arr2[j] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}

int main() {
    int a = 0, b = 0, k = 0;
    char* arr2 = new char;

    char arr[] = "abcdefghigklmnopqrstuvwxyz";

    int* arr3 = new int[a];
    int* arr4 = new int[a];
    int* arr5 = new int[a];
    
    setlocale(LC_CTYPE, "Ukrainian");
    cout << "Якщо Ви хочете зашифрувати - введіть 0, якщо дешифрувати - введіть 1: ";
    cin >> b;
    
    cout << "Введіть фразу для шифрування: ";
    cin >> arr2;
    a = strlen(arr2);
    
    cout << "Введіть k: ";
    cin >> k;

    if (b == 0) {
        Default(a, k, arr, arr2, arr3, arr4);
        Scrambler(a, k, arr, arr2, arr3, arr4, arr5);
    } else {
        Default(a, k, arr, arr2, arr3, arr4);
        Decoder(a, k, arr, arr2, arr3, arr4, arr5);
    }
    return 0;
}
