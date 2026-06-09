### 解题思路
（1）将字符串数组的第一个字符串作为比较对象，依次与后面的字符串进行比较。比较的方法是按照每个字符串的下标，若相同则下标继续往后移动，若不同，则跳出该字符串，同时参照最后一个相同字符所在下标对用来比较的模板进行调整，用erase()函数去掉后面的字符。然后进行下一个字符串的比较。
（2）注意边界条件，判断字符串数组是否为空。
（3）数组长度用size(),单个字符串长度用length()。

### 代码

```cpp
#include <iostream>
#include <string>
 
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string a = strs[0];
        for(int i = 1;i<strs.size();i++)
        {
            for(int j = 0;j<a.length();j++)
            {
                if(strs[i][j]==a[j]) continue;
                else{
                    a=a.erase(j);
                    break;
                }
            }
        }
        return a;
        
        
    }
};
```