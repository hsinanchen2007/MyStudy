**一、思路**
- 求子数组的长度的直观感受——找到满足条件的**区间左右边界**。
- 因为负数的存在，导致区间长度变长且区间和变小的情况的发生。
- 合适的数据结构是解开问题的前提，如果使用暴力的办法，if判断过多，既不全面也不方便后期阅读。
- 在此，引入两个全新的概念——**前缀和**、**双端队列**

**1.1 前缀和**
前缀和属于通过遍历的方式进行预处理的算法，非常著名的KMP算法关于next数组的计算同样可以归于预处理。
 1. 第i个元素的前缀和 = 前i-1个元素之和。
 2. 首元素没有前缀，规定为0。
```
void getPrefixSum(const vector<int> &vec, vector<int> &prefixSum) { //计算前缀和
		//首元素前缀和为0
	prefixSum.push_back(0);
	for (int i = 1; i <= vec.size(); ++i) {
		prefixSum.push_back(prefixSum[i - 1] + vec[i - 1]);
	}
}
```
 3. 关于函数设计的说明：vec是初始数组，**为了避免参数拷贝，选择引用**，但又不能在函数体内修改，额外加const修饰；prefixSum是**前缀和数组**，由调用者传入，希望修改所以使用引用。 

**1.2 双端队列**
 1. 处理j位置时，如果i-1位置的前缀和大于i位置的（i小于j），则有sum[i-1...j] < sum[i...j]，区间长度更长而区间和却更小；明白这一点，直接考虑i舍去对i-1的考虑。
 2. 使用一个变量minLength保存满足条件的区间长度，初始值为-1；遍历完成之后，结果也得到了。 
```
int shortestSubarray(vector<int>& vec, int k) {
	vector<int> prefixSum;
	getPrefixSum(vec, prefixSum); //预先计算前缀和
	deque<int> dq; dq.push_back(0); //先将下标0入队，统一处理
	int minLength = -1;
	for (int i = 1; i < prefixSum.size(); ++i) {
		while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[i]) { //维护单调双端队列
			dq.pop_back();
		}
		while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) { //找到和至少为k的序列
			if (minLength == -1) { //首次找到
				minLength = i - dq.front();
				dq.pop_front();
			}
			else { //找出最短的一次
				minLength = min(minLength, i - dq.front());
				dq.pop_front();
			}
		}
		dq.push_back(i); //入队，待选
	}
	return minLength;
}
```