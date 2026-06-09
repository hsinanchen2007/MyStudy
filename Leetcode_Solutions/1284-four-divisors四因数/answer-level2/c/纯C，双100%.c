### 解题思路
上午的比赛，一开始做从一遍历到nums[i]一直超时，之后比赛结束后在讨论区有大神给了解答，改了之后可以通过了
1.先判断是否为平方数，是平方数则一定不是四因子数，因为如果是平方数则它必有一个单独的因子，所以不可能是四因子数。
2.然后遍历到平方根，详细看下面注释。

### 代码

```c
int sumFourDivisors(int* nums, int numsSize)
{
	int sumfour = 0;
	int incflag = 0;

	for (int i = 0; i < numsSize; i++)
	{
		int flag = 0;
		int cnt = 1;
		int sqrroot = sqrt(nums[i]);
		int sum = 1 + nums[i];
		for (int j = 2; j < sqrt(nums[i]); j++)
		{
			if (sqrroot * sqrroot == nums[i])  //如果是平方数直接跳出判断下一个数
			{
				break;
			}

			if (nums[i] % j == 0)
			{
				cnt++;
				sum += (j + nums[i]/j);
			}

			if (cnt > 2)
			{
				break;
			}
		}
		if (cnt != 2)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			incflag++;
			sumfour += sum;
		}
	}

	if (incflag == 0)
		return 0;
	else
		return sumfour;
}
```