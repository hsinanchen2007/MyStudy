### 解题思路
![屏幕快照 2020-02-12 11.04.49.png](https://pic.leetcode-cn.com/cea371bae3ee94bd181e041f730cdb9f59b6b8ead3381e61b83a3bdbdfbf3a9c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-12%2011.04.49.png)


### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        // 一位的肯定是，大于1位的只要倒数第二位是0 那就返回true
        if (bits.length == 1 || bits[bits.length - 2] == 0) {
            return true;
        }
        // 从倒数第二个开始，从后向前查看，每次跳动2个距离，如果bits[i] == 0,则返回true
        for (int i = bits.length - 2; i >= 0 && bits[i] != 0; i-=2) {
            // 只要遍历到0，那就不是，当前坐标和前一个对比，不同也不是
            if (i == 0 || bits[i] != bits[i - 1]) {
                return false;
            }
        }
        return true;
    }
}
```