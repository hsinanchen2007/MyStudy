### 解题思路
1.方法基于二分法搜索。
2.考虑到二分之后肯定有一部分是有序的，有意部分是乱序的，我们就将情况分为左边有序和右边有序两种情况。
3.nums[mid] >= nums[l]左边有序，nums[mid+1] <= nums[r]右边有序，两点为同一个点也视为有序。
4.并且每种情况里再讨论答案是否在有序区间里的情形：
（1）如果答案在有序区间，继续递归该区间，继续正常二分搜索，
（2）如果答案不在有序区间，则递归无序区间，希望通过不断二分，在一个分出来的有序区间里找到答案。
注意：
（1）**判断左右区间以及搜索左右时，分为left与mid，mid+1，两区间不能重合**，否则对一些情况会找不到答案，例如，只有两个点时，答案在右边，此时left区间没有答案，但mid与left又是同一个点，搜索对半区间时，仍然搜索的是mid=left到right，死循环。
（2）对与left与mid，mid+1与right两两坐标比较值的**大小关系来判断有序与否时，一定要取等号**，因为，这两个点分到最后可能是同一个点，也会出现长度为2即左右区间都是单点的情况，不取等判断出来两边都无序，不符合事实。并且根据除法往0取整，left也有等于mid的情况。
（3）限定条件时一定要足够严密，有序且有答案，有序无答案，判断条件写全。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)return -1;
        return find(nums,target,0,len-1);

    }
    int find(vector<int>& nums, int target,int l, int r){
        if(l==r && nums[l] != target)return -1;
        
        int mid = (l+r)/2 ;
        if ( nums[mid] == target) return mid;
        
        else {
            if ( nums[mid] >= nums[l] && target < nums[mid] && target >= nums[l]){//left sorted and ans in left part
                return find(nums,target,l,mid);
            }
            else if ( nums[mid] >= nums[l]) return find(nums,target,mid+1,r);
            
            if ( nums[mid+1] <= nums[r] && target > nums[mid] && target <= nums[r]){//right sorted and ans in right part
                return find(nums,target,mid+1,r);
            }
            else if (nums[mid+1] <= nums[r]) return find(nums,target,l,mid);
            
        }
        return -1;
    }
};
```