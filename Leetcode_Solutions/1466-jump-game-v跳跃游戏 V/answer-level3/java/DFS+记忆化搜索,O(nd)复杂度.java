## DFS其实就是很简单的对问题模拟，借助递归，我们能很容易地将一个大问题分为多个小问题，而记忆化能够避免重复计算。
### 对于本题，大问题是:从i处开始能访问到的最多下标是多少个？
我们假设ii可以直接到达的下标集合为s,小问题就是：从s集合中的每一个元素出发可以访问多少个下标？那么大问题的解就是所有小问题的解的最大值+1。由于多个柱子可能跳到同一个柱子，就会导致重复计算，因此，可以将从每个柱子出发的解记下来，之后要计算的时候，先查表就行了。  
```
class Solution {
public:
	int max(int a, int b) {
		return a > b ? a : b;
	}
	int dfs(int cur, vector<int>&arr, int d, vector<int>&mem) {
		//返回cur开始能走的最大值,cur有效
		if (mem[cur] != 0) {
			return mem[cur];
		}
		else {
			int tmpMax = 0;
			for (int i = 1; i <= d && (cur - i) >= 0; ++i) {
				if (arr[cur - i] < arr[cur]) {
					tmpMax = max(tmpMax, dfs(cur - i, arr, d, mem));
				}
				else {
					break;
				}
			}
			for (int i = 1; i <= d && (cur + i) < arr.size(); ++i) {
				if (arr[cur + i] < arr[cur]) {
					tmpMax = max(tmpMax, dfs(cur + i, arr, d, mem));
				}
				else {
					break;
				}
			}
			tmpMax++;
			mem[cur] = tmpMax;
			return tmpMax;
		}
	}
	int maxJumps(vector<int>& arr, int d) {
		int ret = 0;
		vector<int> mem(arr.size());
		for (int i = 0; i < arr.size(); ++i) {
			ret = max(ret, dfs(i, arr, d, mem));
		}
		return ret;
	}
};
```
### 复杂度分析
对每个点都向左右两个方向查找d的范围，因此时间复杂度为O(nd)。  
递归栈栈用O(n)的空间，因为同时最多只能有n个柱子的dfs函数在递归栈中。