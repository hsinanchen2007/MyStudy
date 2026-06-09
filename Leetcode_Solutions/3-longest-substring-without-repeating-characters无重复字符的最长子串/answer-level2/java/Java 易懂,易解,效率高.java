**1.以下解法对官方题解进行了改进;
2.定义了一个长度为boolean类型的数组,默认为false;
3.定义两个指针遍历s,先让end开始,如果该字符在boolean数组中为false,表明没有被标记过(或二次标记为false),这时标记true,end++,并计算ans长度,如果对应标记为true,则表明重复,从start开始直到出现重复的字符的位置结束标记为false;
4.完结。**

        public int lengthOfLongestSubstring(String s) {
            boolean[] letter = new boolean[128];
            int start = 0, end = 0, ans = 0;
            while (end < s.length()) {
                if (!letter[s.charAt(end)]) {
                    letter[s.charAt(end++)] = true;
                    ans = Math.max(ans, end - start);
                } else {
                    letter[s.charAt(start++)] = false;
                }
            }
            return ans;
        }