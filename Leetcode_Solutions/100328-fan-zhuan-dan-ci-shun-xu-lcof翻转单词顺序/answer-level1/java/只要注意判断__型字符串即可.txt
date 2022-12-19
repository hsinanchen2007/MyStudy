### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] strings = s.trim().split(" ");
        System.out.println(strings.length);
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = strings.length - 1; i >= 0; i--) {
            if (strings[i].equals("")) {
                continue;
            }
            if (i == 0) {
                stringBuffer.append(strings[i].trim());
            } else {
                stringBuffer.append(strings[i].trim()).append(" ");
            }
        }
        return stringBuffer.toString();
    }
}
```