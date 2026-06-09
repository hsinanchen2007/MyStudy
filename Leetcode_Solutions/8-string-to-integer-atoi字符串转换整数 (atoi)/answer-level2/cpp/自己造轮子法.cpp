### 解题思路
=-=真实按照题目要求一个一个改的（甚至WA了好多次。。。）

### 代码

```cpp
// #define INT_MAX 2147483647
// #define INT_MIN -2147483648

class Solution {
public:
    int myAtoi(string str) {
        // 标记正负
        bool sign = true;
        // 标记是否开始识别数字
        bool begin = false;
        // 保存结果的绝对值
        int result = 0;
        for(char chr: str){
            // 去除开头空格
            if(chr == ' ' && !begin){
                continue;
            }
            // 如果是数字
            if(chr >= '0' && chr <= '9'){
                // 如果为正数 如果再次添加数字则越界(以便于result*10判断) 如果添加数字后越界
                if(sign && ((result > INT_MAX/10)||(chr-'0' > INT_MAX - result*10))){
                    return INT_MAX;
                // 同上 由于最小负数的绝对值存储不下 那么就判断绝对值大于最大整数则判断为溢出
                } else if(!sign && ((result > abs(INT_MIN+1)/10)||(chr-'0' > abs(INT_MIN+1) - result*10))){
                    return INT_MIN;
                // 正常添加数字到末尾
                } else {
                    result = result*10 + (chr-'0');
                }
                begin = true;
            // 只有识别数字之前的正负号有意义 
            } else if(chr == '+' && !begin){
                sign = true;
                begin = true;
            // 同上
            } else if(chr == '-' && !begin){
                sign = false;
                begin = true;
            } else {
                break;
            }
        }
        // 如果是负数则取相反数
        if(!sign){
            result = -result;
        }
        return result;
    }
};
```