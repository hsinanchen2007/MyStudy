### 解题思路

### 代码

```java
class Solution {
    public static boolean isValid(String s) {
        int n = 0;
        while(s.length()!=0){
            n++;
            if(n==20000){
                return false;
            }
            s = s.replaceAll("\\(\\)","");
            s = s.replaceAll("\\{}","");
            s = s.replaceAll("\\[]","");
        }
        return true;
    }

}
```