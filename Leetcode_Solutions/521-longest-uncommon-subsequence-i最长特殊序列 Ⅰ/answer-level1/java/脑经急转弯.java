### 解题思路
这道题目最重要的是理解题意：

    1. a是a的子序列；
    2. a.length() != b.length()，如a.length() > b.length()，则a不是b的子序列，结果为a的长度； 
    3. a.length() == b.length()时，a和b相同，则结果为-1，否则为a.length();

![图片.png](https://pic.leetcode-cn.com/4e3f9ac276e0da8c8db37619f9a21cf54ecaafeecc6f0263d7b14c8a7555051e-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int findLUSlength(String a, String b) {
        return a.equals(b) ? -1: Math.max(a.length(), b.length());
    }
}
```