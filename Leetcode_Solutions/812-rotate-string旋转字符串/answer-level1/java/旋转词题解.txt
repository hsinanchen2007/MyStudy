### 解题思路
将字符串A加上自己本身，如果是旋转词的话，那么新生成的T必然包括B；
### 代码

```java
class Solution {
    public boolean rotateString(String A, String B) {
        if(A.length()!=B.length()){
            return false;
        }
      String t = A+A;
       return t.contains(B);
    }
}
```