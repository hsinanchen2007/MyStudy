### 解题思路
这道题主要是溢出问题，我参考了一位大佬的题解，使用
 if (flag*y > (1 << 31) - 1 || y*flag < 1 << 31) 来判断溢出，
(1 << 31) - 1 为2 147 483 647，而1 << 31为-2 147 483 648。
为了防止溢出，用long long数组来复制输入的x，并用flag来判断正负。

本题另外一个点就是个位为0时反转要去掉，因为0是不占高位的，主要就是通过%和/来获得所有的数字并存进数组来处理。

关于溢出的问题，此前我只了解过C语言的机制，具体的操作还需要进一步学习。

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int num[33];
        int i=1;
        bool flag=1;
        if(x<0)
        {
            flag=-1;
        }
        long long z=x,y=0;
        abs(z);
        while(z!=0)
        {
            num[i++]=z%10;
            z/=10;
        }
        int j=1;
        if(num[1]==0)
        {
            j++;
        }
        for(;j<=i-1;j++)
        {
            y=y*10+num[j];
        }
       if (flag*y > (1 << 31) - 1 || y*flag < 1 << 31) 
        return 0;
        else
        {
             return flag*y;
        }
    }
};
```