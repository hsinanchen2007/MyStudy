### 解题思路
只要一个候选字candidate, 遍历时遇到候选字的次数count, 遇到相同的候选字count + 1, 不同则变更候选字，count = 1. 该算法只需遍历一次。

执行用时 :4 ms, 在所有 C++ 提交中击败了99.83%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        char candidate = ' ';
        int count = 0;
        string compress_string;
        for (auto c : S) {      // 不会取出'\n'
            if (c != candidate) {
                if (count != 0) {
                    compress_string += std::to_string(count);
                }
                candidate = c;
                count = 1;
                compress_string += candidate;
            }
            else {
                count += 1;
            }
        }
        compress_string += std::to_string(count);
        return S.size() <= compress_string.size() ? S : compress_string;
    }
};
```