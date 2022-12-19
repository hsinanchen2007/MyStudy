
n加上它的一半时，所有位数全为1；比如n为21时，对应二进制为10101.n/2为10，对应二进制为1010，两者相加对应二进制为11111.
接下来判断它每一位是否都是1.
```
class Solution {
    public boolean hasAlternatingBits(int n) {
        n += n/2;
        while(n!=0){
            if(n % 2 != 1){
                return false;
            }
            n >>= 1;
        }
        return true;
    }
}
```
