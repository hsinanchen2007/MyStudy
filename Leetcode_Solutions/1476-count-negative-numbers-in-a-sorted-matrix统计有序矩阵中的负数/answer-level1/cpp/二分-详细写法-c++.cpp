### 解题思路
这题重在使用二分法做，用来理解二分法的那些细枝末节，而不是玄学编程。

东哥[那篇文章](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/)讲的太好了，推荐去看！看完基本就可以彻底理解二分思想！

具体不写了，思路见注释

### 代码

```cpp
class Solution {
public:
    //找到第一个小于0的数即可
    int binary_search(vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == 0) {
                left = mid + 1;
            } else if(nums[mid] < 0) {
                right = mid - 1;
            } else if(nums[mid] > 0) {
                left = mid + 1;
            }
        }
        if(left >= nums.size()) return nums.size();
        return left;  //由于是返回第一个小于0的索引,所以不是返回right(right是为最后一个为0的索引)
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            ans += (grid[i].size() - binary_search(grid[i]));
        }
        return ans;
    }
};
```