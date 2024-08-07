#include <stdio.h>
#include <stdlib.h>

// Hàm đệ quy để đếm số chữ số chẵn của số nguyên dương n
int countEvenDigits(int n) {
	if (n == 0) {
		return 0;
	}
	int lastDigit = n % 10;
	if (lastDigit % 2 == 0) {
		return 1 + countEvenDigits(n / 10);
	}
	return countEvenDigits(n / 10);
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

	// Đếm số chữ số chẵn của n
	int numberOfEvenDigits = countEvenDigits(n);

	// In kết quả
	printf("So %d co %d chu so chan.\n", n, numberOfEvenDigits);
	system("pause");
	return 0;
}
