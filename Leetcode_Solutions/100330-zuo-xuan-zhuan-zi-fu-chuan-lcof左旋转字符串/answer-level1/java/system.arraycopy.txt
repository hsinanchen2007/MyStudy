### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
         char[] chars = s.toCharArray();
        char[] dest = new char[chars.length];
        System.arraycopy(chars,n,dest,0,chars.length-n);
        System.arraycopy(chars,0,dest,chars.length-n,n);
        return String.valueOf(dest);

    }
}
```