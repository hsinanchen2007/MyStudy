### 解题思路
就按照题目的要求，不明所以的就过了。

不过大佬们说水很深，看来还是需要多历练啊。
### 代码

```cpp
class Solution {
public:
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp = res;
        int size = temp.size();
        for(int i=0;i<size;i++){
            int rad = rand() % size;
            swap(temp[i],temp[rad]);
        }
        return temp;
    }
private:
    vector<int> res;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```