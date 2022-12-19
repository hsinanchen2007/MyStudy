### 思路
1. 一看到控件O(1)的原地算法，脑子就跑偏了，觉得除了swap没有别的办法了。
2. 因为往右挪，所以先从后往前遍历，把从第k个到最后的全部交换好。
3. 本来以为前面k个也会好好的，结果发现事情并没有那么简单。只好再处理前面被交换的乱七八糟的部分。
4. 分析几个用例发现是有规律的，和k，iLen有难以描述的关系。
5. 通过重新计算k和iLen，循环交换直到正确。

![Solution.jpg](https://pic.leetcode-cn.com/7cb124c41dc1bf06003e6c38d918cdbc9fb8d83183107fe6fb4fca8ea86f9aeb-Solution.jpg)  
↑↑ 看不清可以右键查看大图  

### 答题
```C++
void rotate(vector<int>& nums, int k)
{
	k = k % nums.size();
	int iLen = nums.size();

	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}

		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)