#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Hàm đệ quy để đếm số chữ số của số nguyên dương n
int countDigits(int n) {
	if (n < 10) {
		return 1;
	}
	return 1 + countDigits(n / 10);
}

int main() {
	int n;

	// Nhập vào một số nguyên dương
	printf("Nhap vao mot so nguyen duong: ");
	scanf("%d", &n);

	// Kiểm tra xem số nhập vào có phải là số nguyên dương không
	if (n <= 0) {
		printf("Vui long nhap mot so nguyen duong.\n");
		return 1;
	}

	// Đếm số chữ số của n
	int numberOfDigits = countDigits(n);

	// In kết quả
	printf("So %d co %d chu so.\n", n, numberOfDigits);
	system("pause");
	return 0;
}
