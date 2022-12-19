### 解题思路
1.先将传入的字符串全部转换成小写字母。
2.将字母字符或是数字字符压入vec_str容器中。
3.从首和尾进行匹配，一旦匹配失败就返回false，若全部匹配成功则返回true。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> vec_str;
        for(int i = 0;i < s.length();i++){
            s[i] = tolower(s[i]);  // all char get to lower
        }
        for(int i = 0;i < s.length();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                vec_str.push_back(s[i]);
            }
        }
        
        for(int i = 0,j = vec_str.size() - 1;i < j;i++,j--){
            if(vec_str[i] != vec_str[j]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
};
```