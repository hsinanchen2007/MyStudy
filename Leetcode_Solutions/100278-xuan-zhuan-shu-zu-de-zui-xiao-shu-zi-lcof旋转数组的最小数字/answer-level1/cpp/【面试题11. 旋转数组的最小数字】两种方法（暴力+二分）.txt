## 思路一：暴力

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int res = INT_MAX;
        for (int n : numbers) {
            res = min(res, n);
        }
        return res;
    }
};
```

## 思路二：二分
部分有序可以考虑使用二分，接下来考虑如何通过二分减小范围，本题中左右部分分别是递增有序的，因此最小数可能在 numbers[mid] 左边也可能在右边，如：[1,2,3,4,5]最小数在左边，而[3,4,5,1,2]最小数在右边，所以通过 numbers[mid] 和 numbers[left] 比较无法减少范围。

考虑 numbers[mid] 和 numbers[right] 比较，可得下面三种情况：
- numbers[mid] 小于 numbers[right] : right = mid
- numbers[mid] 大于 numbers[right] : left = mid + 1
- numbers[mid] 等于 numbers[right] : 因为 numbers[mid] 和 numbers[right] 之间可能并不有序，只能得出最小数一定不在最右位置，所以--right

### 代码
时间复杂度：O(logn)
空间复杂度：O(1)
```c++
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) {
                right = mid;
            } else if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else {
                --right;
            }
        }
        return numbers[left];
    }
};
```
