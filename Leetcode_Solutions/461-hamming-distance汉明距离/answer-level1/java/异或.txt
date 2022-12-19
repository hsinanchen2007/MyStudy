### 解题思路
异或
转二进制
输出为1的个数

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int z = x ^ y;
        String str = Integer.toString(z, 2);
        char[] chars = str.toCharArray();
        int result = 0;
        for (char ch : chars) {
            if (ch == '1') {
                result++;
            }
        }
        return result;
    }
}
```