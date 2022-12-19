### 解题思路
用两次二分：
1. 首先找起始的位置坐标x：
![image.png](https://pic.leetcode-cn.com/0e7d8d62f2c2ad772cc2628ee56c0c146a664bca754dda685e37e600c4e6006c-image.png)
这时候答案x在mid的左边，故更新区间：`[l, mid]`，代码为：
```cpp
int l = 0, r = n - 1;
    while (l < r){
        int mid = l + r >> 1;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
res.push_back(l);
```
2. 再找尾元素位置：
![image.png](https://pic.leetcode-cn.com/794fd4ce5b17ea1815dba8b86af20f9ae976653c3e6a5a5d3d059fb95420c3cd-image.png)
这时候答案x在mid的右边，故更新区间：`[mid, r]`，代码为：
```cpp
 l = 0, r = n - 1;
    while (l < r){
        int mid = l + r + 1 >> 1;
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
 res.push_back(r);
```
3. 判断边界情况：数组为空以及二分的结果l或r不等于target时，返回`{-1， -1}`.
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        if (!n) return {-1, -1};
        int l = 0, r = n - 1;
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        res.push_back(l);
        if (nums[r] != target) return {-1, -1};
        
        l = 0, r = n - 1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        res.push_back(r);
        
        return res;
    }
};
```