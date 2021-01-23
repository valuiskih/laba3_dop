//6(доп). высчитать среднее геометрическое и обнулить меньшие.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void sr_geo(float* arr, int len)
{
	int i;
	float K = 0;
	float T = 1;
	float S = 1;
	float R = 1;
	float ln_T = 0;
	float ans = 0;
	float t_t = 0;
	float t_otv = 1;
	double M = 0;
	double e = 2.71828;
	for (i = 0; i < len; i++)
	{
		K = K + 1;
		T = T * arr[i];
	}
	t_t = (T - 1) / (T + 1);
	for (i = 1; i < 100; i++)
	{
		t_otv = t_otv * t_t;
		if (i % 2 != 0)
		{
			M = M + ((1 / (double)i) * t_otv);
		}
	}
	t_t = (T - 1) / (T + 1); // ряд маклорена для ln
	ln_T = 2 * M * (1 / K);
	ans = 1 + ln_T + (ln_T * ln_T) / (2) + (ln_T * ln_T * ln_T) / (1 * 2 * 3); // разложение по тейлору e^x

	for (i = 0; i < len; i++)
	{
		if (arr[i] < ans)
		{
			arr[i] = 0;
		}
	}
}
int main()
{
	int i, l;
	float m[100];
	printf("Enter the length of the array \n");
	if ((scanf("%d", &l) != 1) || (l <= 0))
	{
		printf("Only positive integer numbers can be entered ");
		return -1;
	}
	else if (l > 100)
	{
		printf("Array size exceeded");
		return -1;
	}
	else
		for (i = 0; i < l; i++)
		{
			printf("Enter the %d element \n", i + 1);
			if (scanf("%f", &m[i]) != 1)
			{
				printf("Only numbers can be entered ");
				return -1;
			}
		}
	sr_geo(m, l);
	printf("New array \n");
	for (i = 0; i < l; i++)
	{

		printf("%f \n", m[i]);
	}
	return 0;
}
