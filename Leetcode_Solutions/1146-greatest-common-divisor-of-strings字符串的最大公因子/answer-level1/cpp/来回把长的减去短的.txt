
### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        while(str1 != str2)
        {
            if(str1.size() > str2.size())
                swap(str1,str2);
            if(str2.find(str1) != 0)
                return "";
            str2 = str2.substr(str1.size());
        }
        return str1;
    }
};
```