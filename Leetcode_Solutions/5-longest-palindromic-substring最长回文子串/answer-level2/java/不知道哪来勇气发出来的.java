### 解题思路
    暴力法Plus：分段截取子字符串，满足头尾一致的就进入递归二次判断是否符合回文；
    一开始直接测试超时挂了，后来调整了一下S'先和当下结果长度做比较，不够长就不看了，
    然后递归来判断是否符合回文规律；
    其实本想进一步优化，截取时候两下标差不满当前res长度时候，可以直接把下标跳跃式增长到
    res.length();包括第一层while，如果当前开始地方到s.length()已经不足res.length()的长度了，
    直接就可以退出while了。虽然这样优化不影响最差运行效率，但至少amortized time可以相对优化。
    参考一下大佬们其他方法了！

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        int beginIndex = 0;
        String res = "";
        while (beginIndex < s.length()) {
            for (int i = beginIndex; i < s.length(); i++) {
                if (s.charAt(beginIndex) == s.charAt(i)) {
                    String sub = s.substring(beginIndex, i + 1);
                    if (sub.length() > res.length()) {
                        boolean isPal = isPalindrome(sub, 0, sub.length() - 1);
                        if (isPal) {
                            res = sub;
                        }
                    }
                }
            }
            beginIndex++;
        }
        return res;
    }

    public boolean isPalindrome(String sub, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (sub.charAt(start) != sub.charAt(end)) {
            return false;
        }
        return isPalindrome(sub, start + 1, end - 1);
    }
}
```