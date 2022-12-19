### 解题思路
用string实现翻转，就是挺耗内存的

### 代码

```cpp
#include<string>
class Solution {
public:
    int reverse(int x) {
        int flag = 0;   //负数标志
        long x_ = 0;    //long类型x_用来应对-2147483648(转换为正数会溢出int)
        if(x < 0){
            flag = 1;
            x_ = x;
            x_ = -x_;   //x转化为正数，赋值x_
        }else{
            x_ = x;     //赋值x_
        }
        string tmp = to_string(x_);     //转string
        // **注意翻转函数 reverse
        // **reverse加命名空间
        std::reverse(tmp.begin(), tmp.end());   //翻转
        char* end;
        // **注意字符串转long函数
        long re = strtol(tmp.c_str(), &end, 10);    //转long
        if(flag && (-re)<(INT_MIN))     //当负数时，是否小于最小值
            return 0;
        if(re>(INT_MAX))                //当正数时，是否大于最大值
            return 0;
        // **注意大类型转小类型
        int result = static_cast<int>(re);  //转回int
        if(flag)
            result = -result;              //还原正负号
        return result;
    }
};
```