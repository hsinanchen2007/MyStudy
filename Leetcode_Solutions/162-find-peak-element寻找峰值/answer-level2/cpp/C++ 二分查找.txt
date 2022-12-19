### 解题思路
利用二分法思路实现 O(logN)

### 代码

```cpp
/* 二分查找 O(logN) */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)  return 0;
        
        int left = 0, right = nums.size()-1;

        while(left<right){
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5764bd0342c083917fb7078cbe4f770be04f82fe1e09111166b804a6c2a6a2ed-image.png)
