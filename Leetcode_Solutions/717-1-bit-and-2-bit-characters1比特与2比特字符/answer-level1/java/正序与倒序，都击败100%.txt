### 解题思路
正序：因为1后面必须搭配0和1，所以每次碰到1就跳过1后面的字符，最终判断是否能到达最后一个字符.

倒序：因为1后面必须搭配0和1，所以最后一个字符是否为1比特就取决于它前面有多少个连续的1，为什么不需要考虑0呢？因为0可以自成1比特，当最后一个字符前面遇到0时，这个0或自成1比特，或与前面的1成2比特，总之不会影响结果.
那么接着思考，连续1的数量怎么影响结果？因为1后面必须搭配0和1，所以结果最终取决于连续1的数量为奇数还是偶数（为0不影响结果，可以归到偶数里面）
（1）为奇数时，前面的1两两搭配（或不存在），多出来的那个1必须与最后的0搭配，结果为false
(2)为偶数时，全部的1两两搭配（或不存在），最后一个字符可以自成1比特，结果为true

正序
```Java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        for (int i = 0; i < bits.length; i++) {
            if (i == bits.length - 1) {
                return true;
            }
            if (bits[i] == 1) {
                i += 1;
            }
        }
        return false;
    }
}
```

倒序
```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int len = bits.length;
        int cnt = 0;
        for (int i = len - 2; i >= 0; i--) {
            if (bits[i] == 1) {
                cnt++;
            } else {
                break;
            }
        }
        return (cnt & 1) == 0;
    }
}
```