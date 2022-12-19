### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if(s.length()<0 || s.length()>10000){
            return null;
        }
        
        return s.replace(" ", "%20");
    }
}
```