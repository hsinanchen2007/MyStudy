### 解题思路
简单的相互减去，做的挺粗糙的，只是自己记录一下，主要还是学习大佬的题解吧。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1=str1.size(),s2=str2.size();
        if(str1+str2!=str2+str1)return "";
        while(str1.size()!=0 && str2.size()!=0){
            if(str2.size()>str1.size()){swap(str1,str2);}
            str1=str1.substr(0,str1.size()-str2.size());
        }
        return str2;
    }
};
```