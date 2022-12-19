## 思路一：从后向前遍历移动零
### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (int i = size - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                for (int j = i; j < size - 1; ++j) {
                    if (nums[j + 1] != 0) {
                        swap(nums[j], nums[j + 1]);
                    }                    
                }                                           
            }
        }
    }
};
```

## 思路二：双指针
算法：
1. 统计0个数
2. 利用双指针，将不为0元素放到前面
3. 如果新指针小于原数组个数，则后面数组位置置0
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int c = 0, k = 0;
        for (int n : nums) {
            if (n == 0) ++c;
        }
        for (int n : nums) {
            if (n != 0) {
                nums[k++] = n;
            }
        }
        while (k < size) {
            nums[k++] = 0;
        }
    }
};
```
#### 优化
省去统计0个数
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int k = 0;
        for (int n : nums) {
            if (n != 0) {
                nums[k++] = n;
            }
        }
        while (k < size) {
            nums[k++] = 0;
        }
    }
};
```

## 思路三：优化双指针（最优解）
参考官方
### 代码
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (int k = 0, i = 0; i < size; ++i) {
            if (nums[i] != 0) {
                swap(nums[k++], nums[i]);
            }
        }
    }
};
```



