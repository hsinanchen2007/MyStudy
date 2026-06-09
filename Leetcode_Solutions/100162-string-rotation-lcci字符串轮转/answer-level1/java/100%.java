### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if (s1.length()!=s2.length())
            return false;
        if (s1.equals(s2))
            return true;
        for (int i=0;i<s1.length();i++){
            if (s1.charAt(i)==s2.charAt(0)){
                StringBuilder sb=new StringBuilder();
                sb.append(s1.substring(i)).append(s1.substring(0,i));
                if (sb.toString().equals(s2))
                    return true;
            }
        }
        return false;
    }
}
```