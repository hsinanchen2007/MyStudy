适用于正负数
```java []
class Solution {
    public int getSum(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        int res=0,carrier=0;
        while(b!=0){
            res=a^b;
            carrier=a&b;
            a=res;
            b=carrier<<1;
        }
        return res;
    }
}
```
