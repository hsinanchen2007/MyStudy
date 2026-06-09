### 解题思路
看到排序的，第一印象就是二分。然而理清这些逻辑需要时间。
参考这篇答案，写得很好
https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int mid = 0, l=0, r = (int)numbers.size()-1;
        while(l < r) {
            mid = (l + r) / 2;
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]) {
                r = mid;
            } else {
                r -= 1;
            }
        }
        return numbers[l];
    }
};
```