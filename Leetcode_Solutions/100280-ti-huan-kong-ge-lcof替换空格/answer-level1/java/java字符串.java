### 解题思路
清晰思路题。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        // return s.replaceAll(" ", "%20");
        if(s.length() == 0)
            return s;
        
        String str = "%20";
        char[] chars = s.toCharArray();
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < chars.length; i++){
            if(chars[i] == ' '){
                sb.append(str);
            }
            else{
                sb.append(chars[i]);
            }
        }
        return sb.toString();
    }
}
```