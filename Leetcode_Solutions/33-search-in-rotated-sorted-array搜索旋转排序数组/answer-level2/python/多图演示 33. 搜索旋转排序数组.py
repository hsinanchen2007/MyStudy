


## 解法一
数组```[0,1,2,4,5,6,7]```，经过了旋转，可能会变成下面这样:   
![1.jpg](https://pic.leetcode-cn.com/97ede0e95e2a1c42f3d6cf2d8ab9679ea244ad6311062219be406d04cf751e32-1.jpg)
上图中除了第四个数组没变动，其他三个数组都有这么一个特点:   
> 存在某个下标```i```，使得```num[i]```大于```nums[i+1]```。  

因为输入的是升序的，正常来说```nums[i+1]```应当是大于```num[i]```，现在反而是小于，说明找到了旋转点。```num[i+1]```就是数组中最小的元素。   
   
找到数组中的最小值有什么用呢？我们看下面这个数组   
![2.jpg](https://pic.leetcode-cn.com/90a8b6bb8d8b03b7cc1440362ba90795690dcb7621b98a88d1c6ed803dfa53d0-2.jpg)

蓝色部分的```4,5,6,7```是升序的，绿色部分的```0,1,2,3```也是升序的。最小值```0```将整个数组分成两段，而这两段都是升序的。       
如果**蓝色部分最小值**<=target<=**蓝色部分最大值**，那么结果肯定是在蓝色部分，又因为这部分是升序的，所以用正常的二分查找就可以找target了。   
同理，如果**绿色部分最小值**<=target<=**绿色部分最大值**，那就用二分查找在绿色部分进行查找。
   
现在问题就转换为如何找到数组中的最小值了，如果找到了```最小值```，接着再用正常的二分查找就可以搞定了。   
下面我们来看看如何查找最小值。   
我们仍然用二分查找的思路，假设中间点```nums[mid]```>=```num[0]```，那么可以推断出[```nums[0]```,```nums[mid]```] 这段是升序的，它不满足我们之前说的旋转点条件```nums[i]```>```nums[i+1]```，说明最小值肯定是在```mid```下标的右侧。   
![3.jpg](https://pic.leetcode-cn.com/136c422a669594fc2d241be29ef5ab94cd4817e8f966525a260c512cb5c45686-3.jpg)


如果是下面这种情况，```nums[mid]```<```nums[0]```，说明[```nums[0]```，```nums[mid]```]这段不是有序的，那么我们要找的最小值就包含在[```nums[0]```，```nums[mid]```]之间。   
![4.jpg](https://pic.leetcode-cn.com/09d7d7ff098140361db4d6012d1fda2ba3d5b7775673a824a4c5718dc701132a-4.jpg)

按照上述分析，查找最小值的过程如下:
> 1. nums[0]<=nums[max]说明整个数组是有序的，下标```0```就是最小值
> 2. 如果```num[i]```>```nums[i+1]```，不满足升序，说明```mid+1```就是最小值，退出查找
> 3. 如果中间值```numd[mid]```>=```nums[0]```说明数组左边是有序的，最小值应该在右边
> 3. 如果中间值```nums[mid]```<```nums[0]```说明数组左边是无序的，最小值应该在数组左边   

动画演示:
![5.gif](https://pic.leetcode-cn.com/8084cdb1fe27e4e0e91d86d5d84a5897826f631e1d8c52bc4def03bf32189a68-5.gif)

代码实现:
```java []
class Solution {
	public int search(int[] nums, int target) {
		if(nums==null || nums.length==0) {
			return -1;
		}
		//查找最小值的下标
		int minIndex = findMin(nums);
		//如果最小值下标为0，说明整个数组是有序的
		if(minIndex==0) {
			return binarySearch(nums,0,nums.length-1,target);
		}
		//最终结果在[0,min_index-1]中
		if(nums[0]<=target) {
			return binarySearch(nums,0,minIndex,target);
		}
		//最终结果在[min_index-1,length-1]中
		return binarySearch(nums,minIndex,nums.length-1,target);
	}
	
	//正常的二分查找
	private int binarySearch(int[] nums,int begin,int end,int target) {
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
		return -1;
	}
	
	//查找最小值的下标
	private int findMin(int[] nums) {
		int begin = 0;
		int end = nums.length-1;
		//如果第一个值比最后一个值小，说明整个数组是有序的
		if(nums[begin]<=nums[end]) {
			return begin;
		}
		while(begin<=end) {
			int mid = begin+(end-begin)/2;
			//前一个值比后一个值大，找到了旋转点
			if(mid<nums.length-1 && nums[mid]>nums[mid+1]) {
				return mid+1;
			}
			//中间点大于等于第一个元素，左半边是有序的，转去右边查找
			if(nums[mid]>=nums[0]) {
				begin = mid+1;
			//左边是无序的，继续在左边查找	
			} else {
				end = mid-1;
			}
		}
		return 0;
	}
}
```
```python []
class Solution(object):
	def search(self, nums, target):
		if not nums:
			return -1
		n = len(nums)
		# 查找最小值的下标
		def findMin():
			begin = 0
			end = n-1
			# 如果第一个值比最后一个值小，说明整个数组是有序的
			if nums[begin]<=nums[end]:
				return begin
			while begin<=end:
				mid = begin+(end-begin)//2
				# 前一个值比后一个值大，找到了旋转点
				if mid<n-1 and nums[mid]>nums[mid+1]:
					return mid+1
				# 中间点大于等于第一个元素，左半边是有序的，转去右边查找	
				if nums[0]<=nums[mid]:
					begin = mid+1
				# 左边是无序的，继续在左边查找		
				else:
					end = mid-1
			return 0
		# 正常的二分查找	
		def binarySearch(begin,end):
			while begin<=end:
				mid = begin+(end-begin)//2
				if nums[mid]>target:
					end = mid-1
				elif nums[mid]<target:
					begin = mid+1
				else:
					return mid
			return -1
		# 查找最小值的下标	
		minIndex = findMin()
		# 如果最小值下标为0，说明整个数组是有序的
		if minIndex==0:
			return binarySearch(0,n-1)
		# 最终结果在[0,min_index-1]中	
		if nums[0]<=target:
			return binarySearch(0,minIndex-1)
		# 最终结果在[min_index-1,length-1]中	
		return binarySearch(minIndex,n-1)
```




## 解法二
假设以```mid```位中间点，可以看到无论```mid```落在哪里，肯定有一边是有序的。因为某一边肯定是有序的，我们利用```有序```这个条件，就可以判断出```target```落在哪一边。          
![6.jpg](https://pic.leetcode-cn.com/d0bceb971153de87845131521dcbf9f0f8940e86b9991dd0cb3102f96caed220-6.jpg)

假设我们已经确定了```mid```的下标位置，目标值```target```所在的位置可能有如下几种情况。   
第一种(见下图)很简单，```mid```指向的值正好就等于```target```，直接返回即可   
![7.jpg](https://pic.leetcode-cn.com/9f573b35268382a155bd304976ce91a810dd07dff1b611aedafd510c27b329dc-7.jpg)

---

第二种情况(见下图)，如果```mid```左侧是有序的，那么```target```要么落在```mid```的左侧，要么落在```mid```的右侧。   
如果是落在左侧，那么一定满足```arr[begin]<=target<=arr[mid]```，继续往左边搜索。   
如果是落在无序的右侧，那么一定**不**满足```arr[begin]<=target<=arr[mid]```这个条件，继续往右侧搜索。   
![8.jpg](https://pic.leetcode-cn.com/5a9c8efc1ab922a71f66c3c344d7d31481f8b23a251c783a507d40f39aa3be7a-8.jpg)

---

第三种情况(见下图)，```mid```的左侧是无序的，那么右侧肯定是有序的。   
如果```target```落在右侧，那么一定满足```nums[mid]<target<=nums[end]```，继续往右搜索。   
如果落在无序的左侧，那么那么一定**不**满足```nums[mid]<target<=nums[end]```  继续往左搜索。     
![9.jpg](https://pic.leetcode-cn.com/328a1125513b3fd724c7b292273b40f5a658946716309d70e0b396ba656d4c3e-9.jpg)

按照上述分析，可以总结出查找过程如下:
> 1. 如果```nums[mid]==target```，找到目标值直接返回
> 2. 如果```mid```左侧是有序的且```nums[begin]<=target<=nums[mid]```，那么目标值在```mid```左侧
> 3. 如果```mid```左侧是有序的且```taget```不在```[nums[begin],nums[mid]]```范围内，那么目标值在```mid```右侧
> 4. 如果```mid```右侧是有序的且```nums[mid]<target<=nums[end]```，那么目标值在```mid```右侧
> 5. 如果```mid```右侧是有序的且```target```不在```(nums[mid],nums[end]]```，那么目标值在```mid```左侧。   
   
   
代码实现:
```java []
class Solution {
    public int search(int[] nums, int target) {
        if(nums==null || nums.length==0) {
            return -1;
        }
        int begin = 0;
        int end = nums.length-1;
        while(begin<=end) {
            int mid = begin+(end-begin)/2;
            //找到目标值了直接返回
            if(nums[mid]==target) {
                return mid;
            }
            //如果左侧是有序的
            if(nums[begin]<=nums[mid]) {
                //同时target在[ nums[begin],nums[mid] ]中，那么就在这段有序区间查找
                if(nums[begin]<=target && target<=nums[mid]) {
                    end = mid-1;
                //否则去反方向查找	
                } else {
                    begin = mid+1;
                }
            }
            //如果右侧是有序的
            else {
                //同时target在 ( nums[mid],nums[end] ]中，那么就在这段有序区间查找
                if(nums[mid]<target && target<=nums[end]) {
                    begin = mid+1;
                //否则去反方向查找	
                } else {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
}
```
```python []
class Solution(object):
    def search(self, nums, target):
        if not nums:
            return -1
        begin = 0
        end = len(nums)-1
        while begin<=end:
            mid = begin+(end-begin)//2
            # 找到目标值了直接返回
            if nums[mid]==target:
                return mid
            # 如果左侧是有序的	
            if nums[begin]<=nums[mid]:
                # 同时target在[ nums[begin],nums[mid] ]中
                # 那么就在这段有序区间查找
                if nums[begin]<=target<=nums[mid]:
                    end = mid-1
                # 否则去反方向查找	
                else:
                    begin = mid+1
            # 如果右侧是有序的		
            else:
                # 同时target在 ( nums[mid],nums[end] ]中
                # 那么就在这段有序区间查找
                if nums[mid]<target<=nums[end]:
                    begin = mid+1
                # 否则去反方向查找	
                else:
                    end = mid-1
        return -1
```




## 解法二变形
代码和解法二几乎是一样的，只在循环中的判断稍稍不同。   
其查找过程如下:
> 1. 如果```nums[mid]==target```，找到目标值直接返回
> 2. 如果```mid```右侧是有序的且```nums[mid]<=target<=nums[end]```，那么目标值在```mid```右侧
> 3. 如果```mid```右侧是有序的且```taget```不在```[nums[mid],nums[end]]```范围内，那么目标值在```mid```左侧
> 4. 如果```mid```左侧是有序的且```nums[begin]<target<nums[mid]```，那么目标值在```mid```左侧
> 5. 如果```mid```左侧是有序的且```target```不在```[nums[begin],nums[mid])```，那么目标值在```mid```右侧。   
   



java代码:
```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums==null || nums.length==0) {
            return -1;
        }
        int begin = 0;
        int end = nums.length-1;
        while(begin<=end) {
            int mid = begin+(end-begin)/2;
            if(nums[mid]==target) {
                return mid;
            }
            if(nums[mid]<=nums[end]) {
                if(nums[mid]<=target && target<=nums[end]) {
                    begin = mid+1;
                } else {
                    end = mid-1;
                }
            }
            else {
                if(nums[begin]<=target && target<nums[mid]) {
                    end = mid-1;
                } else {
                    begin = mid+1;
                }
            }	
        }
        return -1;
    }
}	
```

python代码:
```python
class Solution(object):
    def search(self, nums, target):
        if not nums:
            return -1
        begin = 0
        end = len(nums)-1
        while begin<=end:
            mid = begin+(end-begin)//2
            if nums[mid]==target:
                return mid
            if nums[mid]<=nums[end]:
                if nums[mid]<=target<=nums[mid]:
                    begin = mid+1
                else:
                    end = mid-1
            else:
                if nums[begin]<=target<nums[mid]:
                    end = mid-1
                else:
                    begin = mid+1
        return -1
```
(全文完)
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)









