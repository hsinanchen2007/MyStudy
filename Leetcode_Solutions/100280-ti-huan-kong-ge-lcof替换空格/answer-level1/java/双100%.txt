### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if(s.length() == 0) return ""; 
        char[] chars = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(char c:chars){
            if(c == ' '){
                sb.append("%20");
            }else{
                sb.append(c);
            }
        }
        return String.valueOf(sb);
    }
}
```