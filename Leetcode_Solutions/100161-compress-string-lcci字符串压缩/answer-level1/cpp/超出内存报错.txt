### 解题思路
开始一直报错超内存。
结果把s2=s2+x改成s2+=x就通过了。
真的是......
### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
    string s2="";
    int i=0;      
    int n=1;       
    char x;         
    while(i < (int)S.length())
    {
        x=S[i];
        if(S[i+1]==x)
        {
            n++;
        }
        else
        {
            s2+=x;
            s2+=to_string(n);
            n=1;
        }
        i++;
    }
    return s2.length() >= S.length() ? S : s2;
    }
};