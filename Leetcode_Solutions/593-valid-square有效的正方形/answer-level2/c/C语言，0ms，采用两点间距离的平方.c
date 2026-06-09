### 解题思路
主要思路是四个点两两组合，分别算出平方存入一个数组中
该数组所有元素的和就是8倍个边长的平方，进而推算出如果是正方形需要满足的条件，即该数组y中出现四次边长的平方并且出现两次2*边长的平方。
缺点就是需要long long int，内存消耗太大（不然会溢出）

### 代码

```c
long long int twoPoints(int* p1, int* p2)
{
	long long int dx = (p1[0] - p2[0]) * (p1[0] - p2[0]);
	long long int dy = (p1[1] - p2[1]) * (p1[1] - p2[1]);
	return (dx + dy);
}
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) 
{
	long long int len[6];
	len[0] = twoPoints(p1, p2), len[1] = twoPoints(p1, p3), len[2] = twoPoints(p1, p4);
	len[3] = twoPoints(p2, p3), len[4] = twoPoints(p2, p4), len[5] = twoPoints(p3, p4);
	
	int i = 0;
	long long int sum=0;
	for (i; i < 6; i++)
	{
		sum = sum + len[i];
	}
	long long int length1 = sum / 8;//一条边的平方
	long long int length2 = 2 * length1;//对角线的平方
	int count1 = 0, count2 = 0;
	for (int j = 0; j < 6; j++)
	{
		if (len[j] == length1)
			count1++;
		else if (len[j] == length2)
			count2++;
		else
			;
	}
	if (count1 == 4 && count2 == 2)
		return 1;
	else
		return 0;

}

```