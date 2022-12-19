### 解题思路

经典二分查找法。注意这里使用的是左闭右开[l,r) 的搜索范围，因此while上的判断是 l<r ，而不是 l<=r。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l<r) {
            int mid = l + (r-l)/2; // 避免越界问题
            if (nums[mid]==target) return mid;
            else if (nums[mid] < target) l=mid+1;
            else if (nums[mid] > target) r=mid; // 左闭右开[l, r)
        }

        return -1;
    }
};
```