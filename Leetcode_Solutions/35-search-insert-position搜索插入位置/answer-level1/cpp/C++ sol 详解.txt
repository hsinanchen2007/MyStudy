### 解题思路

执行用时 :4 ms, 在所有 C++ 提交中击败了96.02%的用户
内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户

//
1. 二分搜索就能解决所有问题，但要注意边界。在下面的代码中控制的边界是左闭右开，即[l,r)-> [l, mid), [mid+1, r), 其中 r = nums.size()
2. 由上分析可得 while (l<r)，而不是 while(l<=r)。这里要特别注意，以免遗漏搜索的数。
3. 当mid被找到时，返回mid。否则等while结束，l就是target需要插入的位置。返回它。

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = static_cast<int>(nums.size());
        while (l<r) {
            int mid = l + (r-l)/2; // 避免l+r溢出的问题
            if (nums[mid]==target) return mid;
            else if (nums[mid] < target) l=mid+1;
            else if (nums[mid] > target) r=mid;
        }

        return l;
    }
};
```