### 分析

1. 看一个例子，根据题目要求，当满足 `k=2` 条件时，会有这16种子数组是「优美子数组」
![1.png](https://pic.leetcode-cn.com/b6a2e2a03e30b65219f5cd574c0752f41dd1d64a9675efe80e8f7f48bd263973-1.png)  

2. 而这16种，其实是通过满足k个奇数的情形下，**前面的个数**（3+1），与**后面的个数**（3+1），排列组合4*4的结果
![2.png](https://pic.leetcode-cn.com/41f0419236ae0a111da1c072809686fe2c1d1f2326b52f7aae5213541f251686-2.png)  

3. 如果使用一个数组来记录奇数的索引，可以通过相邻奇数索引做减法得到**前面的个数**，和**后面的个数**
![3.png](https://pic.leetcode-cn.com/cc0246b7b508790d5d1454561504e6d1196e438e274e217dce3b86f205ea0c8a-3.png)  

4. 数组的开头和结尾制造一个假的奇数，会方便计算
5. 滑动窗口，窗口设置为 `k+1` 个，而不是 `k` 个，这样会方便计算 `k` 个奇数**后面的个数**




### 思路
1. 使用一个 `vector<int>` 记录奇数的索引，并根据时机插入头尾两条假数据
2. 使用滑动窗口，保证窗口内有 `k+1` 个奇数
   * 当滑到一个窗口的时候，计算刚脱离窗口的**前面的个数** `a`
   * 计算在窗口内的**后面的个数** `b`
   * `a*b` 为含有滑动窗口中前 `k` 个奇数的子数组组合数
   * 结果累加
3. 结束遍历后，返回结果

### 答题
```C++
int numberOfSubarrays(vector<int>& nums, int k)
{
	vector<int> odd;
	odd.push_back(-1);

	int ans = 0;
	int i = 1;
	for (int j = 0; j <= nums.size(); j++)
	{
		if (j == nums.size() || (nums[j] & 1))
		{
			odd.push_back(j);
		}

		if (odd.size() - i > k)
		{
			int a = odd[i] - odd[i - 1];
			int b = j - odd[odd.size() - 2];
			ans += a * b;
			i++;
		}
	}
	return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

