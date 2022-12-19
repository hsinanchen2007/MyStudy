### 解题思路

由于kadane算法求最大子序列和，无法跨越边界，因此，问题拆分为两个子问题：
（1）A的最大子序列和
（2）跨边界最大子序列和

重点在子问题（2），可以两次遍历求解：

1.先使用dp[i]记录包括必须包括A[0]的子序列A[0~i]的最大值，是边界点的右侧和；

2.再遍历sum(i~Asize-1)作为边界左侧和;

3.两者相加得到跨边界子序列最大和。

[包括A[0]的最大子序列]  |   [ i + 1剩余元素和   ]
A[0] A[1]........A[i-1] |   A[i+1].....A[N-1]

= [ i + 1剩余元素和   ][包括A[0]的最大子序列]

进而得到从i+1开始的跨边界最大子序列和。

该解法效率不是最优，但思路简单直观。

![image.png](https://pic.leetcode-cn.com/73bdb56d72894e3e94b6867687e78dc44599c9b0bba1efaebaa185651e32fc21-image.png)


### 代码

```c


#define MMAX(a, b)	((a) > (b)? (a) : (b))

//【算法思路】kadane算法+dp。将题目分解为两个问题：（1）A使用kadane算法求最大子序列和；（2）求解跨边界最大子序列和。
//求解问题2时，使用dp[i]记录包括A[0]的从0~i序列的最大子序列和，然后和包括A[ASize - 1]的子序列和相加，得到跨边界最大子序列和
int maxSubarraySumCircular(int* A, int ASize){
	if(ASize == 1)
	{
		return A[0];
	}

    //kadane算法求最大子序列和
    int res = INT_MIN;
    int sum = 0;
	for(int i = 0; i < ASize; i++)
	{
        if(sum > 0)
		{
			sum += A[i];
		}
		else
		{
			sum = A[i];
		}

        res = MMAX(res, sum);
	}

    //记录包括必须包括a[0]的序列的和的最大值
    int *dp = (int *)calloc(ASize, sizeof(int));

    sum = 0;
    int tmax = INT_MIN;
    for(int i = 0; i < ASize; i++)
    {
        sum += A[i];

        tmax = MMAX(tmax, sum);
        dp[i] = tmax;
    }
/*
    for(int i = 0; i < ASize; i++)
    {
        printf("dp[%d] = %d ", i, dp[i]);
    }
    printf("\n");
*/
    //利用记录的包括a[0]的和的最大值，计算跨边界序列最大值
    //dp[i]是跨边界右侧的最大值，下面遍历左边的和，相加即为跨边界序列最大值
	sum = 0;
	
	for(int i = ASize - 1; i >= 0; i--)
	{
		sum += A[i];

        //printf("sum[%d] = %d ", i, sum);

		res = MMAX(res, (i > 0? sum + dp[i - 1] : sum));
	}

	return res;
}
```