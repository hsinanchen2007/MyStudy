### 解题思路
此处撰写解题思路
先取出放入数组，然后每次从头取一个，所有的前移一位，头放最后，for循环执行n次。
### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) 
    {
        int i,ii,iii;
        for(i=0; i < s.size(); i++)   
        {
            s[i];
        }
        for(ii = 0; ii < n; ii++)      
        {
            char a=s[0];
            for(iii = 1; iii < s.size(); iii++)   
            {
                s[iii-1]=s[iii];
                s[iii]=a;
            }
        }
        return s;
    }
};
```