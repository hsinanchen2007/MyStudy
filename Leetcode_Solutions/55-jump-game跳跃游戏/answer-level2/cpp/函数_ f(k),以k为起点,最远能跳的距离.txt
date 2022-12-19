### 解题思路
构造函数f(k): 以k为起点,最远能跳的距离
维护一个数组jumpIndex，保存的值为：每一个元素位置为起跳点，最远能跳到的index
然后进行下一次循环，维护一个变量max_idx，保存当前循环能跳到的最远的index
一旦某个元素是0，max_idx一定大于当前的idx，才能保证可以跳过这个0，否则返回false

此外，最后一个元素是多少都无所谓，因为题目是跳到最后一个元素，而不是跳完整个vector

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        vector<int> jumpIndex;
        for(int i = 0; i < nums.size(); ++i){
            jumpIndex.push_back(i + nums[i]);
        }
        int max_idx = -1;
        for(int i = 0; i < nums.size()-1; ++i){
            max_idx = max(max_idx, jumpIndex[i]);
            if(nums[i] == 0 && max_idx <= i) return false;
        }
        return true;
    }

};
```

### 结果
执行用时 : 20 ms , 在所有 C++ 提交中击败了 24.55% 的用户 
内存消耗 : 8.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户