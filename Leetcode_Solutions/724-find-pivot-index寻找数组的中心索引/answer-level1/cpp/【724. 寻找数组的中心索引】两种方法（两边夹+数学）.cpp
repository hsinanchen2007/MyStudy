## 思路一：两边夹
### 代码
```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;  
        int size = nums.size();      
        int left = 0, right = 0;
        for (int i = 1; i < size; ++i) {
            right += nums[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            if (left == right) return i;//中心索引在开头
            left += nums[i];
            right -= nums[i + 1];
        }
        //中心索引在最后
        if (left == right) return size - 1;
        return -1;
    }
};
```

## 思路二：数学
### 代码
```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;  
        int size = nums.size();      
        int sum = 0, sumLeft = 0;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
        }
        for (int i = 0; i < size; ++i) {
            if (sumLeft * 2 + nums[i] == sum) {
                return i;
            }
            sumLeft += nums[i];
        }        
        return -1;
    }
};
```

