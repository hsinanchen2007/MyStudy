### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if("".equals(s)){
            return true;
        }
        int len = s.length();
        String str1 = "\\[\\]", str2 = "\\(\\)", str3 = "\\{\\}";
        for (int i = 0; i < len; i++) {
            if(s.contains("[]")){
                s = s.replaceAll(str1, "");
            }
            if(s.contains("()")){
                s = s.replaceAll(str2,"");
            }
            if(s.contains("{}")){
                s = s.replaceAll(str3,"");
            }
            if("".equals(s)){
                return true;
            }
            len--;
        }
        return false;
    }
}
```