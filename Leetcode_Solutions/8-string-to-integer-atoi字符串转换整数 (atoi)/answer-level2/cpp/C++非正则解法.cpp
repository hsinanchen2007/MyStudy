思路：利用C++标准库实现lstrip及转换，利用异常排除非其他情况
```
class Solution {
public:
    int myAtoi(string str) {
        str.erase(str.begin(), find_if(str.begin(), str.end(), [] (int ch) {return !isspace(ch);}));  //去除左侧空白
        str.erase(find_if_not(str.begin() + 1, str.end(), [] (int ch) {return isdigit(ch);}), str.end());  //去除首个非空白后的非数字字符
        if (str.empty()) {    //全空白情况
            return 0;
        } else {
            int ans;
            try {
                ans = stoi(str);
            } catch (invalid_argument e) {  //表达式错误，证明首个非空白字符为字母
                return 0;
            } catch (out_of_range e) {  //溢出，判断正负，返回最大值或最小值
                return str[0] == '-' ? INT32_MIN : INT32_MAX;
            }
            return ans;
        }
    }
};
```