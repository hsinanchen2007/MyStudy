### 解题思路
主要思路就是对上一个元素进行比较，如果相同则计数+1，否则append上一个元素及计数到可变数组对象，最后比较输出

### 代码

```java
class Solution {
    public String compressString(String s) {
        char[] chars = s.toCharArray();
        StringBuilder stringBuilder = new StringBuilder();
        int count = 0;
        if(chars.length == 1) {
            return s;
        }
        for (int i = 0; i < chars.length; i++) {
            if (i == 0) {
                count ++;
                continue;
            }
            if (chars[i] != chars[i-1]) {
                stringBuilder.append(chars[i-1]).append(count);
                count = 0;
                count ++;
            } else {
                count ++;
            }
            if(i == chars.length - 1) {
                stringBuilder.append(chars[i]).append(count);
            }
        }
        if (stringBuilder.length() < chars.length) {
            return stringBuilder.toString();
        } else {
            return s;
        }
    }
}
```