### 解题思路

![5E548F93AFF450CE620E0C270289A2E2.png](https://pic.leetcode-cn.com/7d8840571c75e8e8d5963961a6110b84f10daa02268fd1171965b5bfe92f0725-5E548F93AFF450CE620E0C270289A2E2.png)


### 代码

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String ss = s+s;
		ss = ss.substring(1,ss.length()-1);	
		return ss.contains(s);
    }
}
```