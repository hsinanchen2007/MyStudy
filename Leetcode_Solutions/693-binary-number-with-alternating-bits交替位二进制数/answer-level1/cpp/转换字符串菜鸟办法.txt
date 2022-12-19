### 解题思路
先把整数的二进制形式转换成字符串，判断是否有相邻两字符相同即可。

### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        string str="";
        
        while(n>0)
        {
            int temp=n%2;
            str+=to_string(temp);
            n/=2;
        }
        
        for(int i=0;i<str.size()-1;i++)
        {
            if(str[i]==str[i+1])
            {
                return false;
            }
        }
        return true;

    }
};
```