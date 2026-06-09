### 解题思路
res用来存储分数，p用来存储嵌套括号的层数，x用来判断是否是最内层括号
只需将最内层括号的分数加起来就是最终的分数

### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<char> s;
        int res=0;
        int p=0;
        int x = 0;
        for (auto i : S) {
            if (i == '(') {
                p++;
                x = 1;
            }
            else {
                if (x) {
                    res += pow(2, p - 1);
                }
                x = 0;
                p--;
            }
        }
        return res;
    }
};
```