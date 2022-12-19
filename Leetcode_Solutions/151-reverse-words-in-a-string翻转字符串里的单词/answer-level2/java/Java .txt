执行用时 :9 ms, 在所有 Java 提交中击败了52.47% 的用户
内存消耗 :37.3 MB, 在所有 Java 提交中击败了95.81%的用户

思路：翻转每一个单词，最后翻转整体
如：
    the sky is blue
    翻转每一个单词
    eht yks si eulb
    翻转整个字符串
    blue is sky the
    
```
class Solution {

    private static final char NULL_CHAR = ' ';

    public String reverseWords(String s) {

        StringBuilder sb = new StringBuilder();
        for (int i = 0, len = s.length(); i < len; i++) {
            //越过所有空格字符 找到第一个字母
            while (i < len && s.charAt(i) == NULL_CHAR) i++;
            //如果已经超过字符串长度 则直接退出
            if (i == s.length()) break;
            // 单词起点
            int begin = i;
            // 继续往后位移直到遇见空格则表明从begin到i-1 是一个单词
            while (i < len && s.charAt(i) != NULL_CHAR) i++;
            i--;
            // 单词终点
            int end = i;
            // 反转每一个单词(从后往前追加)
            while (end >= begin) {
                sb.append(s.charAt(end));
                end--;
            }
            //每个单词用空格隔开
            sb.append(" ");
        }

        //将单词翻转后拼接的字符串去除空格 整体字符串反转一次，则获得想要的答案了。
        return new StringBuilder(sb.toString().trim()).reverse().toString();
    }
}
```
