

## 题解
求容器能够容纳水的最大值，其实就是求矩形的最大面积。   
![2.jpg](https://pic.leetcode-cn.com/701c36367b56d7ea199827b585f1a62e03f07d8baa19ff9d1d36991a764f93eb-2.jpg)
我们定义两个指针(指向上图中红色的柱子)来代表两个柱子，然后这两个指针都向中间移动，每次移动的时候都计算一下当前的面积，并保存下来，等到两个指针相遇时(即两个指针都指向同一个柱子时)，当遍历结束后完，就可以求的最大的矩形面积。   
怎么计算矩形面积呢？   
比如这个数组：   
```[1,8,6,2,5,4,8,3,7]```   
下标```1```的值是```8```，下标```8```的值是```7```。通过值和下标这两个维度就可以计算矩形了。   
将右边下标```-```左边下标，就能得出矩形的长度，然后再计算 ```max(```下标```1```的值和下标```8```的值```)``` 得到高度，有了长度和高度就可以得出面积了。   
![3.gif](https://pic.leetcode-cn.com/d74840a00670d7ed0a648aa4a44642e6e48adfe53a9dfa2309328d7a96a24bee-3.gif)


时间复杂度：O(n)   
空间复杂度：O(1)   

代码实现:
```java []
class Solution {
	public int maxArea(int[] height) {
		if(height==null) {
			return 0;
		}
		//定义两个指针，分为位于最左边和最右边
		int i = 0;
		int j = height.length-1;
		int res = 0;
		//两个指针不断像中间移动，每迭代一次都会计算矩形的最大面积
		while(i<j) {
			int tmp = Math.min(height[i],height[j]);
			res = Math.max(res,tmp*(j-i));
			if(height[i]<=height[j]) {
				++i;
			} else {
				--j;
			}
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def maxArea(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		if not height:
			return 0
		# 定义两个指针，分为位于最左边和最右边	
		i = 0
		j = len(height)-1
		res = 0
		# 两个指针不断像中间移动，每迭代一次都会计算矩形的最大面积
		while i<j:
			tmp = min(height[i],height[j])
			res = max(res,tmp*(j-i))
			if height[i]<=height[j]:
				i += 1
			else:
				j -= 1
		return res
```
(全文完)

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)


