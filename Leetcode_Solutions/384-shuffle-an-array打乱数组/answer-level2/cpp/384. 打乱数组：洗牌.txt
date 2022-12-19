### 解题思路
* 从 [i, n-1] 之间选取一个位置与 i 交换，可以与自身交换；
* 保证可能性有 n! 种。

### 代码

```cpp
class Solution {
    vector<int> nums;
    vector<int> copy;
public:
    Solution(vector<int>& nums) {
        this->nums.assign(nums.begin(), nums.end());
        this->copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums.clear();
        nums.assign(copy.begin(), copy.end());
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=nums.size() - 1; i>=0; i--) {
            int rd = rand() % (i + 1);          
            swap(nums[rd], nums[i]);            
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```
![2.3.png](https://pic.leetcode-cn.com/79013ce7d1e756fed55e15719fdb02726687272be22611b9bded9a56c2374580-2.3.png)

* 但是`shuffle()`这样写也是可以通过的
* 这其实每个位置有 n 种可能，但是交换不会导致重复。
```cpp
        for(int i=0; i < nums.size(); i++) {
            int rd = rand() % (i + 1);          
            swap(nums[rd], nums[i]);            
        }
```

