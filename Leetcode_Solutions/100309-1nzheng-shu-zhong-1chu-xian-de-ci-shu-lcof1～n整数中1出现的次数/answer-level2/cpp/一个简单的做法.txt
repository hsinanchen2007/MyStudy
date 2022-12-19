### 解题思路
把n拆成三部分，n=high*10^(digit+1)+cur*10^digit+low
第digit位上出现1的个数为 high*d+(cur>1)*d+(cur==1)*low
d=10^digit
digit=0代表个位

### 代码

```cpp
class Solution {
public:
    int oneInDigit(long n,int digit){
        //digit 代表第几位，个位为第0位，第一位上1的个数为 oneInDigit(n,0)
        int count=0;
        long d=pow(10,digit);
        //把n拆成三部分，n=high*10^(digit+1)+cur*10^digit+low
        long low=n%d;
        long high=n/(10*d);
        long cur=(n/d)%10;
        count+=high*d;
        if(cur>1){
            count+=d;
        }
        if(cur==1){
            count+=low+1;
        }
        return count;
    }
    int countDigitOne(int n) {
        int count=0;
        for(int k=0;pow(10,k)<=n;k++){
            count+=oneInDigit(n,k);
        }
        return count;
    }
};
```