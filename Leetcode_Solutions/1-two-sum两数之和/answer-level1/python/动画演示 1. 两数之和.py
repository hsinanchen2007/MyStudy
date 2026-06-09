
# 暴力法
题目要求是两个数相加，结果等于给定的某个值，那可以用两层循环来搞定。   
第一个循环将数组遍历一遍，第二个循环继续遍历这个数组，然后外层遍历到的值+内层循环遍历到的值==target，就是结果了。
注意一个细节，题目要求不能重复利用相同的值，所以这里要判断外层的下标 ！= 内层循环的下标，这种算法的时间复杂度是O(n^2)   
这题已经说明了，每种输出有一个答案，所以开头可以不用做边界判断了。   

代码实现：
```java []
class Solution {
	public int[] twoSum(int[] nums, int target) {
		int n = nums.length;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				//外层循环遍历到的值+内层循环遍历到的值==target
				//并且外层的下标不等于内层的下标
				if(i!=j && nums[i]+nums[j]==target) {
					return new int[]{i,j};
				}
			}
		}
		return new int[]{-1,-1};
	}
}
```
```python []
class Solution(object):
	"""
	:type nums: List[int]
	:type target: int
	:rtype: List[int]
	"""
	def twoSum(self, nums, target):
		n = len(nums)
		for i in xrange(n):
			for j in xrange(n):
				# 外层循环遍历到的值+内层循环遍历到的值==target
				# 并且外层的下标不等于内层的下标
				if i!=j and nums[i]+nums[j]==target:
				return [i,j]
		return [-1,-1]
```
# hash解法
我们可以利用一个hash表存储元素的值和元素的下标，hash表的key是元素的值，hash表的value是元素的下标。
我们遍历一遍数组，假设   
```
n = target-当前遍历到的值
```
如果n出现在这个hash表中，就表明已经找到答案了，n和当前遍历到的值就等于target，于是返回当前遍历到的值的下标，以及hash表中n对应的value即可。因为用到了hash所以只需要一个循环就可以了，时间复杂度为O(n)，空间复杂度也是O(n)
动态演示如下：
![两数之和gif.gif](https://pic.leetcode-cn.com/efa05c30afdf957a10bc6f44e1ed87673d9a066b177e14f83802fe5f8029a8c2-%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8Cgif.gif)

代码实现如下：
```java []
class Solution {
	public int[] twoSum(int[] nums, int target) {
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int i=0;i<nums.length;i++) {
			int n = target-nums[i];
			//如果n在map中，就表示找到了答案，map中n的value就是下标
			//返回n对应的value，以及当前循环的下标i即可
			if(map.containsKey(n)) {
				return new int[]{i,map.get(n)};
			}
			map.put(nums[i],i);
		}
		return new int[]{-1,-1};
	}
}
```
```python []
class Solution(object):
	def twoSum(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		if not nums or len(nums)==0:
			return [-1,-1]
		d = dict()
		for i,v in enumerate(nums):
			n = target-nums[i]
			# 如果n在map中，就表示找到了答案，map中n的value就是下标
			# 返回n对应的value，以及当前循环的下标i即可
			if d.has_key(n):
				return [i,d[n]]
			d[v] = i
		return [-1,-1]
```
(全文完)   
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)