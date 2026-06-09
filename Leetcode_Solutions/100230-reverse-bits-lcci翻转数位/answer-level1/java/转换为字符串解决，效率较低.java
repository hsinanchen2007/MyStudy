### 解题思路
补齐32位，字符串按0拆分。很好理解

### 代码

```java
class Solution {
    public int reverseBits(int num) {
        String bs = Integer.toBinaryString(num);
        int count = 32 - bs.length();
        if (count > 0) {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < count; ++i)
                builder.append('0');
            bs = builder.append(bs).toString();
        }
        // 按0拆分为数组
        String[] arr = bs.split("0");
        int max = 0;
        for (int i = 1; i < arr.length; ++i)
            max = Math.max(arr[i].length() + arr[i - 1].length(), max);
        return max + 1;
    }
}
```