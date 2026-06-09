刚刚学习$java$喜欢那题来练习语法，这道题也让我学到不少$java$字符串和字符数组的东西。
代码的思想是先去掉字符串首尾的多余的空格，然后从字符串头部扫描到尾部。期间遇到字母计数器加一，遇到空格就将计数器置零，这个应该懂吧，说明有新的单词出现，之前统计的单词要作废了，他显然不是最后一个单词。代码中因为首先将多余空格去掉了，所以中间有一句代码其实是没有必要的，没有去掉是为了保险 [/笑哭]。其实是懒得去掉了。
```
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        char[] ch = s.toCharArray();
        int length = s.length();
        if (s.isEmpty())
            return 0;
        int ans = 0;
        int ANS = 0;
        boolean flag = false;
        for (int i=0; i<length; i++) {
            if (Character.isSpace(ch[i])) {
                if (i<length) {
                    ans = 0;
                    continue;
                } else {
                    return ans;
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
}
```
