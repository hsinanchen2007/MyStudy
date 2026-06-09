### 解题思路
官方思路
### 知识点
**INT_MAX**,**INT_MIN**由标准头文件<limits.h>定义。
**INT_MAX**=2^31-1(2,147,483,647)
**INT_MIN**=-2^31(-2,147,483,648)
### 感悟
心态崩了，这一个破题搞了2个小时，各种溢出！！！！！！！！！！！！！！！！！！！！！！！
人生就像一场戏，因为有缘才相聚。相扶到老......
### 代码

```cpp
class Solution {
public:
    int reverse(long long int x) {
        //输出
        int output=0;
        int tail;
        int xtail=x%10;
        while(x!=0){
            tail=x%10;
            x/=10;
            if(output>INT_MAX/10 || (output==INT_MAX/10 && xtail>INT_MAX%10)) return 0;
            if(output<INT_MIN/10 || (output==INT_MIN/10 && xtail<INT_MIN%10)) return 0;
            output=output*10+tail;
            }
            return output;
    }
};
```