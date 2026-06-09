```
class Solution {
public:
    //直接调用库函数，删除所有等于val值的元素
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
```

执行用时 :8 ms, 在所有 C++ 提交中击败了59.82%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了87.25%的用户
