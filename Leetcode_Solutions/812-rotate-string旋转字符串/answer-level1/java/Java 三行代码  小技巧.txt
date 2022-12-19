### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean rotateString(String A, String B) {
        if(A.length()!=B.length())  return false;
        StringBuffer res=new StringBuffer(B).append(B);
        return res.toString().contains(A);        
    }
}
```