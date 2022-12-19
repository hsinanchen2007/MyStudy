### 解题思路
思路是每次取num的最后一位，通过计数器count右移到相应的位置后，与ans进行或操作。

### 代码

```java
class Solution {
    public int exchangeBits(int num) {
        int ans = 0, count = 0;
        while (num > 0) {
            int last = (num & 1); //取得num的最后一位
            num >>= 1;
            if (count % 2 == 0)
                last <<= 1 * (count + 1); 
            else 
                last <<= 1 * (count - 1);
            ans |= last;
            count++;
        }
        return ans;
    }
}
```