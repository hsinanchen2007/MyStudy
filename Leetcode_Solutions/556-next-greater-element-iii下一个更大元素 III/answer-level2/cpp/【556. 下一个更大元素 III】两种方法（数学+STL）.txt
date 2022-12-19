### 思路一：找规律
参考官方示例
如：158476531
1. 从右向左，找到第一递减数字 4
2. 再从右向左，找到第一个大于之前找到的递减数字（4）为 5
3. 交换 4 和 5，得到 158**5**76431
4. 将 5 之后数字逆序，记得到下一个更大数字 158**5** (13467)


### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 1;
        for (; i > 0; --i) {
            if (str[i] > str[i - 1]) break;
        }
        if (i == 0) return -1;
        for (int j = len - 1; j >= i; --j) {
            if (str[j] > str[i - 1]) {
                swap(str[j], str[i - 1]);
                break;
            }
        }
        reverse(str.begin() + i, str.end());
        long long res = stoll(str);
        return res > INT_MAX ? -1 : res;
    }
};
```

### 思路二：STL
### 代码
```c++
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long long res = stoll(str);
        return res > INT_MAX || res <= n ? -1 : res;
    }
};
```
