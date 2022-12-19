### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)>>1;
            if(nums[mid]==target) return mid;
            // mid 在左侧
            if(nums[mid] >= nums[i]){
                if(target >= nums[mid]) i=mid+1;
                else if (target < nums[mid] && target >= nums[i])
                    j = mid-1;
                else
                    i = mid+1;
            }else{
                if(target > nums[mid] && target < nums[0]) i = mid+1;
                else  j = mid-1;
            }
        }
        return -1;
    }
};
```

```
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        i, j = 0, len(nums)-1
        while(i<=j):
            mid = (i+j)/2
            if (target==nums[mid]):
                return mid;
            if nums[mid] >= nums[i]:
                if target >= nums[i] and target < nums[mid]:
                    j = mid - 1
                else:
                    i = mid + 1
            else:
                if target > nums[mid] and target < nums[0]:
                    i = mid + 1
                else:
                    j = mid - 1
        return -1
```
