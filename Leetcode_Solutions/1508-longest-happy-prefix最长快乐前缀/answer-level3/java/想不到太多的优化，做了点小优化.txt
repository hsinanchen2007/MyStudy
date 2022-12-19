
看到有人用python暴力求解通过，惊到了。所以只要稍微有些优化，都能成功通过。

说说我的速度提升点吧：
> 1. 从前往后检测，这样只要找到一个就一定是最长的，不需要继续检测了（这一点不应该算优化，只是个小技巧而已）
> 2. 用一个数组存储重复个数（这点是从超时案例中得到的启发），这样可以节省大量重复比较（主要是本题字符集只有26个英文字母，所以这个优化对性能提升很大）

定义一个长度为字符串长度的数组repeatCount，repeatCount[i]存储第i个位置开始重复字符的个数，这样每次检测完这个字符之后就可以直接将指针 +repeatCount[i]

没什么大的优化，直接贴代码吧，执行用时11 ms

```java
class Solution {
    public String longestPrefix(String s) {
        char[] chars = s.toCharArray();
        
        int[] repeatCount = new int[s.length()];
        int lastIndex = s.length() - 1;
        char lastChar = chars[lastIndex];
        repeatCount[lastIndex] = 1;
        for (int i = s.length() - 2; i >= 0; i--) {
            if (chars[i] != lastChar) {
                lastIndex = i;
                lastChar = chars[lastIndex];
            }
            repeatCount[i] = lastIndex - i + 1;
        }
        
        for (int i  = 1; i < chars.length; i++) {
            if (chars[0] != chars[i]) {
                continue;
            }
            
            int k = 1;
            boolean valid = true;
            for (; k + i < chars.length; ) {
                if ((chars[k] ^ chars[k + i]) != 0 || repeatCount[k + i] > repeatCount[k]) {
                    valid = false;
                    break;
                }
                k += repeatCount[k + i];
            }

            if (valid) {
                return new String(chars, i, k);
            }
        }
        
        return "";
    }
}
```

![image.png](https://pic.leetcode-cn.com/0a9bd09f19b1971b3af1cb5964cb0d4830db7f34c2ab19cd744032a215c9f494-image.png)
