## 题解
乍一看似乎非常简单，用一个set或者map存储一下数组中的元素，然后过滤一下就可以了。   
但再细看一下题目要求，加了一个限制不能使用额外的空间，也就是空间复杂度必须是O(1)的。   
我们再仔细读一下题目：   
给定一个非空整数数组，**除了某个元素只出现一次以外，其余每个元素均出现两次**。找出那个只出现了一次的元素。   
题目中有一个隐藏的信息，只有一个元素出现了一次，其他元素都出现了两次，注意，这里没有说其他元素出现了3次，8次，12次，偏偏之说了出现了2次，这个就是关键点。   
解决这题的关键是 异或(XOR)：
```
1^1=0 
0^0=0 
1^0=1 
0^1=1
```
这里的0,1是一个bit的意思，也就是说这两个比特位相同，异或的结果就是0，如果不同就是1。      
假设a是123，b是123，
来看一个例子 1^2=3：   
```
1的二进制是0000 0001
2的二进制是0000 0010
(0000 0001) ^ (0000 0010) = (0000 0011)
0001
0010
----
0011
```
异或操作还有如下特点：   
1. a^a = 0
2. 0^a = a
3. a^b^a = (a^a)^b = 0^b = b

根据上述特点，只需要遍历一遍数组，挨个将元素做异或操作，最终得到的结果就是 那个只出现了一次的数字。   
 
![动画.gif](https://pic.leetcode-cn.com/335df7b220826b73503777956c2c612caa085235d25bf5b661cceee9810bfd64-%E5%8A%A8%E7%94%BB.gif)

java代码实现：
```java
class Solution {
	public int singleNumber(int[] nums) {
		int n = 0;
		//遍历数组，对数组中的每个元素进行 异或运算
		for(int i:nums) {
			n ^= i;
		}
		//最终的n就是出现了一次的元素
		return n;
	}
}
```
python代码实现：
```python
class Solution(object):
	def singleNumber(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		number=0
		# 遍历数组，对数组中的每个元素进行 异或运算
		for i in range(len(nums)):
			number ^= nums[i]
		# 最终的number就是出现了一次的元素	
		return number
```
(全文完)
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)