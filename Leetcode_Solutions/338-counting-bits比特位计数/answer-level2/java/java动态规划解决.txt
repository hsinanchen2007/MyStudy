```java
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        res[0] = 0;
        int a = 1, n= 0;
        for(int i = 1; i <= num; i++){
            if(i == (a<<n)){
                res[i] = 1;
                n++;
            }else{
                int idx1 = a<<(n-1);
                int idx2 = i - idx1;
                res[i] = res[idx1]+res[idx2];
            }
        }
        return res;
    }
}
```
对于2的整数幂的数，比特位所含1的个数为1，在2^i到2^i+1之间的数k，例如3等于2^1+1,位于2^1和2^2之间，所含比特1的个数为res[2^i]+res[k-2^i]=1+res[k-2^i];