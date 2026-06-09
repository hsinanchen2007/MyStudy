这道题的核心思想是将一个数字的二进制变化为只有最高位为1，其余为0。我们可以根据不同bit逐位判断。

如果数位上是0，直接到下一个bit并且步数+1；如果是1，则步数+2，并且根据下一位到底是1/0，执行加减操作。如果下一位同为1，则+1（一步去掉2个‘1’）；如为0，则-1。（即不做任何操作）
```
class Solution {
public:
    int integerReplacement(int n) {
        int ret = 0;
        while(n > 3){
            if(n % 2){
                n >>= 1;
                if(n % 2) n ++;
                ret += 2;
            }
            else{
                n >>= 1;
                ret++;
            }
        }
        return ret + n - 1;
    }
};
```
