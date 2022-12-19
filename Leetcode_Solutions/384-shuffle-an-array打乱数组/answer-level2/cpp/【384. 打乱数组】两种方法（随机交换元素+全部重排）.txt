### 思路一：随机交换元素

### 代码

```cpp
class Solution {
    vector<int> vec;  
    vector<int> ori;
public:
    Solution(vector<int>& nums) : vec(nums), ori(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {        
        //vec = ori;
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (vec.size() > 0) {
            int i = rand() % vec.size();
            int j = rand() % vec.size();
            swap(vec[i], vec[j]);
        }        
        return vec;
    }
};
```

### 思路二：全部重排

### 代码
```c++
class Solution {
    vector<int> vec;    
public:
    Solution(vector<int>& nums) : vec(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {        
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = vec;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }
};
```