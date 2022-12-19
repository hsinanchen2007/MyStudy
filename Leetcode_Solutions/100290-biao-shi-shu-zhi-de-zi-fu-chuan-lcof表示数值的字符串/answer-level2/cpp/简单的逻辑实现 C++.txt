```
class Solution {
public:
    bool isNumber(string s) {
        int i=0, n = s.size();
        // 1. 去除空格
        for(; i< n && isspace(s[i]); i++);

        // 2. 存在符号+，-
        if(s[i] == '+' || s[i] == '-') {
            i++;
        }
        // 3. 接下来，只能跟数字或者.才能符合条件
        int digits=0, dots=0;
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
            isdigit(s[i]) ? digits++ : dots++;
        }
        // 没有数字或者.大于1个，则是错误的
        if (!digits || dots > 1) {
            return false;
        }
        // 4. 对e进行特殊处理
        if (s[i] == 'e') {
            i++;
            // 去掉符号
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++) {
                digits++;
            }
            // e后面必须加数字
            if (!digits) {
                return false;
            }
        }
        // 5. 去掉末尾空格
        for (; i < n && isspace(s[i]); i++);
        return i == n;
    }
};
```
