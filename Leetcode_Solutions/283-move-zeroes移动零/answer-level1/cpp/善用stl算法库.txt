因为用的c++，拿到这个题立即想到了std::remove，但是remove只是把保留的元素向前移动，尾部的是不管的，于是又想到std::fill。
这道题目最终就是一句代码了：
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
    }
};
```
