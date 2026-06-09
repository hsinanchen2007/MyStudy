### 解题思路
本题和[153题](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)类似，但是153题给的数字都是不重复的。

该题减治的思想是：通过排除不可能是最小值元素，进而缩小范围。当我们拿中间的数和最右边的数相比时，有三种情况：
    1. 中间的数比右边的大，那么中间数不可能是最小的数，最小的数只可能出现在中间数的后面，改`left = mid + 1`缩小区间
    2. 中间的数和右边的小，那么右边的数不可能是中位数，此时，中间的数可能是最小的数，改`right = end` 缩小区间
    3. 中间的数和右边相等，例如`[3,3,3,1,3]`此时中间的数和最右边的数都为**3**，可以知道的是，此时我们可以排除最右边的数，改区间为`right = right - 1`

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(numbers[mid] > numbers[right]) left = mid + 1;
            else if(numbers[mid] == numbers[right]) right --;
            else right = mid;
        }
        return numbers[left];
    }
};
```