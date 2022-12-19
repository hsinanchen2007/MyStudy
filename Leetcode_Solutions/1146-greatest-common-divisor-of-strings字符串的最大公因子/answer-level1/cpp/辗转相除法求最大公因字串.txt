### 解题思路
先调整成str1长度大于str2长度。
然后把str1前面减去和str2一样的部分。如果有不一样，说明没有公因字串，直接返回空。
最好递归操作，str1变成str2的值，str2变成上一步减去后的部分。直到str2为空。
整体和gcd的数字版是一样的。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.size() > str1.size())
            return gcdOfStrings(str2, str1);
        for(int i = 0;i<str2.size();++i){
            if(str1[i] != str2[i])
                return "";
        }
        
        string tmp = str1.substr(str2.size(),str1.size()-str2.size());
        str1 = str2;
        str2 = tmp;

        return str2.size()==0?str1: gcdOfStrings(str1, str2);
    }
};
```