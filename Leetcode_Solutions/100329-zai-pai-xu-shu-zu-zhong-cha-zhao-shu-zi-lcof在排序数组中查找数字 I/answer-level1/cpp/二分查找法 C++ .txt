### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int left = 0, right = n-1, mid;
        int x;
        int y;
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid+1;
        }
        if(nums[left] != target) return 0;
        x = left;
        right = n;
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        y = left;
        return y-x;
    }
};
//二分查找法
//具体的mid取法需要实践获得，尝试几组数据，要注意2个数据可能会出现的死循环情况，利用mid+1来改变
```