先看题目要我做什么，求两个有序数组的中位数。
比较直观的想法是，假设数组A和数组B按序将元素排列在一起，形成数组 C，这时求中位数就只有两种情况：

	1). 元素个数 num 为奇数时，中位数就是 C[num / 2]；
	2). 元素个数 num 为偶数时，中位数就是 ( C[num / 2] + C[num / 2 + 1] ) / 2;

**所以，这个题可以转换为查找虚拟数组 C 的第 k 个数（ C[0] 是第1个元素）**
情况1)只需要查找1个数，情况2)查找2个数并求中值。

考虑到时间复杂度的要求，不能真的生成数组 C，这里用下标 i、j 分别指向数组A、B。O(logn)的时间复杂度也可以联想到要用到二分查找。

#### 大致的思路是，第k个数满足 ( i + j ) == k ，利用理想场景 i == j == k / 2 来一步步逼近正确结果，每次逼近都递减k（以 k / 2 递减），直到 k == 1 就找到了第k个数。具体步骤：

	1.  在 A 和 B 中递增下标到各自的第 k / 2 个元素，记作 a 和 b。**

   	2.  若 a <= b ，说明数组 A 中 a 左侧的元素（包括 a 本身）属于虚拟数组 C 的前 k 个元素且一定不包含第k个，
   	    记作找到了 k / 2 个，递减 k 为 k - k / 2 ，并且更新数组 A 的下标到 a 的下一个，数组 B 的下标不变。
        同样的道理，若 b <= a ，则更新数组 B 的下标到 b 的下一个，数组 A 的下标不变。

   	3.  对更新后的数组继续执行操作1，直到 k == 1 时，对比数组 A 和 B 中当前下标所指元素的值，较小的那个值就
   	    是我要找的第 k 个数。

这里比较难理解的是，**当 a <= b 时，为什么数组 A 中 a 左侧（包括 a 本身）一定在前 k 个数里？** 
下面就来分析。先定义几个代号，AaL代表数组A中元素a左侧（包括a本身），AaR代表数组A中元素a右侧。


**根据题意，数组 A 和数组 B 都是有序数组，左边的数都小于右边的（相对位置不变，这很重要）。位于AaL的数一定位于虚拟数组CbL，这是很自然的。如果AaR大于 b ，则 b 就是这第 k 个数，这时位于AaL的元素就包含在前k个里。但是，数组 AaR也可能比 b 小（加入到虚拟数组CbL），这时第 k 个数的位置就会往 b 的左侧移动， CbL 每加入一个位于 AaR 的元素，第k个数的右边就会多一个位于 AaR 或者 BbL 的元素，但永远不可能多出位于 AaL 的元素（多出的个数和加入的个数相等），所以第 k 个数的位置一直在 a 右侧。**

剩下的就是一些边界条件的考虑：
   1.  当一个数组查找完时，跳转到另一个数组并从该数组当前下标继续查找
   2.  当一个数组没有第 k / 2 个元素时，取两数组剩余元素最小值为步长来查找

最后算一下这种解法的时间复杂度
$$C + (\frac{k}{2} + \frac{k}{2}) + (\frac{k}{4} + \frac{k}{4}) + (\frac{k}{8} + \frac{k}{8}) + ... (\frac{k}{2^x} + \frac{k}{2^x})$$
$$= C + k + \frac{k}{2} + \frac{k}{4} + ... + \frac{k}{2^{x-1}}$$
所以 
$${\lim_{x \to +\infty}}{C + k + \frac{k}{2} + \frac{k}{4} + ... + \frac{k}{2^{x-1}}}$$
$$ = C+ log_{2}k = C+ log_2(\frac{m+n}{2}) = C + log_2{\frac{1}{2}}+log_2{(m+n)}$$
可以看出，时间复杂度符合题目要求。

```
static int FindKthNumber(int *A, int Asize, int *B, int Bsize, int K)
{
	int number = 0;
	int k = K;
	int stride = 0; // 查找步进，以便应付特殊情况
	int i = 0, j = 0;
	while (k > 1)
	{
		int oi = i, oj = j; // 记录初始i、j，以便每轮结束时将被放弃的数组下标重置
		int kA = 1, kB = 1; // i和j当前所指数字各算一个
		if ((Asize - i) != 0 && (Bsize - j) != 0) //计算步长
		{
			stride = (Asize - i) <= (Bsize - j) ? (Asize - i) : (Bsize - j);
			stride = (k / 2 <= stride) ? (k / 2) : stride;
		}
		else
		{
			stride = (k / 2 <= (Asize - i + Bsize - j)) ? k / 2 : (Asize - i + Bsize - j);
		}
		while (i < Asize && kA < stride)
		{
			i++;
			kA++;
		}
		while (j < Bsize && kB < stride)
		{
			j++;
			kB++;
		}
		// 去掉找到的数字，并更新所在数组的下标
		k = k - stride;
		if (j < Bsize && i < Asize) // 如果两个数组都还没遍历完，则通过比较第k/2小数决定更新哪个数组的下标
		{ 
			if (A[i] <= B[j])
			{
				i++;
				j = oj;
			}
			else
			{
				j++;
				i = oi;
			}
		}
		else if(j == Bsize) // 数组B已遍历完，当前下标要有效，只能是在数组A中
		{
			i++;
			j = oj;
		}
		else // i == Asize
		{
			j++;
			i = oi;
		}
	}

	// 判断第k小数在哪个数组，如果A、B均未遍历完则通过比较当前下标确定，如果任一数组遍历完则在未遍历完数组当前下标
	if (i < Asize && j < Bsize)
	{
		number = A[i] <= B[j] ? A[i]: B[j];
	}
	else if(j == Bsize)
	{
		number = A[i];
	}
	else // i == Asize
	{
		number = B[j];
	}
	
	return number;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1 == NULL || nums2 == NULL || (nums1Size == 0 && nums2Size == 0))
	{
		return -1;
	}
	double n = 0, m = 0;
	if ((nums1Size + nums2Size) % 2 == 1) // 奇数
	{
		n = FindKthNumber(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1);
		return n;
	}
	else // 偶数
	{
		n = FindKthNumber(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2);
		m = FindKthNumber(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1);
		return (n + m) / 2.0;
	}
}
```
