public int lengthOfLongestSubstring(String s) {
    int max = 0;
    int begin = 0;
    for (int i = 0; i < s.length(); i++) {
        int index = s.substring(begin, i).indexOf(s.charAt(i));
        if (index == -1) {
            max = Math.max(max, i - begin + 1);
        } else {
            begin = index + 1 + begin; // 注意此时的index是前面子串的位置，要加上begin才是原字符串的index
        }
    }
    return max;
}