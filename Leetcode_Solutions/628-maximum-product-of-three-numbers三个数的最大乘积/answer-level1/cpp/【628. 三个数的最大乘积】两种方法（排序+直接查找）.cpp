## 思路一：排序
### 代码
时间复杂度取决于排序：O(nlogn)
```c++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int a = INT_MIN, b = INT_MIN;
        if (nums[0] < 0 && nums[1] < 0) {
            a = nums[0] * nums[1] * nums[size-1];
        }
        b = nums[size-1] * nums[size-2] * nums[size-3];        
        return max(a, b);
    }
};
```

## 思路二：查找
寻找三个最大数和两个最小数，比较三个最大数乘积和两个最小数和一个最大数乘积。
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //假设max1 > max2 > max3
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        //假设min1 < min2
        int min1 = INT_MAX;
        int min2 = INT_MAX;        
        for (int a : nums) {
            if (a > max1) {
                max3 = max2;
                max2 = max1;
                max1 = a;
            } else if (a > max2) {
                max3 = max2;
                max2 = a;
            } else if (a > max3) {
                max3 = a;
            }
            
            if (a < min1) {
                min2 = min1;
                min1 = a;
            } else if (a < min2) {
                min2 = a;    
            }            
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
```
