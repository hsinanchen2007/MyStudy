### 解题思路
设置判断正负的标志flag，如果x小于零需要利用标志来去掉负号，最后再添加负号即可
特殊情况x=0 直接输出零，反转后的数溢出则直接返回0
接着仿照栈的弹出压入来实现反转
### 代码

```java
class Solution {
    int result=0;
    int flag=0;
    public int reverse(int x) {
        if(x<0)
        {
            x*=-1;
            flag=-1;
        }
        if(x==0)
        {
            return x;
        }
        while(x%10==0)
        {
            x=x/10;
        }
        while(x!=0)
        {
            if((result*10)/10!=result)
            {
                result=0;
                return result;
            }
            result=result*10+x%10;
            x=x/10;
        }
        if(flag==-1)
        {
            result*=-1;
        }
        return result;
    }
}
```