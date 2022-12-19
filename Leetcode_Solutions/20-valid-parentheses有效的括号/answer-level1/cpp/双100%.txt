### 解题思路
栈。中间图写的快，比符号的时候比的ascii码。
![image.png](https://pic.leetcode-cn.com/dc6563de63515d461f171d5f995aef7592acf81be54edff7421011b84bea6e3e-image.png)

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(auto c:s)
        {
            if(c=='('||c=='['||c=='{')
                sta.push(c);
            else
            {
                if(sta.empty())
                    return false;
                char item=sta.top();
                if(item!=(c-1)&&item!=(c-2)) //比的ascii码
                    return false;
                sta.pop();
            }
        }
        if(sta.empty())
            return true;
        return false;
    }
};
```