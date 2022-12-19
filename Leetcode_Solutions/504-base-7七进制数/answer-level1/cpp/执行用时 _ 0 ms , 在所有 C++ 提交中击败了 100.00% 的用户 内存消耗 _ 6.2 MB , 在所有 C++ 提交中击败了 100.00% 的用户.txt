### 解题思路
正常的进制转换方法，如果你不会的话百度都能百度得到的。
唯一要注意的一点是如果num是个负数话定义一个标记用作后边操作字符串是否加负号，并取num的绝对值，接着正常进行进制转换就好了。

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        
        if(num==0)
        {
            return "0";
        }
        
        int n=0;
        if(num<0)
        {
            n=1;
            num=abs(num);
        }
        string str="";
        
        while(num>0)
        {
            int n=num%7;
            str=to_string(n)+str;
            num/=7;
        }
        
        if(n==1)
        {
            str="-"+str;
        }
        
        return str;

    }
};
```