### 解题思路
这道题和剑指offer11题找旋转数组中最小数字类似。但是难度有提升。主要还是用到二分查找
若nums[mid]==target,返回mid
若nums[0]<=nums[mid]证明mid之前是有序的。
··若nums[0]<=target<nums[mid]区间变换到[0,mid-1]
··否则区间变换为[mid+1,end]
若nums[0]>nums[mid]证明mid之后是有序的。
··若nums[mid]<target<=nums[end]区间变换到[mid+1,end]
··否则区间变换为[0,mid-1]



第二个异或的方法太牛了。。  三个中两个为1。结果为0.一个为1，结果为1
(nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])  有点不太懂啊。。。
解题里说的是
nums[0] <= target <= nums[mid]
           target <= nums[mid] <= nums[0]
                     nums[mid] <= nums[0] <= target
区间在前面、



执行用时 :4 ms, 在所有 C++ 提交中击败了88.39% 的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)>>1;
            if(nums[mid]==target)
                return mid;
            if(nums[start]<=nums[mid]){
                if(nums[start]<=target&&target<nums[mid])
                    end=mid-1;
                else
                    start = mid+1;
            }
            else{
                if(nums[mid]<target&&target<=nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }   
};
```