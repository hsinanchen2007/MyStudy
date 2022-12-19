### 解题思路
合理运用trim，split后遇到""就跳过

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String string = s.trim();
        String[] strings = string.split(" ");
        int i;
        StringBuffer sb = new StringBuffer();
        for(i=strings.length - 1;i > 0;i--){
            if(strings[i].equals("")) continue;
            sb.append(strings[i] + " ");
        }
          sb.append(strings[i]);
        return sb.toString();
    }
}
```