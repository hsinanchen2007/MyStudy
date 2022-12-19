```java
class Solution {
    public boolean validUtf8(int[] data) {
        int expectByte = 0; // 期待接下来出现的byte数
        for (int i = 0; i < data.length; i++) {
            // 获取开始的1的个数
            int leadingOne = leadingOne(data[i]);
            if (expectByte == 0) {
                // 字符开头
                if (leadingOne == 1 || leadingOne > 4) return false;
                else expectByte = Math.max(0, leadingOne - 1);
            } else if (leadingOne != 1) {
                // 字符中间，此时leadingOne只能是1
                return false;
            } else {
                expectByte--;
            }
        }
        return expectByte == 0;
    }

    private int leadingOne(int num) {
        int mask = 1 << 7;
        int count = 0;
        while ((num & mask) != 0) {
            count++;
            mask >>= 1;
        }
        return count;
    }
}
```
