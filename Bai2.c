#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Ham Sang Eratosthenes de tim tat ca cac so nguyen to <= limit
void sieveOfEratosthenes(int limit, bool isPrime[]) {
    for (int i = 0; i <= limit; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }
}

// Ham sinh cac so Blum nho hon N
int generateBlumNumbers(int N, int blum[], int maxSize) {
    int limit = sqrt(N);
    bool isPrime[limit + 1];
    sieveOfEratosthenes(limit, isPrime);

    int primes4k3[limit], primeCount = 0;

    // Loc ra cac so nguyen to dang 4k + 3
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i] && i % 4 == 3) {
            primes4k3[primeCount++] = i;
        }
    }

    int blumCount = 0;

    // Sinh cac so Blum nho hon N
    for (int i = 0; i < primeCount; i++) {
        for (int j = i; j < primeCount; j++) {
            int product = primes4k3[i] * primes4k3[j];
            if (product < N) {
                blum[blumCount++] = product;
                if (blumCount >= maxSize) return blumCount;
            }
        }
    }

    return blumCount;
}

// Ham kiem tra su ton tai cua so Blum M
bool checkBlumExistence(int blum[], int size, int M) {
    for (int i = 0; i < size; i++) {
        if (blum[i] == M) return true;
    }
    return false;
}

// Ham tim cac cap so Blum co tong la so Blum va nho hon N
void findBlumPairs(int blum[], int size, int N) {
    printf("Cac cap so Blum co tong la so Blum va nho hon %d:\n", N);
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int total = blum[i] + blum[j];
            if (total < N && checkBlumExistence(blum, size, total)) {
                printf("Cap so Blum: %d va %d\n", blum[i], blum[j]);
            }
        }
    }
}

int main() {
    int N;

    // Nhap so N tu ban phim
    printf("Nhap so N: ");
    scanf("%d", &N);

    // Kiem tra gia tri nhap vao
    if (N <= 1) {
        printf("N phai lon hon 1.\n");
        return 0;
    }

    int blum[100];  // Mang de chua cac so Blum
    int size = generateBlumNumbers(N, blum, 100);  // Tao so Blum nho hon N

    printf("Cac so Blum nho hon %d:\n", N);
    for (int i = 0; i < size; i++) {
        printf("%d ", blum[i]);
    }
    printf("\n");

    int M;
    // Nhap so M tu ban phim de kiem tra
    printf("Nhap so Blum M de kiem tra: ");
    scanf("%d", &M);
    
    if (checkBlumExistence(blum, size, M)) {
        printf("So %d co trong day so Blum.\n", M);
    } else {
        printf("So %d khong co trong day so Blum.\n", M);
    }

    // Tim cac cap so Blum
    findBlumPairs(blum, size, N);

    return 0;
}