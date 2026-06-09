### 解题思路

![image.png](https://pic.leetcode-cn.com/4964df7bff3d570248e52e281af203138bcd47b89035f55d1c63c8854bde6896-image.png)

### 代码

```java
class Solution {
    public int reverseBits(int num) {
        int cnt1 = 1;
        int pos = -1;
        int result = 0;
        for (int i = 0; i < 33; i++) {
            if ((num & 1) == 1) {
                cnt1++;
            } else {
                result = Math.max(result, cnt1);
                cnt1 = i - pos;
                pos = i;
            }
            num >>>= 1;
        }

        return result;
    }
}
```