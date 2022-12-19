### 解题思路
一开始我还无耻地试图用try catch解决溢出问题：只要error直接return 0 
结果发现力扣的编译器不会try catch，照样runtime error
那就正儿八经写咯，先写一个MAX_INT/10的值，反转后每次加新的值上去之前先除10看看会不会溢出（如果不除10直接就error，0分了）
符号位有没有影响我没考虑，直接先分离符号咯
跑个while循环计算一下有几位。
如果是个个位数就直接返回，省的跑一遍
还有一个要注意，如果是**-2[^31]**次方，去掉符号位的时候会直接溢出
然后循环就一位一位剥离,%10,/=10，乘以相应的位数，加到ans里（加之前先把二者除10加一下看看会不会超过maxn）
没啥好说的了，直接看代码吧

### 代码

```cpp
#include <cmath>
class Solution {
public:
    const int maxn=214748365;  //max_int / 10 ,构建的数除以10必须小于这个数，否则溢出
    const int pow[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int reverse(int x) {
        if(abs(x)<10) return x;
        if(x==-2147483648) return 0;
        int ans = 0,n = 0,t = 0, flag = x/abs(x);
        x = abs(x);
        int y = x;
        while(y)  //数x的位数
        {
            y/=10;
            n++;
        }
        for(int i=n;i>=1;i--)
        {
            t = x % 10;
            if(t*pow[i-1] + ans/10 >= maxn) return 0;
            ans += t*pow[i];
            x/=10;
        }
        return ans*flag;
    }
};
```