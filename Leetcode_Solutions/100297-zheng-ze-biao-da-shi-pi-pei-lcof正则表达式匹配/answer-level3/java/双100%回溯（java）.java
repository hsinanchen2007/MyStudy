## 题目分析
pattern能够支持的特殊字符只有.以及\*，那么题设隐含一个意思就是\*必须跟在另外一个字符后面。
这题我考虑到可以根据pattern对s进行校验匹配，也就是对每个独立的pattern子项，在s已经匹配的基础上，进行进一步穷举搜索，所以可以使用回溯法。

## 实现分析
已知我们要根据pattern子项使用回溯法，首先要确定可以割裂的pattern子项，分析有以下几项：
1. 字符或者.
3. 字符+\*

考虑到题设，没有对参数进行格式校验，也不考虑null值情况，不过我认为这里抛出NPE是合理的。

通过列举子项，可以看到处理可以分两类，一种是带\*，一种不带，带\*的逻辑处理要考虑很多情况，但是我们知道\*一定在某个字符后面，所以从后往前匹配比较方便（从前往后的话，边缘检查更麻烦一点）。同时我们用两个变量维护两个字符串的匹配位置，通过匹配位置可以完成回溯的退出。

具体代码如下：
```
class Solution {
    public boolean isMatch(String s, String p) {
        return isMatch(s, p, s.length() - 1, p.length() - 1);
    }

    private boolean isMatch(String s, String p, int si, int pi) {
        if (pi < 0) {
            return si < 0;
        }

        // 存在*匹配
        if (p.charAt(pi) == '*') {
            int newPI = pi - 2;
            if (isMatch(s, p, si, newPI)) {
                return true;
            }

            // 找到最大匹配
            int leastBegin = si;
            char c = p.charAt(pi - 1);
            if (c == '.') {
                leastBegin = -1;
            } else {
                while (leastBegin >= 0 && s.charAt(leastBegin) == c) {
                    leastBegin--;
                }
            }
            // 从最大匹配开始回溯
            for (int i = leastBegin; i < si; i++) {
                if (isMatch(s, p, i, newPI)) {
                    return true;
                }
            }
            return false;
        } else {
            // 当前存在字符，但是待匹配字符为空，或无法匹配
            if (si < 0 || (s.charAt(si) != p.charAt(pi) && p.charAt(pi) != '.')) {
                return false;
            } else {
                return isMatch(s, p, si - 1, pi - 1);
            }
        }
    }
}
```