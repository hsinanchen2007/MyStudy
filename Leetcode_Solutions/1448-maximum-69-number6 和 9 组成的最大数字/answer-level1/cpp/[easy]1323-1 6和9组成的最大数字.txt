### 解题思路
把第一个遇到的6变成9即可
to_string:把int/double/...变string
stoi:把数字类字符串转变为十进制

![KS0_NP8LM~QU`GW5XU1I95W.png](https://pic.leetcode-cn.com/264be015310d689115b40632d24d9d98505bd36e8cb3034624c827297ace5fde-KS0_NP8LM~QU%60GW5XU1I95W.png)


### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};
```