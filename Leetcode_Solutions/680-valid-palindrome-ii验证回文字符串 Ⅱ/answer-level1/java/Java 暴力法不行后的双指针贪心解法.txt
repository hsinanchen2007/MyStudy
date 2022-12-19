### 解题思路

手写思路：

![IMG_0452.PNG](https://pic.leetcode-cn.com/d4df405d2c4d00ad4f40872cbeb3339be8a9e393328b7ed916a87de5909f99bc-IMG_0452.PNG)

整体思路就是贪心算法：

![QQ截图20200201174542.png](https://pic.leetcode-cn.com/98588045dad71bb149c0657fb63c81534c3aaa043336c9d7ad87ac1889668435-QQ%E6%88%AA%E5%9B%BE20200201174542.png)

同时我好心的测评了本题几种解法的执行用时和内存消耗如下：

![IMG_0453.PNG](https://pic.leetcode-cn.com/fc20c8ccfc3e54d1bc50dae3b17c48c70c0566951cbea5a5bd22b92ea559881f-IMG_0453.PNG)

所以我们碰到类似的题还是 将字符串转化为数组 直接访问数组下标快一点；判断回文字符串也用 双指针法 快一点

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        char[] chars = s.toCharArray();
        int i = 0;
        int j = chars.length - 1;
        while (i < j && chars[i] == chars[j]) {
            i++; 
            j--;
        }
        if (isValid(chars,i + 1,j)) return true;
        if (isValid(chars,i,j - 1)) return true;
        return false; 
    }
    private boolean isValid(char[] chars,int i,int j) {
        while (i < j) {
            if (chars[i++] != chars[j--]) {
                return false;
            }
        }
        return true;
    }
}
```