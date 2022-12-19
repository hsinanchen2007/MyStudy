先求两个数的异或，然后求异或结果的二进制1的个数
```
class Solution {
    public int hammingDistance(int x, int y) {
        int z = x^y;
        int res = 0;
        while(z!=0){
            res++;
            z = z&(z-1);
        }
        return res;
    }
}
```
