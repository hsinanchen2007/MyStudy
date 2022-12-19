### 解题思路
处理空格，使用stringstream比较方便

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        istringstream ss(s);
        string tmp;
        int cnt = 0;
        while (ss >> tmp) {
            cnt ++;
        }
        return cnt;
    }
};
```
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.8 MB, 在所有 C++ 提交中击败了5.83%的用户