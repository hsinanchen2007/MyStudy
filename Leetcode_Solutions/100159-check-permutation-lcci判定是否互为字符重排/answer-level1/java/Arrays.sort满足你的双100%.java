### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public boolean CheckPermutation(String s1, String s2) {
	        char[] char1 = s1.toCharArray();
	        char[] char2 = s2.toCharArray();
	        Arrays.sort(char1);
	        Arrays.sort(char2);
	        s1 = String.valueOf(char1);
	        s2 = String.valueOf(char2);
	        return s1.equals(s2);
	    }
}
```