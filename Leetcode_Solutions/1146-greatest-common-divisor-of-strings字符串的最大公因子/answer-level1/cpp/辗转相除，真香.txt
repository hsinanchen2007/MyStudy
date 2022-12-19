![image.png](https://pic.leetcode-cn.com/961f5e2f8bab9868ed69be93386a2a2ba9c6da46c1b36575143847985f6b488c-image.png)


### 解题思路
一开始的时候，想通过数学计算的方法去求，但是没算出来，后来回想了一下辗转相除的步骤，发现还是挺快的。

### 代码

```cpp
class Solution {
public:

    bool chu(string& s1, string& s2){
        int i = 0;

        while(i < s2.size()){
            if(s1[i] != s2[i]) return false;
            ++i;
        }
        
        s1 = s1.substr(i, s1.size() - i);
        
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1 == str2) return str1;
        
        while(chu( str1.size() >= str2.size() ? str1 : str2, str1.size() >= str2.size() ? str2 : str1) ){
            if(str1.size() == str2.size()) 
                if( str1 == str2) 
                    return str1;
                else
                    return "";
        }

        return "";
    }
};
```