### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
     //方法一：字符串转换为数值，数值转换为字符串to_string 
        string s = to_string(num) ;
        for (int i = 0 ; i < s.length() ; ++i) {
            if (s[i] == '6') {
                s[i] = '9' ;
                break ;
            }
        }
        int ret = 0 ;
        for (int i = 0 ; i < s.length() ; ++i) {
            ret = ret * 10 + s[i] - '0' ;
        }
        return ret ;
        //方法二：使用流，将字符串变成整数
        string s = to_string(num) ;
        for (int i = 0 ; i < s.length() ; ++i) {
            if (s[i] == '6') {
                s[i] = '9' ;
                break ;
            }
        }
        int ret = 0 ;
        stringstream ss;
        ss<<s;
        ss>>ret;
        return ret ;
        
    }
};
```