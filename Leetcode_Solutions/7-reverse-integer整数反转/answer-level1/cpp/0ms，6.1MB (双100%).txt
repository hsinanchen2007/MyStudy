### 解题思路
先求出此数位数，然后循环求每一位数即可
### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long int i,s,j;
        j=x;
        for(i=0;x!=0;i++)x/=10;
        x=j;
        for(s=0;x!=0;x/=10)s+=x%10*pow(10,--i);
        if(s>2147483647||s<-2147483648)return 0;
        return s;
    }
};
```