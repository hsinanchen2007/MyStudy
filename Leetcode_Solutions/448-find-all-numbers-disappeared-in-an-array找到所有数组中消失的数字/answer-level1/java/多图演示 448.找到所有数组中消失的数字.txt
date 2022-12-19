
## 题解
注意题目要求```不能使用额外空间```，这也是这道题的难点所在。   
这道题里面其实包含了隐藏的条件，```1 ≤ a[i] ≤ n```，即每个数字本身都对应一个```i-1```的```数组下标```。   
我们可以利用数组内容本身跟数字下标的关联找出缺失的数字。  
扫描两遍数组，第一次将所有数字做标记，第二次根据标记信息找出缺失的数字。下面来看详细分析。   
假设有数组```[1,2,3,4,5,6]```如下图：   
![1.jpg](https://pic.leetcode-cn.com/5ec95e7e9d60d3a519ae79c98fd6ce2f0ad13f8c1dc91fb01e760d30c28c6cc3-1.jpg)

数组上方的是数组的下标，通过这张图可以发现，数组中的每个值都有一个对应的数组下标，比如```值为4的```对应```下标3```。即```arr[i]```对应```i-1```   
如果数组是乱序的呢？   
![2.jpg](https://pic.leetcode-cn.com/82cc75d84d49ab07b67526f0cca083db4a97d02689b442036c6450fafb2d135e-2.jpg)
乱序的数组并不影响，比如```值为3的```对应的是```下标2```，```值为6的```对应的是```下标5```。   
   
   
我们可以利用下标这个隐藏条件，再假设有下面数组，数组缺少```5```   
![3.jpg](https://pic.leetcode-cn.com/1ee78863331347f6a948796bce94915afeed652cbea954c5f149a08e5b7a43d9-3.jpg)
因为每个```arr[i]```都对应下标```i-1```，我们将```arr[i]```对应的下标中的数组值置为负，比如```值是3的```对应下标```2```，我们将```arr[2]```中的值设置为```arr[2]*-1```。 
对```[1,2,3,4,6,6]```这个数组我们做如下操作：   
```1=>arr[0]```，将```arr[0]```设置成```-1```   
```2=>arr[1]```，将```arr[1]```设置成```-2```   
```3=>arr[2]```，将```arr[2]```设置成```-3```   
```4=>arr[3]```，将```arr[3]```设置成```-4```   
```6=>arr[5]```，将```arr[5]```设置成```-6```   
```6=>arr[5]```，将```arr[5]```设置成```-6```
![4.jpg](https://pic.leetcode-cn.com/6ed2e80e8456d3e4c897e712c8a55e28b02984296917aafc58120ae2ba6f2a5e-4.jpg)
再扫描一遍数组，找到大于```0```的数，这里是```6```，它的数组下标是```4```，但现在```arr[4]```大于0，说明缺少数字```5```，因为```5```对应```数组下标4```。   
如果数组是乱序的，也不会影响其结果。   
![5.jpg](https://pic.leetcode-cn.com/040110ddbc37de39877e5e2d6c98d8de0958945552c1383983dbfe9af1648951-5.jpg)
扫描一遍，仍然是```下标4```大于0，即缺少数字```5```。   
如果用0作为标记呢？   
![6.jpg](https://pic.leetcode-cn.com/d9ab1b9af84e88db3c0b1c8c49c96a84f06a8349672e7606ca9889f16a93037a-6.jpg)
这样是不行的，```arr[0]=>2```，即将```arr[1]```设置成了```0```，这样就等于把已有的信息给覆盖了。
   
   
再看下题目中的列子，数组```[4,3,2,7,8,2,3,1]```   
![7.jpg](https://pic.leetcode-cn.com/d2deb47233dc613dcdf821b81935ad95002a7a44c61471304e58edafcfcd66b5-7.jpg)
经过转换得到新数组```[-4, -3, -2, -7, 8, 2, -3, -1]```   
扫描一遍```8```和```2```大于0，他们分别对应```下标4```和```下标5```，所以缺失的数字是```5```和```6```。   
   
复杂度分析      
时间复杂度:O(n)，扫描两边数组   
空间复杂度:O(1)   
   
代码实现:   
```java []
class Solution {
	public List<Integer> findDisappearedNumbers(int[] nums) {
		List<Integer> res = new ArrayList<Integer>();
		//第一遍扫描，根据数组的值找到对应的下标，比如3对应下标2
		//将arr[2]设置成负数
		for(int i=0;i<nums.length;++i) {
			int index = Math.abs(nums[i])-1;
			if(nums[index]>0) {
				nums[index] *= -1;
			}
		}
		//第二遍扫描，找到所有非负数，非负数所在的下标+1，即为缺失的数字
		for(int i=1;i<=nums.length;++i) {
			if(nums[i-1]>0) {
				res.add(i);
			}
		}
		return res;
	}
}
```
```python []
```python
class Solution(object):
	def findDisappearedNumbers(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		res = []
		# 第一遍扫描，根据数组的值找到对应的下标，比如3对应下标2
		# 将arr[2]设置成负数
		for i in nums:
			index = abs(i)-1
			if nums[index]>0:
				nums[index] *= -1
		# 第二遍扫描，找到所有非负数，非负数所在的下标+1，即为缺失的数字
		for i in xrange(len(nums)):
			if nums[i]>0:
				res.append(i+1)
		return res
```
   
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)


















