### 分析

本题是一个典型的二分查找类题目。题目的意思很明确，就是寻找左边界和右边界。
二分查找看似很简单，其实里面的变化还是蛮多的。
如何寻找左边界呢？
1.1如果nums[mid] < target，那么左边没有target。start = mid+1，
1.2如果nums[mid]==target，在正常的二分查找中，这种情况是可以直接返回结果。但是因为我们是要查找左边界，这就有可能mid的左边还有可能有target这个数。因此需要进行两步操作。
   1.2.1 用一个变量res标记mid的值，如果左边还有数值等于target，则更新res的值。否则直接返回res即可。
   1.2.2 end = mid - 1，继续向左查找。
1.3 如果nums[mid] > target, 同1.2.2 end = mid - 1，继续向左查找。

如何寻找右边界呢？
2.1如果nums[mid] > target，那么右边没有target。end = mid - 1，
2.2如果nums[mid]==target，在正常的二分查找中，这种情况是可以直接返回结果。但是因为我们是要查找右边界，这就有可能mid的右边还有可能有target这个数。因此需要进行两步操作。
   2.2.1 用一个变量res标记mid的值，如果左边还有数值等于target，则更新res的值。否则直接返回res即可。
   2.2.2 start = mid + 1，继续向右查找。
2.3 如果nums[mid] < target, 同1.2.2 start = mid + 1，继续向右查找。
其实说白了，找target，找target的左边界或者找target的右边界仅仅是在nums[mid]==target的处理上有差别。

### 代码
python 版本
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) == 0:
            return [-1, -1]
        left, right = -1, -1

        # left bounder
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = start + ((end - start) >> 1)
            if target <= nums[mid]:
                end = mid
            else:
                start = mid
        if target == nums[end]:
            left = end
        if target == nums[start]:
            left = start
        
        # right bounder
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = start + ((end - start) >> 1)
            if target >= nums[mid]:
                start = mid
            else:
                end = mid
        if target == nums[start]:
            right = start
        if target == nums[end]:
            right = end
        
        return [left, right]


```
java 版本
```
public int[] searchRange(int[] nums, int target) {
        assert nums!= null;
        if(nums.length == 0){
            return new int[]{-1,-1};
        }
        int[] res = new int[]{findLeft(nums, target),findRight(nums, target)};
        return res;
    }


    private int findLeft(int[] nums, int target){
        int len = nums.length;
        int res = -1;
        int start = 0;
        int end = len - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }
             else {
                if(nums[mid] == target){
                    res = mid;
                }
                end = mid - 1;
            }
        }

        return res;

    }

    private int findRight(int[] nums, int target){
        int len = nums.length;
        int res = -1;
        int start = 0;
        int end = len - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target){
                end = mid - 1;
            }
            else {
                if(nums[mid] == target){
                    res = mid;
                }
                start = mid + 1;

            }
        }

        return res;

    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)