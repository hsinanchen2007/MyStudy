### 解题思路
while下面的三行类似整除除法

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) swap(str1, str2);
        if (str2 == "") return str1;
        int pos = str1.find(str2);
        if (pos == -1) return "";
        while (pos != -1) {
            str1 = str1.substr(pos + str2.size());
            pos = str1.find(str2);
        }
        return gcdOfStrings(str1, str2);
    }
};
```