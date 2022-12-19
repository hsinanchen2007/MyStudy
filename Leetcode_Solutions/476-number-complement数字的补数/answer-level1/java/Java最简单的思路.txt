利用此数加补数的二进制所有位数都为1的性质，先求二进制所有数位都为1的时候的值，再减去当前数字即可
```
class Solution {
    public int findComplement(int num) {
        int powX = 2;
        while(powX - 1 < num){
            powX *= 2;
        }
        powX--;
        return powX - num;
    }
}
```
