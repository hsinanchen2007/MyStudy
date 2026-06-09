  
## 题解
一般来说在```排序数组```中查找某个元素，那首先想到的就是用```二分查找```，这道题也是用了```二分查找```解决的，但它跟正常的二分查找在细节上有些不同，我们在正常的二分查找基础上稍作修改就可以解决这道题了。   
```二分查找```的思路很简单，但是具体实现的时候，一不小心可能就会出错。   
   
下面我们先看看如何实现一个正确的```二分查找```。   
假设有```[1,2,3,4,5,6,7,8,9,10,11]```这个数组，求目标值```targeet=2```在数组中的下标，target指向的是绿色的格子，```begin=0```落在数组左边界上，```end=len(arr)-1```落在数组右边界上，具体查找过程如下图所示:   
![1.jpg](https://pic.leetcode-cn.com/d8dc1d5612a2cfb8718f9e0c65e3d14f565359ca64d4e6ebfa40df259be8ca71-1.jpg)


首先求出中间下标```mid```，判断```arr[mid]```是大于、等于、还是小于```target```，然后再决定是往数组左半边查找，还是右半边查找，其过程如下：      
1. ```mid=5```，```arr[mid]>target```，减小右边界end
2. ```mid=2```，```arr[mid]>target```，继续减小右边界end
3. ```mid=0```，```arr[mid]<target```，增加左边界begin
4. ```mid=1```,```arr[mid]==target```，返回

二分查找的开头循环判断是:
```while begin<=end```   
这里的循环判断终止条件是一个容易出错的地方。从上图中第四行可以看出，```begin```，```mid```，```end```三个变量都指向了下标```1```，如果循环的终止条件写成了```while begin<end```，那么上述的判断就不对了，程序也就没法返回正确值了。   
   
目标值```taget=10```，即出现出数组右侧，其处理过程也是类似的。
![2.jpg](https://pic.leetcode-cn.com/a4a5c4ccfaf7d84b2fadf9154ac135a2c1619b40517fa2210a6811589c8ef200-2.jpg)
1. ```mid=5```，```arr[mid]<target```，增加左边界begin
2. ```mid=8```，```arr[mid]<target```，继续增加左边界begin
3. ```mid=9```，```add[mid]==target```，返回

为什么往数组左边寻找的时候要```end=mid-1```呢？可以写成```end=mid```这样可以吗？   
请看下面这个例子:   
```arr=[1,3,5,7]```，```target=2```。   
这样的话，结果应该是返回-1，我们看下执行流程:   
1. ```begin=0,end=3, mid=1```，```arr[mid]>target```
2. ```end=mid```
3. ```begin=0,end=1,mid=0```，```arr[mid]<target```
4. ```begin=mid```
5. ```begin=1,end=1,mid=1``` 死循环....
  
确定了循环的终止条件，以及如何往左/往右查找，还有一个小细节需要说明下，一般我们取中间值，是这么写
```mid = (begin+end)/2```   
当```begin```和```end```都很大时其结果可能会溢出，所以可以改成这样:   
```mid = begin+(end-begin)/2```   
   
到这里我们就可以写出一个二分查找的模板了   
```python
def binarySearch(nums, target):
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
			return mid
	return -1
```
   
当数组中包含了```target```，上述的代码执行正确，但如果```target```不在数组中呢？   
很简单，等循环退出后，返回begin就可以了:   
![3.gif](https://pic.leetcode-cn.com/a9a4b4aa1a98d05cdb8f3267336a2e7fadc84b3d2cfb7f25ed8462e27f40010f-3.gif)
上图中，要查找的值是```7```，它不在数组中，于是```begin```和```end```会不断逼近最终值，不会指向```6```因为小了，也不会指向```9```因为大了，最终会落到```8```上。   
这也很好理解，假设有数组```[1,2,3....,i-1,i+1,i+2,...]```我们要查找的值是```i```，```mid```指向```i-1```时，比```i```小，所以继续往数组右边找，当找到```i+1```时，又比```i```大，于是再往数组左边找，这时触发了循环终止条件```while begin<=end```。   
循环退出后，```begin```就指向了```i+1```的位置，而```i+1```正是我们要找到的位置(将```i```放到```i+1```的位置，然后```i+1```和后面的元素都往右挪一位，整个数组又有序了)，所以返回begin即可。   
   
   
代码实现:
```java []
class Solution {
	public int searchInsert(int[] nums, int target) {
		if(nums==null) {
			return -1;
		}
		int begin = 0;
		int end = nums.length-1;
		while(begin<=end) {
			int mid = begin+(end-begin)/2;
			if(nums[mid]>target) {
				end = mid-1;
			}
			else if(nums[mid]<target) {
				begin = mid+1;
			}
			else {
				return mid;
			}
		}
		return begin;
	}
}
```
```python []
class Solution(object):
	def searchInsert(self, nums, target):
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
				return mid
		return begin
```
(全文完)

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)
