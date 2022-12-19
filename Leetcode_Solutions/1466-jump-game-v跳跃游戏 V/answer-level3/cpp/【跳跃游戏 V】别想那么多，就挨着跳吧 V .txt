### 思路
1. 分析题目
   11. 只能往左右两个方向跳
   12. 只能往低了跳，并且跳过去的部分不能比 **起跳点** 高
   13. 可以从任意点起跳，不能跳到外边
   14. 求最多能跳的次数
2. 递归
   21. 从一个点开始跳，往左或往右
   22. 如果高度比 **起跳点** 高，就结束
   23. 如果可以跳，就挨着跳
      231. **起跳点** 的 **可跳跃次数** 是所有能跳到的点的最大 **可跳跃次数** 加一
      232. 递归进入这个点，计算他的 **可跳跃次数**
   24. 如果左右两边都没有可以继续跳的点，那么这个点的 **可跳跃次数** 为 0 （递归出口）
   25. 使用 `vector<int>& steps` 记忆化已经确定的 **可跳跃次数**
   26. 使用 `ans` 保存最大的结果

### 答题
```C++
void maxJumps(vector<int>& arr, int d, int cur, vector<int>& steps, int& ans)
{
	if (steps[cur] != -1) return;

	int l = max(0, cur - d);	// 确定左右边界
	int r = min((int)arr.size() - 1, cur + d);

	int step = 0;
	for (int dirction = -1; dirction <= 1; dirction += 2)	// 方向，往左往右
	{
		for (int i = cur + dirction; i <= r && i >= l; i += dirction)
		{
			if (arr[cur] <= arr[i]) break;	// 高度超过就结束

			maxJumps(arr, d, i, steps, ans);	// 递归
			step = max(step, steps[i]);
		}
	}

	steps[cur] = step + 1;
	ans = max(ans, steps[cur]);
}

int maxJumps(vector<int>& arr, int d) 
{
	vector<int> steps(arr.size(), -1);
	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		maxJumps(arr, d, i, steps, ans);
	}
	return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

