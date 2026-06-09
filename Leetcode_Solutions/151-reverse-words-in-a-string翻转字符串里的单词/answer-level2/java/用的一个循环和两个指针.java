对字符串从后往前遍历
在遇到空格的时候用三种情况
1.第一次遇到空格：添加单词（指针i+1到指针tail+1的位置的字符）
2.中间的空格：继续循环
3.是最后一个空格：移动tail指针

class Solution {
    public String reverseWords(String s) {
        if (null == s)
            return s;

        /**
         * 1.首先处理掉前后的空格
         */
        s = s.trim();
        char[] chars  = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        int tail = chars.length - 1;
        for (int i = chars.length - 1; i >= 0; i--) {
            if (chars[i] == ' '){
                if (chars[i+1] != ' '){
                    // 遇到一个单词前的空格'
                    sb.append(s.substring(i+1,tail+1));
                    sb.append(" ");
                }
                if (chars[i-1] != ' ') {
                    // 遇到连续空格
                    tail = i -1;
                }
            } else if (i == 0) {
                sb.append(s.substring(0,tail+1));
            }
        }
        return sb.toString().trim();
    }
}