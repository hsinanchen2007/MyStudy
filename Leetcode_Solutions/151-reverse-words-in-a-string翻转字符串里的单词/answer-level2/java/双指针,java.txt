### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        int i = len-1, j = len-1;
        while(i >= 0){
            while(i >= 0 && s.charAt(i) != ' '){
                i--;
            }
            sb.append(s.substring(i+1, j+1) + ' ');
            while(i >= 0 && s.charAt(i) == ' '){
                i--;
            }
            j = i;
        }
        return sb.toString().trim();
    }
}
```