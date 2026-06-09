执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    bool isNumber(string s) {
        int loc = 0;
        while (loc < s.length() && s[loc] == ' ')                     // 跳过空格
        {
            ++loc;
        }
        bool f = num(s, loc);                                         // f含义为是否有数字存在
        if (loc < s.length() && s[loc] == '.')                        // 遇见小数点
        {
            ++loc;
            if ((!unsignednum(s, loc))&& (!f))                        //小数点后或者前必须有数字，否则错误 
            {
                return false;
            }
            f = true;                                                 // 若小数点前无数字，点后有数字也成立
        }
        if (loc < s.length() && (s[loc] == 'e' || s[loc] == 'E'))     // 指数部分
        {
            ++loc;
            if (!num(s, loc))                                         // 指数e/E后面必须有数字，否则错误
            {
                return false;
            }
        }
        while (loc < s.length() && s[loc] == ' ')                     // 跳过空格
        {
            ++loc;
        }
        if (!f || loc != s.length())                                  //若无数字或者没有遍历完，则错误
        {
            return false;
        }
        return true;
    }
    bool unsignednum(string s, int& loc)                              //判断是否有数字
    {
        bool flag = false;
        while (loc < s.length() && s[loc] <= '9' && s[loc] >= '0')    // 跳过连续数字
        {
            ++loc;
            flag = true;
        }
        return flag;
    }
    bool num(string s, int& loc)                                      // 判断是否为带符号数字
    {
        if (loc >=s.length())
        {
            return false;
        }
        if (s[loc] == '+' || s[loc] == '-')
        {
            ++loc;
        }
        return unsignednum(s, loc);
    }
};
```
