### 解题思路
一开始想着用字符串的charAt方法，不过耗时居高不下，后改为toCharArray然后遍历。
思路：
1. 通过前后元素异或，如果相同则异或结果为0，计数count++;
2. 当异或不为0，说明发现前后不一致字符，添加进StringBuilder中；
3. 考虑循环是length-1，所以要把最后统计的字符加入

### 代码

```java
class Solution {
    public String compressString(String string) {
        if (Objects.isNull(string) || string.length() <= 2) {
            return string;
        }

        int count = 1;
        char[] chars = string.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < chars.length - 1; i++) {
            if ((chars[i] ^ chars[i + 1]) == 0) {
                count++;
            } else {
                sb.append(chars[i]).append(count);
                count = 1;
            }
        }
        
        sb.append(chars[chars.length - 1]).append(count);

        if (sb.length() >= string.length()) {
            return string;
        } else {
            return sb.toString();
        }
    }
}
```