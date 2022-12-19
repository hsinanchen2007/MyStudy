### 解题思路
从短一点的那个串入手，看是否匹配。到最后都匹配不了那就没救了，返回空字符串

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string & minstr = str1.size() < str2.size() ? str1 : str2;
        string & maxstr = str1.size() < str2.size() ? str2 : str1;
        //i表示将minstr分割成几段
        int i = 1;
        while (minstr.size()/i != 0) {
            int len = minstr.size()/i;
            //不能整除证明不可能，直接跳过
            if (minstr.size() % len != 0 || maxstr.size() % len != 0) {
                i++;
                continue;
            }
            bool minok = true;
            for (int j=0; j<minstr.size(); j+=len) {
                //不匹配直接跳出
                if (minstr.substr(j, len) != minstr.substr(0,len)) {
                    minok = false;
                    break;
                }
            }

            if (!minok) {
                i++;
                continue;
            }
            for (int j=0; j<maxstr.size(); j+=len) {
                if (maxstr.substr(j, len) != minstr.substr(0,len)) break;
                //匹配，返回子串
                if (j+len==maxstr.size()) return maxstr.substr(0, len);
            }
            i++;
        }
        return "";
    }
};
```