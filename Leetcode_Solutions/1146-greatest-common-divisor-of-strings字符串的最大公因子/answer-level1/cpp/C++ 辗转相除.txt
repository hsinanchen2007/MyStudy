### 解题思路
辗转相除求最大公因式

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while(str1 != str2){
            if(str1.size() > str2.size()){
                str1 = str1.substr(str2.size());
            }
            else if(str1.size() < str2.size()){
                str2 = str2.substr(str1.size());
            }
            else return "";
        }
        return str1;
    }
};
```