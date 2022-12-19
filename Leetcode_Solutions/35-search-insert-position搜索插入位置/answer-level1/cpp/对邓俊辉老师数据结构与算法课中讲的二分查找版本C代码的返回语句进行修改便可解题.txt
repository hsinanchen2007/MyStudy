### 解题思路
对邓俊辉老师数据结构与算法课中讲的二分查找版本C代码的返回语句进行修改便可解题。
执行用时 :12 ms, 在所有 C++ 提交中击败了11.78%的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了72.94%的用户
用时有点大，各位适当参考！

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while(lo < hi) {
            int mi = (lo + hi) >> 1;
            target < nums[mi] ? hi = mi : lo = mi + 1;
        }
        return (0 <= lo - 1) && nums[lo - 1] == target ? lo - 1 : lo;
    }
};
```