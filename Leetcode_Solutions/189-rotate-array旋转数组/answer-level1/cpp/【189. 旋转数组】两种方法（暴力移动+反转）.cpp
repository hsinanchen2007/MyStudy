## 思路一：暴力移动（一个case超时）
旋转k次，每次旋转一个元素。
### 代码
时间复杂度：O(n * k)
空间复杂度：O(1)
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        for (int i = 0; i < k; ++i) {
            int t = nums[size - 1];            
            for (int i = size - 1; i > 0; --i) {
                nums[i] = nums[i - 1];
            }
            nums[0] = t;
        }
    }
};
```

## 思路二：利用反转
**注意当k大于数组大小的处理**
### 代码
时间复杂度：O(n)，一次反转时间复杂度O(n)，反转3次
空间复杂度：O(1)
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k > size) {
            k = k % size; 
        } 
        reverse(nums.begin(), nums.begin() + size - k);
        reverse(nums.begin() + size - k, nums.end());
        reverse(nums.begin(), nums.end());        
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());        
    }
};
```


