每隔5会产生一个零；
每隔5乘5再产生一个0；
每隔5乘5乘5再会产生一个；
……
故数次连除，计数相加

```
class Solution {
    public int trailingZeroes(int n) {
            int result =0;
            while(n>0)
            {   
                result+=n/5;
                n/=5;
            }
            return result;
        
    }
}
```
