### 解题思路
Split后reverse再拼接

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i=arr.length-1;i>=0;i--) {
            if (arr[i].length()>0) {
                sb.append(arr[i]);
                sb.append(" ");
            }
        }
        if (sb.lastIndexOf(" ")>0) {
            sb.deleteCharAt(sb.lastIndexOf(" "));
        }
        return sb.toString();
    }
}
```