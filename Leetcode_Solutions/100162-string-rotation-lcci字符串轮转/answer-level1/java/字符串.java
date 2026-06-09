### 解题思路
这一题前面有过类似的思想。添加一份查看是否有就行了。

### 代码

```java
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if(s1.length()!=s2.length())
            return false;
        
        if(s1.equals(s2))
            return true;

        s1 += s1;
        return s1.contains(s2);
    }
}
```