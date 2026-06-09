### 解题思路
根据左旋值k将字符串截成前后两段，重新拼接。

### 代码

```java
class Solution {
     public String reverseLeftWords(String s, int n) {
        String s1 = s.substring(0, n);//第一段
        String s2 = s.substring(n);//第二段
        StringBuffer sb = new StringBuffer();
        sb.append(s2).append(s1);//重新拼接
        String s3 = sb.toString();
        return s3;
    }
}
```