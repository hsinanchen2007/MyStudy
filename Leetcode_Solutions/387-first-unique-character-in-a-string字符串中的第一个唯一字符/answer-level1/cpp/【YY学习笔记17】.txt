### 解题思路
双重循环暴力求解
### 知识点
**1.**  求string s的长度：s.length()。
**2.**  有一个疑问：对于字符串s=""。for(i=0 ; i<(s.length()-1) ; i++)会无限死循环。（我觉得应该就不会进入循环呀）。
### 感悟
**1.**  这么简单的题又卡了30min。“鸡哥，算了算了。不就是一道题嘛，别和它计较”。
**2.**  之所以花了这么长时间，一个是因为上述疑问把我卡了10多分钟；另外就是测试用例"","z","cc"都没有注意到，导致代码一直有漏洞。
### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        bool equ;
        if(s.length()==1) return 0;
        if(s.length()==0) return -1;
        for(int i=0;i<s.length();++i){
            equ=false;
            for(int j=0;j<s.length();++j){
                if(s[i]==s[j]&&i!=j){
                   equ=true;
                   break; 
                }    
            }
            if(!equ)
                return i;
        }
        return -1;
    }
};
```