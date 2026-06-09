因为2的幂词方的二进制数只有一个1，可以使该数字不断右移。当移出第一个1之后，如果此时的数字为0，则为true，反之为false
```
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        while(n-((n>>>1)<<1)!=1){
            n=n>>>1;
        }
        if ((n>>>1)!=0)
            return false;
        else
            return true;
    }
}
```
