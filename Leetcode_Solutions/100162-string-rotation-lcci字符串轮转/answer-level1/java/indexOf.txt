### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isFlipedString(String s1, String s2) {
       if (s1.length()!=s2.length()) 
       return false;
	String num = s2+s2;
	return num.indexOf(s1)!=-1;
    }
}
```