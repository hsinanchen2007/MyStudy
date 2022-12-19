### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public static  boolean isValid(String s) {
     char[] chars = s.toCharArray();
        if (chars.length%2!=0){//基数肯定不是
            return false;
        }
        if (s.isEmpty()) return true;
        for (int i=0;i<chars.length/2;i++){
            s = s.replaceAll("\\(\\)","")
                    .replaceAll("\\[\\]","")
                    .replaceAll("\\{\\}","");
            if (s.isEmpty()) return true;
        }
        return false;
   }
}
```