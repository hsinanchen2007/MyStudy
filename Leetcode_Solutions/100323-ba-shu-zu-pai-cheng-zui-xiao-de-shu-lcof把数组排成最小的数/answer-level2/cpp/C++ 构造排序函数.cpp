### 解题思路
按题目要求，最后就是简化成两个数拼接好之后，谁在前面的时候更小。
这样的话，就可以构造一个排序函数来进行。构造出拼接后的两个数比大小就行了。

### 代码

```cpp
class Solution {
public:
    static bool minNumberSort(int a, int b) {
        int countA = 1, countB = 1;
        int tmpA = a, tmpB = b;
        while (a/10 > 0) {
            countA++;
            a = a/10;
        }
        while (b/10 > 0) {
            countB++;
            b = b/10;
        }
        return tmpA * pow(10,countB) + tmpB < tmpB * pow(10,countA) + tmpA ? true : false;
    }

    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), minNumberSort);
        string res;
        for (auto n : nums) {
            res += to_string(n);
        }
        return res;
    }
};
```