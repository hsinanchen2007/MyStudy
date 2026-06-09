1、去首尾空格（LeetCode蜜汁干扰测试用例）
2、一个究极完整的数字里面的可以分为 A.B[e/E]C
- A：可带符号数
- B：无符号数字
- C：可带符号数
3、好了，下面我们从第一个数，下标index=0开始判断；
因为A、B、C每一部分都有明显的特殊符号进行分割，所以很方便分段判断。
1. 先判断整数部分，因为可以带符号所以用bool scanInt()，bool isNum全程记录当前字符的合法性;
2. 找到‘.’，开始判断小数部分，因为“.5”或“5.”都合法，所以小数部分要求【小数点前为可带符号数 或 小数点后为无符号数字 】
3. 找到‘e/E’，开始判断指数部分，出现e/E，则指数不能空，要求【e之前都符合1.2条件 并且 e后为可带符号数】
4. 最后结果【当前合法性isNum 并且 下标index=s.size()】。

```
class Solution {
public:
    bool isNumber(string s) {
        // 去除首尾空格
        int len = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(0, s.size() - len);
        len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(len);

        if(s.size() == 0) return false;
        int index = 0; // 记录当前判断位置

        // 判断整数部分是否 是可带符号数字
        bool isNum = scanInt(s, index);

        // 判断小数部分
        if(s[index] == '.')
        {
            index++;

            // 小数点前面有带符号数字 或者 小数点后面有数字 即可
            isNum = isNum | scanUnsignedInt(s, index) ;
        }

        // 判断指数部分
        if(s[index] == 'e' || s[index] == 'E')
        {
            index++;

            // e或者E的前面 得是符合要求数字，并且后面 得是可带符号的数字
            isNum = isNum & scanInt(s, index);
        }

        return isNum & (index == s.size());
    }

    bool scanInt(string & s, int& index){
        if(s[index] == '+' || s[index] == '-')
        {
            index++;
        }
        return scanUnsignedInt(s, index);
    }

    bool scanUnsignedInt(string & s, int& index)
    {
        bool flag = false;
        while(s[index] >= '0' && s[index] <= '9' && index < s.size())
        {
            index++;
            flag = true;
        }
        return flag;
    }
};
```
