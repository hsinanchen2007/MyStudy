### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        String[] strs = s.split(" ");

        for (int i= strs.length-1; i>=0; i--){
            if (!strs[i].equals("")){
                sb.append(strs[i]);
                sb.append(" ");
            } 
        }
        return sb.toString().trim();
    }
}
```