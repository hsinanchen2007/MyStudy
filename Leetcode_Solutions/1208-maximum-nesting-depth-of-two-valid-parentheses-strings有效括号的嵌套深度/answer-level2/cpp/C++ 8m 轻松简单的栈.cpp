### 解题思路
1. 思路就是每个括号根据深度的奇偶性给数组赋0或者1.
2. 所以只需要遍历的时候记录深度即可, 具体看下面的代码.

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> _stack;
        vector<int> res(seq.size(), 0);
        int depth = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                _stack.push('(');
                depth++;
                res[i] = (depth + 1) % 2;
            }
            else {
                _stack.pop();
                res[i] = (depth + 1) % 2;
                depth--;
            }
        }

        return res;
    }
};
```