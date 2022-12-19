看到这个题最开始想的是写一个计算两个数的汉明距离的函数，之后循环的加一下，结果全复杂度太高，超时：
int HammingDistance(int i_num1, int i_num2)
{
	int i_Ham = 0;
	int num1 = i_num1;
	int num2 = i_num2;

	int num3 = num1^num2;


	while (num3)
	{
		if (((num3 - 1)^ num3) == 1)
			i_Ham++;
		num3 = num3 >> 1;
	}

	return i_Ham;
}

int totalHammingDistance(int* nums, int numsSize) 
{
	int i_totalHammingDistance = 0;
	for (int i = 0; i < numsSize-1; i++)
		for (int j = i + 1; j < numsSize; j++)
		{
			i_totalHammingDistance = i_totalHammingDistance + HammingDistance(nums[i], nums[j]);
		}

	printf("\ni_totalHammingDistance:%d\n", i_totalHammingDistance);
	return i_totalHammingDistance;
}

后面按位来计算，总的汉明距离等于每个位的汉明距离之和。一个数一共30位，对于每一位来算，实际只需要统计1和0的个数即可，1的个数乘以0的个数就是这个位的汉明距离：
int totalHammingDistance(int* nums, int numsSize)
{
	int i_totalHammingDistance = 0;
	for (int i = 0; i < 30; i++)
	{
		int i_eq_0 = 0;  //0的总个数
		int i_eq_1 = 0;  //1的总个数
		for (int j = 0; j < numsSize; j++)
		{
			int i_tmp = nums[j] >> i;
			if (((i_tmp - 1) ^ i_tmp) == 1)
				i_eq_1++;
			else
				i_eq_0++;
		}
		i_totalHammingDistance = i_totalHammingDistance + i_eq_0*i_eq_1;
	}

	return i_totalHammingDistance;
}