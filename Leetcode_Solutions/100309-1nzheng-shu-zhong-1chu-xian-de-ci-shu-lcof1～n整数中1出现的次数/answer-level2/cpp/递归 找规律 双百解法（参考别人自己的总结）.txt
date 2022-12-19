### 解题思路
这样理解 比如167 此时最高位first为1, fist_is_1就是1 _ _,但是不超过67，所以就是67+1=68；
fist_less_itself就是 0 _ _, 在两个——中任选一个为1，其余位置就是10个数字，所以为1*2*10=20；
至于此时为什么不考虑1，我们这样考虑，167中找100-167为1的个数与找67在0-67中为1的个数等同，所以接下来递归 67 7

在举个列子 237
first=2,对于1_ _这种就有100种，0_ _,1_ _ 有2*2*10=40种，之后递归37 7

总结一下 就是找区间进行递归，比如2789，分为[0-1999] [0-699] [0-79] [0-9]进行递归

### 代码

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        if(n<10) return 1;
        int len=getlen(n);
        int tmp=pow(10,len-1);
        int first=n/tmp;
        int first_is_1=first==1?n%tmp+1:tmp;
        int first_less_itself=first*(len-1)*(tmp/10);
         return countDigitOne(n%tmp)+first_is_1+first_less_itself;
    }
    int getlen(int n){
        int count=1;
        while(n/10!=0){
            n/=10;
            ++count;
        }
        return count;
    }
};
```