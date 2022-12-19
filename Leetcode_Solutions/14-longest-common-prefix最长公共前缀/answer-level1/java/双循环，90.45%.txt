### 解题思路

1. 首先，你一定要仔细读题，如果面试的话，需要和面试官确认自己对题目的理解是否正确。
2. 然后，你可以看到，是公共前缀，既然是前缀，那么一定是从0开始，否则就不用前缀了。
3. 边界条件需要考虑一下。
4. 然后可以找出数组中，长度最小的一个，作为你要循环匹配的边界，比如数组长度为3，而数组中长度最小为5，
那么5肯定是最外面的循环结束条件，你想一下，对于charAt(0)，你是不是要比较数组中的每一个字符的charAt(0)呢，
那么，自然数组的长度作为里面循环的边界条件。这个应该不难懂的。
5. 有了这几点，可以coding了。

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        int minLen = Integer.MAX_VALUE, len = strs.length, sum = 0;
        for (int i = 0; i < strs.length; i++) {
            minLen = Math.min(minLen, strs[i].length());
        }

        for (int i = 0; i < minLen; i++) {
            char ch = strs[0].charAt(i);
            for (int j = 0; j < len; j++) {
                if (strs[j].charAt(i) != ch) return strs[0].substring(0, sum);
            }
            sum++;
        }
        return strs[0].substring(0, sum);
    }
}
```
![2.png](https://pic.leetcode-cn.com/1c3108730a5eacda596d68c6a0e851da53785a628ed3adfbf04517fefc385959-2.png)
