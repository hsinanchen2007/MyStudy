送分题，进制转换，别忘了负号和0

代码：
```
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        else {
            string str = "";
            bool neg = false;
            if (num < 0) {
                neg = true;
                num = -num;
            }
            while (num) {
                str.insert(0, 1, (char)(num % 7 + 48));
                num = num / 7;
            }
            if (neg)
                str.insert(0, 1, '-');
            return str;
        }
    }
};
```
