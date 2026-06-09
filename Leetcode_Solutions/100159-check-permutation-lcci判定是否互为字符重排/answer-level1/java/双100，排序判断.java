### 解题思路
![屏幕快照 2020-02-18 18.58.11.png](https://pic.leetcode-cn.com/d07a8877653abdb3533f9ebe377d405b4047d771bff27ecdc18094649d3ed81c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-18%2018.58.11.png)


### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1.equals(s2)) {
            return true;
        }
        char[] a = s1.toCharArray();
        char[] b = s2.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        return String.valueOf(a).equals(String.valueOf(b));
    }
}
```