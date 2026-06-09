### 经典的位运算
这道题目已经广为流传了，扫描数组，使用异或运算，最终的结果即是答案。
至于为什么异或运算是题解，首先需要了解以下几点：
1. 什么是异或运算(xor)：`1 xor 1 = 0, 0 xor 0 = 0, 1 xor 0 = 1, 0 xor 1 = 1`
2. 知道了什么是异或运算之后，就可以得出`任意数字异或其自身等于0`的结论。比如数字5，其二进制是101，那么就有`101 xor 101 = 0`
3. 知道了什么是异或运算之后，就可以得出`任意数字异或0等于其本身`的结论。
4. 位运算与顺序无关，即`a xor b = b xor a, a xor b xor a = a xor a xor b = b`

因此，对于数组内只有一个数字出现了奇数次，其余数字都是出现偶数次的情况，异或运算刚好完美解决这个问题。
```
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int num = 0;
		for (vector<int>::size_type i = 0; i < nums.size(); ++i)
			num ^= nums[i];
		return num;
	}
};

```
文末推荐：[Single Number - LeetCode官方题解](https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode/)
我果真不适合写题解，写文章啊！