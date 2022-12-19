class Solution {
    public String addBoldTag(String S, String[] words) {
         int N = S.length();
        boolean[] flag = new boolean[N];
        for (int i = 0; i < N; ++i) {
            // S的起始的字符，每个都要遍历到，避免出现相邻字符相同的情况
            for (String word : words) {
                // S以i起始的字符长度为word.length(),是否和word匹配
                if (!match(S, i, i + word.length(), word)) {
                    // 不匹配则看下一个word
                    continue;
                }
                // 匹配则置标记位
                for (int j = i; j < i + word.length(); ++j) {
                    flag[j] = true;
                }
            }
        }

        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < flag.length; i++) {
            if ((i == 0 && flag[i]) || (flag[i] == true && flag[i - 1] == false)) {
                stringBuffer.append("<b>");
            }
            stringBuffer.append(S.charAt(i));
            if ((i == flag.length - 1 && flag[i]) || (flag[i] == true && flag[i + 1] == false)) {
                stringBuffer.append("</b>");
            }
        }
        return stringBuffer.toString();
    }
    
     /**
     * 字符串S从i到j是否和字符串T从i到j匹配
     * 这里调用的时候 j - i就是T的长度，即代表S中从i到j是否和T一致
     * @param S 源字符串
     * @param i 起始位置
     * @param j 终点
     * @param T 目标字符串
     * @return 是否匹配
     */
    public boolean match(String S, int i, int j, String T) {
        for (int k = i; k < j; ++k)
            if (k >= S.length() || S.charAt(k) != T.charAt(k - i))
                return false;
        return true;
    }
}