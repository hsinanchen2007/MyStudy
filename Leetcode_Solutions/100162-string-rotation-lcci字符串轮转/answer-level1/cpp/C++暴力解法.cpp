### 解题思路
我的方法是不是原地“暴”炸了 ┭┮﹏┭┮

![image.png](https://pic.leetcode-cn.com/b8a7d71b3917c14da95dfa59ff89eccaa3f318b03577cd3975b12b8b00565b4b-image.png)


### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int mask = 0, j=0;
        bool m = false;
        
        if(s1.length() != s2.length())
            return false;
        
        for(int i=0,k=0; mask<s1.length(); k++)
        {
            if(s1[i] == s2[j])
            {    
                if(i+1 == s1.length())
                {
                    i = 0;
                    j++;
                    mask++;
                    m = true;
                }
                else
                {
                    j++;
                    i++;
                    mask++;
                }
            }
            else
            {
                if(i+1 == s1.length())
                {
                    return false;
                }
                else{
                    if(m)
                        return false;
                    j = 0;
                    i++;
                    mask = 0;
                }
            }
        }
        cout<<mask<<endl;
        if(mask == s1.length())
            return true;
        else
            return false;
    }
};
```