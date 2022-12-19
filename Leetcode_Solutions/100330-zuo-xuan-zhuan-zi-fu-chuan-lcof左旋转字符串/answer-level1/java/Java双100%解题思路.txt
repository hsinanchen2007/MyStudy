### 解题思路
    题目中的向左旋转可理解为：提取字符串s的前n项，拼接到字符串后面。
![100.png](https://pic.leetcode-cn.com/1557594d7a183baae8690ccbb2e3ec7f91923895ab12c6300ab9ae7f2ddb1d13-100.png)



### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        String str = "";
        str = s.substring(n,s.length());
        str += s.substring(0,n);
        return str;
    }
}
```