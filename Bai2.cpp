#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo mảng ngẫu nhiên
void generateRandomArray(int *a, int n, int lower, int upper) {
	srand(time(0)); 
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % (upper - lower + 1)) + lower;
	}
}

// Hàm tính tổng các phần tử chẵn trong mảng
int sumEven(int a[], int n) {
	if (n == 0) return 0;
	return (a[n - 1] % 2 == 0 ? a[n - 1] : 0) + sumEven(a, n - 1);
}

// Hàm tìm kiếm nhị phân
int binarySearch(int a[], int x, int left, int right) {
	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (a[mid] == x) return mid;
	if (a[mid] > x) return binarySearch(a, x, left, mid - 1);
	return binarySearch(a, x, mid + 1, right);
}

// Hàm tìm max chẵn trong mảng
int maxEven(int a[], int n) {
	if (n == 0) return -1;
	int max = maxEven(a, n - 1);
	if (a[n - 1] % 2 == 0 && (max == -1 || a[n - 1] > max)) return a[n - 1];
	return max;
}

// Hàm tính tổng các phần tử lẻ trong mảng
int sumOdd(int a[], int n) {
	if (n == 0) return 0;
	return (a[n - 1] % 2 != 0 ? a[n - 1] : 0) + sumOdd(a, n - 1);
}

// Hàm xuất các số ở vị trí lẻ
void printOddIndices(int a[], int n, int index) {
	if (index >= n) return;
	if (index % 2 != 0) printf("%d ", a[index]);
	printOddIndices(a, n, index + 1);
}

int main() {
	int n ; 
	int lower = 1, upper = 100; 
	printf("Moi nhap n so nguyen: ");
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Khong du bo nho cap phat\n");
		return -1;
	}

	// Tạo mảng ngẫu nhiên
	generateRandomArray(a, n, lower, upper);

	// In mảng ngẫu nhiên

	printf("\nMang ngau nhien: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	int x = 7; 

	//1. Tính tổng các phần tử chẵn
	printf("Tong cac phan tu chan: %d\n", sumEven(a, n));

	//2. Tìm kiếm số x bằng thuật toán tìm kiếm nhị phân
	int index = binarySearch(a, x, 0, n - 1);
	if (index != -1) {
		printf("So %d duoc tim thay tai vi tri %d\n", x, index);
	}
	else {
		printf("So %d khong duoc tim thay\n", x);
	}

	//3. Tìm max chẵn trong mảng
	int max = maxEven(a, n);
	if (max != -1) {
		printf("Gia tri chan lon nhat trong mang: %d\n", max);
	}
	else {
		printf("Khong co gia tri chan trong mang\n");
	}

	//4. Tính tổng các phần tử lẻ
	printf("Tong cac phan tu le: %d\n", sumOdd(a, n));

	//5. Xuất các số ở vị trí lẻ
	printf("Cac so o vi tri le: ");
	printOddIndices(a, n, 0);
	printf("\n");

	free(a);
	system("pause");
	return 0;
}
