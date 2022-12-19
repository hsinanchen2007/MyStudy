- System.arraycopy

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        char [] res = new char[s.length()];
        char [] temp = s.toCharArray();
        System.arraycopy(temp,0,res,s.length() - n,n);
        System.arraycopy(temp,n,res,0,s.length() - n);
        return String.copyValueOf(res);
    }
}
```
- subString

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        return new String(s.substring(n) + s.substring(0,n));
    }
}
```