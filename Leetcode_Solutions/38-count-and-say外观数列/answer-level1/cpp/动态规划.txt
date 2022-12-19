### 解题思路
以n=1和2为迭代基，设置两个常量记录数值和对应的数量，通过迭代求出下一个数列。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string s="11";
        string snew;
        char x,y;
        for(int k=2;k<n;++k){
            x=s[0];
            y='1';
            for(int i=1;i<s.size();++i){
                if(s[i]==x) ++y;   
                else{
                    snew+=y;
                    snew+=x;
                    x=s[i];
                    y='1';
                }
                if(i==s.size()-1){
                    snew+=y;
                    snew+=x;
                }
            }    
        s=snew;
        snew={};
        }
        return  s;
    }
};
```