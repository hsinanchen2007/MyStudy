### 解题思路
直接用random_shuffle……

### 代码

```cpp
class Solution {
    vector<int> v;
public:
    Solution(vector<int>& nums) {
        v=vector<int>(nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> v1(v);
        random_shuffle (v1.begin(), v1.end());
        return v1;
    }
};
```