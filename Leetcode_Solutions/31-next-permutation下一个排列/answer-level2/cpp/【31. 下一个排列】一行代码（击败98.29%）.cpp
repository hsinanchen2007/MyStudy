## 思路一：利用库函数
### 代码
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            sort(nums.begin(), nums.end());
        }
    }
};
```

## 思路二
如果存在下一个排列，则数组非递减，所以一定存在相邻的两个数递增。
如：
1 2 5 8 7
1 2 7 8 5 （交换5和7）
1 2 7 5 8 （逆序7后面数）
1. 把整个数组元素看作一个整数，下一个排列即为**比当前排列数字稍大一点的数**，所以从最低位开始向高位遍历（即从右向左遍历），如果找到一个前一位比当前位小的数，则停止，当前位为i。本例中为2。
2. 如果找到，再次从低位开始找，在区间[i, size-1]中从后向前遍历，找到第一个比当前数大的数7，然后交换5和7。
3. 将7后面的数字逆序即得到下一个稍大一点数。（如果没有找到，则i为-1，逆序即为整个数组元素）

### 代码
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i;
        for (i = size - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                break;    
            }
        }
        if (i >= 0) {
            for (int j = size - 1; j >= i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```
