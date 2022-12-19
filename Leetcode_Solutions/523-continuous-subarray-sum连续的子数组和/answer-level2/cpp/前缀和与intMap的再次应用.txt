### 解题思路
【先赞后看，养成习惯】
首先需要理清楚两个概念`子序列`和`子数组`
- 子序列：数组中不连续的某一段数字，但是要保持原先的**先后顺序**(n>...>k>j>0)
$$
A[i],A[i+j],A[i+k],...,A[i+n] 
$$
- 子数组：数组中连续的某一段数字，例如
$$
A[i],A[i+1],A[i+2],...,A[i+n]
$$
这道题是对子数组求和，因此我们可以考虑用`前缀和(preSum)`来表示A[i],...,A[i+n]这段子数组的和
### 前缀和概念
`preSum[i]`：表示的是A[0]+A[1]+A[2]+...+A[i]的和（这里我定义是**左闭右闭**）
$$
preSum[i] =  \sum_{j=0}^iA[j]
$$
**Note**：在实际使用过程中，preSum[0] = 0，preSum[1] = 0 + A[1]（这里根据个人使用习惯啦~）

### 前缀和解题
根据以上`前缀和`的概念，我们容易求出任意一段子数组的和
$$
preSum[i] - preSum[j-1] == A[j] + A[j+1] + ... +A[i]
$$
因此我们只需要两重循环，寻找是否存在这样的子数组即可
```cpp
for (int i = 1; i <= n; i++) {
	for (int j = 0; j < i - 1; j++) {
		if ((k != 0 && (preSum[i] - preSum[j]) % k == 0) || \
			(k == 0 && preSum[i] - preSum[j] == 0)) {
			return true;
		}
	}
}
```
### intMap的应用
（`intMap`可以参考`我的题解`[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/solution/zhuang-tai-ding-yi-hen-shi-zhong-yao-by-christmas_/)）
基于如下等式，
$$
(preSum[i] - preSum[j])\mod k == 0 \Longleftrightarrow preSum[i]\mod k == preSum[j]\mod k 
$$
因此我们可以认为如果`preSum[i]`和`preSum[j]`在intMap中映射到了同一`余数`，即表示这样的子数组存在

```cpp
for (int i = 1; i <= n; i++) {
   	int index = preSum[i] % k;
   	for (auto iter : intMap[index]) {
		if (iter < i - 1) { return true; }
   	}
}
```
### 相关题目
- 以下题目需要考虑用到`前缀和(preSum)`
[LeetCode1314 矩阵区域和](https://leetcode-cn.com/problems/matrix-block-sum/)
[LeetCode303 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)
[LeetCode304 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)


- 以下题目需要考虑用到`intMap`来优化
[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence)
[LeetCode1218 最长定差子序列](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference)
### 我的题解
[LeetCode1262 可被三整除的最大和](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/dong-tai-gui-hua-yu-zhuang-tai-zhuan-yi-by-christm/)
[LeetCode688 “马”在棋盘上的概率](https://leetcode-cn.com/problems/knight-probability-in-chessboard/solution/zhuang-tai-ji-de-zai-ci-ying-yong-by-christmas_wan/)
[LeetCode967 连续差相同的数字](https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences/solution/cun-chu-kong-jian-ke-bian-de-dpshu-zu-by-christmas/)
[LeetCode873 最长的斐波那契子序列的长度](https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/solution/zhuang-tai-ding-yi-hen-shi-zhong-yao-by-christmas_/)
[LeetCode1218 最长定差子序列](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/solution/yi-dao-jian-dan-de-dong-tai-gui-hua-de-you-hua-wen/)

### 代码

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
	if (n == 0) { return false; }

	if (k == 0) {
		for (int i = 1; i < n; i++) {
			if (nums[i - 1] == nums[i]&& nums[i] == 0) {
				return true;
			}
		}
		return false;
	}
	else {
    		vector<int> preSum(n + 1);
	    	unordered_map<int, vector<int>> intMap;
	    	preSum[0] = 0;
	    	for (int i = 1; i <= n; i++) {
		    preSum[i] = preSum[i - 1] + nums[i - 1];
        	    intMap[preSum[i] % k].push_back(i);
	    	}
          	intMap[preSum[0] % k].push_back(0);
	
		for (int i = 1; i <= n; i++) {
		    int index = preSum[i] % k;
		    for (auto iter : intMap[index]) {
			if (iter < i - 1) { return true; }
	    	    }
		}
		return false;
	}
    }
};
```