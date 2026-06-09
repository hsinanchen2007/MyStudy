### 解题思路

直接利用hash求解
注意额外数组要开在class里面，推测leetcode的判题机制是不断循环class输入数据的
定义在类外面会导致hash的初值不正确
### 代码

```cpp
// 0-n-1


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        const int maxn = 100010;
        int hash_[maxn] = {0};

        for(int i = 0; i < nums.size(); i++){
            if(hash_[nums[i]]==0) hash_[nums[i]]++;
            else return nums[i];
        }
        return -1;
    }
};
```