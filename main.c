#include <stdio.h>
#include <assert.h>

// calculate_mode возвращает моду из массива а.
// вместо точки с запятой открывайте фигурные скобки и пишите ваше решение.
int calculate_mode(int n, int a[n]) {
	int m[n][2];
	int max = 0;
	int i, j, k;
	
	if (n == 1) {
		return a[0];
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (m[j][1] == 0) {
				m[j][0] = a[i];
				m[j][1]++;
				break;
			}
			else if (m[j][0] == a[i]) {
				m[j][1]++;
				break;
			}
		}
	}
	for(i = 0; i < n; i++) if (max <= m[i][1]) { max = m[i][1]; }
	for(i = 0; i < n; i++) if (m[i][1] == max) k++;
	if(k!=1){for( i = 0; i < n; i++) if (a[0]>max) max = a[0];}
	return max;
}


void test_calculate_mode() {
	assert(calculate_mode(1, (int[]) { 1 }) == 1);
	assert(calculate_mode(2, (int[]) { 1, -1 }) == 1);
	assert(calculate_mode(3, (int[]) { 1, 2, 3 }) == 3);
	assert(calculate_mode(3, (int[]) { 0, 0, 0 }) == 0);
	assert(calculate_mode(5, (int[]) { 1, 2, 3, 3, 4 }) == 3);
	assert(calculate_mode(6, (int[]) { 1, 1, 2, 2, 3, 4 }) == 2);
	assert(calculate_mode(10, (int[]) { 1, 12, -3, -3, 12, -3, 1, 4, -3, 4 }) == -3);

	printf("Тесты прошли успешно!\n");
}

int main() {
	test_calculate_mode();
	return 0;
}