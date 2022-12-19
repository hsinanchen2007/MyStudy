### 解题思路
正常字符串从后向前筛选，特殊情况包括空字符串""，全为空格的字符串" "，末尾为空格的字符串"a "

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        string res = "";

        if(!s.size()) return 0; // 空字符串

        int i = s.size()-1;
        while(i>=0 && s[i]==' '){ // 确定结尾第一个字母的位置，筛选空格字符串和结尾空格字符串
            i--;
        }

        for(; i>=0; i--){ // 筛选最后一个单词
            if(s[i]!=' '){
                res+=s[i];
            }else{
                break;
            }
        }

        return res.size();
    }
};
```