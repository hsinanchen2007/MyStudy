### 解题思路

![image.png](https://pic.leetcode-cn.com/54a42657d0455769136019558b4354dbf50f3341d805de647ee00b1829fc7997-image.png)
思路：
利用栈，当栈顶是'('时，且元素是')'时，出栈，否则入栈。最后栈中元素的和即是需要补齐的个数
原因：不需要补齐的，一定是嵌套成对出现的。
### 代码

```cpp
class Solution {
public:
    int minAddToMakeValid(string S)
    {
        deque<char> buff;

        for (int i = 0; i < S.size(); i++) {
            if (!buff.empty() && buff.front() == '(' && S[i] == ')') {
                buff.pop_front();
            } else {
                buff.push_front(S[i]);
            }
        }

        return buff.size();
    }
};
```