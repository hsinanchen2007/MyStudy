```
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stringstack;
        for(int i = 0; i < S.size(); ++i) {
            if(!stringstack.empty() && stringstack.top() == '(' && S[i] == ')') {
                stringstack.pop();
                continue;
            }
            stringstack.push(S[i]);
        }
        return stringstack.size();
    }
};
```
![image.png](https://pic.leetcode-cn.com/2d9c168ee5538c1352047c4c45136942fcb8bf02350b0a403c6d961b396e5fcf-image.png)
