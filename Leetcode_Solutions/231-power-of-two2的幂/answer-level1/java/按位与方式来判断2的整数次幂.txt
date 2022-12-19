### 解题思路
看题干
1.是整数，只能是2的正整数次幂，并且只能是大于0的整数
2.2的正整数次幂只有最高位是1，其它位是0
3.当n大于1时，通过判断最后一位和1的按位与的结果，如果大于0，可以判断不是2的整数次幂
4.当n最后等于1时，表明n时2的正整数次幂

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n > 0){
            while(n > 1){
                if((n & 0x01) > 0){
                    return false;
                }
                n = n >> 1;
            }
            return true;
        }else{
            return false;
        }
    }
}
```