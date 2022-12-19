### 解题思路
![}{98OX4OW1`SDNLS8KSI57F.png](https://pic.leetcode-cn.com/792087d31b4c1b88e46dee20b7eb7fbd994b49ae60a8eb842e31af9d72934ccc-%7D%7B98OX4OW1%60SDNLS8KSI57F.png)

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt = 0;
        string res;
        for (auto c:S) {
            if(c == '('){
                cnt++;
                if(cnt == 1) continue;
            }
            else cnt--;

            if(cnt != 0)res.push_back(c);
        }
        return res;
    }
};
```