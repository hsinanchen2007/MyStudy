### 解题思路
此处撰写解题思路
1. 主要思路就是逐个字符比对，遇到数字字符转成数字当做word的偏移 在逐个比对。

注意点：
    1. 只有当逐个比对到最后一个字符长度为word.length()才能算成功。
    2. 隐含条件"02" "04" 开头不能为0，必须排除掉。

  if (stroffset[0] == '0') {
        return false;
   }

### 代码

```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
         
         int first = 0;
         int second = 0;
         int offset = 0;
         string stroffset = "";
         for (int i = 0; i < abbr.length(); i++) {
             if (abbr[i] <= '9' && abbr[i] >= 0) {
                 stroffset += abbr[i]; 
                 if (abbr[i + 1] > '9' || abbr[i + 1] < '0') {
                     int temp = atoi(stroffset.c_str());
                     offset += temp;
                     
                     if (stroffset[0] == '0') {
                         return false;
                     }
                     stroffset = "";
                     //cout << second + offset << word.length() << endl;
                 }
             } else {
                 //cout << i << offset << word[second + offset] << abbr[i] << endl;
                 if (word[second + offset] != abbr[i]) {
                     return false;
                 }
                 second++;
             }
         }
         //cout << second + offset << word.length() << endl;
         if (second + offset != word.length()) {
             return false;
         } else {
             return true;
         }
    }
};
```