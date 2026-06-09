## 题解
如果修改下题目要求，不要求返回```给定值```的第一个、最后一个，只要等于给定的值就返回，那会变成什么样呢？   
假设给定的数组如下图所示，给定的值是```3```，求下标。   
![1.jpg](https://pic.leetcode-cn.com/eb7a378006651dc035fec11b2a693d71b6f7b27cfa83b1f93641d9f75e62c767-1.jpg)
上图的数组中下标```2```，```3```，```4```，```5```，```6```都满足要求，返回任意一个都可以了。   
这个查找过程就是正常的二分查找:   
```python
def binary_search(nums):
	if not nums:
		return -1
	begin = 0
	end = len(nums)-1
	while begin<=end:
		mid = begin+(end-begin)/2
		if nums[mid]>target:
			end = mid-1
		elif nums[mid]<target:
			begin = mid+1
		else:
			return mid
	return -1
```
如果对二分查找没有印象了，可以参考[这篇文章](https://leetcode-cn.com/problems/search-insert-position/solution/dong-hua-yan-shi-35-sou-suo-cha-ru-wei-zhi-by-wang/)回忆一下。    
现在我们再把题目的要求加上，已经定位到```3```这个元素了，如果求得```第一个```3和```最后一个```3出现的位置呢？   
如果直接挨个向前移动查找，或者挨个向后移动查找是不行的。   
![2.jpg](https://pic.leetcode-cn.com/b82362148dfbae94b60d5dcc42117893f01500f236d854ff15b3dfcda128eccd-2.jpg)
题目要求了时间复杂度是O(logN)，挨个查找的话，时间复杂度就变成O(N)了，而且这么查找的话，跟从头到尾扫描一遍也没区别，那么就必须要用更高的效率去找到第一个和最后一个元素。     
   
到这里，我们就有一个大致的脉络了
1. 首先用正常的二分查找定位到给定的元素，时间复杂度O(logN)   
2. 在定位到指定元素的情况下，用O(logN)时间复杂度查找第一个/最后一个
   
第一点题我们已经解决了，现在看看如何解决第二点。   
怎么样才算找到```第一个```目标值呢？
![3.jpg](https://pic.leetcode-cn.com/5c84d0dbe2d32e1a8fbba5791465c94541a4e43b815f5ef8fc6a501533e06321-3.jpg)
很简单，当```nums[i]```大于```nums[i-1]```时。      
但还有一个特殊情况，```nums[i]```的下标为```0```时，这也很好理解，前面都没元素了，那当前元素肯定就是第一个了。   
![4.jpg](https://pic.leetcode-cn.com/dd959374d05321bde4cccc9bc824eae093c2f789162c0d1ec425c0abb59f4d1b-4.jpg)

   
对于最后一个元素也是类似的
![5.jpg](https://pic.leetcode-cn.com/700e945f783a40cc5a949cb05e2a9858399a139f546bc2f49eb29cc175467388-5.jpg)

如果```nums[i]```小于```nums[i+1]```就算找到了，或者```nums[i]```是数组的最后一个元素时。      
   
至此，我们就实现了完整的查找逻辑了   
```python
def binary_search(nums):
	if not nums:
		return -1
	begin = 0
	end = len(nums)-1
	while begin<=end:
		mid = begin+(end-begin)//2
		if nums[mid]>target:
			end = mid-1
		elif nums[mid]<target:
			begin = mid+1
		else:
			# 找到目标值了，开始查找第一个目标值
			if mid>0 and nums[mid]==nums[mid-1]:
				end = mid-1
			else:
				return mid
	return -1
```
详细说明下上面代码中```else```中的这段:
```python
if mid>0 and nums[mid]==nums[mid-1]:
	end = mid-1
else:
	return mid
```
既然找到了目标值，就将当前值和前一个值对比，如果一样说明没找到，那么就需要缩小右边界。   
缩小右边界的原因是我们要找```第一个```，第一个肯定是在最左边，所以就要缩小右边界。  
   
下面演示查找```第一个```目标值的过程:   
![6.gif](https://pic.leetcode-cn.com/7ab0d8cc7f35b1821c9b989c31aa960a619cc9705384235dafa91e3b41610609-6.gif)

接着是查找```最后一个```目标值的过程:   
![7.gif](https://pic.leetcode-cn.com/c284ab37f1e2c2b783765b785eb06eeb0b0b625eccd09ec327142a743f6b0198-7.gif)

   
代码实现:
```java []
class Solution {
	public int[] searchRange(int[] nums, int target) {
		if(nums==null) {
			return new int[]{-1,-1};
		}
		int firstIndex = find(true,nums,target);
		int lastIndex = find(false,nums,target);
		return new int[]{firstIndex,lastIndex};
	}
	
	//查找第一个和最后一个元素
	private int find(boolean isFindFirst,int[] nums,int target) {
		int begin = 0;
		int end = nums.length-1;
		//if和else if的逻辑跟正常的二分查找一样
		while(begin<=end) {
			int mid = begin+(end-begin)/2;
			if(nums[mid]>target) {
				end = mid-1;
			}
			else if(nums[mid]<target) {
				begin = mid+1;
			}
			//找到目标值了，开始定位到第一个和最后一个位置
			else {
				//查找第一个和最后一个逻辑很类似，这里用一个变量标记
				//是查找第一个还是查找最后一个
				if(isFindFirst) {
					//如果不满足条件，缩小右边界，继续往左边查找
					if(mid>0 && nums[mid]==nums[mid-1]) {
						end = mid-1;
					} else {
						return mid;
					}
				}
				else {
					//如果不满足条件，增大左边界，继续往右边查找
					if(mid<nums.length-1 && nums[mid]==nums[mid+1]) {
						begin = mid+1;
					} else {
						return mid;
					}
				}
			}
		}
		return -1;
	}
}
```
```python []
class Solution(object):
	def searchRange(self, nums, target):
		if not nums:
			return [-1,-1]
		n = len(nums)
		# 查找第一个和最后一个元素
		def find(is_find_first):
			begin = 0
			end = n-1
			# if和elif的逻辑跟正常的二分查找一样
			while begin<=end:
				mid = begin+(end-begin)//2
				if nums[mid]>target:
					end = mid-1
				elif nums[mid]<target:
					begin = mid+1
				# 找到目标值了，开始定位到第一个和最后一个位置	
				else:
					# 查找第一个和最后一个逻辑很类似，这里用一个变量标记
					# 是查找第一个还是查找最后一个
					if is_find_first:
						# 如果不满足条件，缩小右边界，继续往左边查找
						if mid>0 and nums[mid]==nums[mid-1]:
							end = mid-1
						else:
							return mid
					else:
						# 如果不满足条件，增大左边界，继续往右边查找
						if mid<n-1 and nums[mid]==nums[mid+1]:
							begin = mid+1
						else:
							return mid
			return -1
		return [find(True), find(False)]
```
(全文完)
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)