    
    class Solution {
        public int strStr(String haystack, String needle) {
            if(needle.length() == 0) {
                return 0;
            }
            int i = 0, j = 0;
            int[] next = getNext(needle);
            while(i < haystack.length() && j < needle.length()) {
                if(haystack.charAt(i) == needle.charAt(j)) {
                    i++;
                    j++;
                }else {
                    if(j == 0) {  // j已经到了模式串的第一个字符了，退无可退
                        i++;      // 主串老老实实后移吧
                    }else {       // 模式串的j还能后移
                        j = next[j];
                    }
                }
            }
            return j == needle.length() ? i - j : -1;
        }

        public int[] getNext(String s) {
            if(s.length() == 1) {
                return new int[] {-1};
            }
            int[] next = new int[s.length()];
            next[0] = -1;   // 人为规定为-1
            next[1] = 0;    // 人为规定为0，因前面就一个字符，前后缀又不允许是字符串本身
            int i = 2;
            int p = 0;  //p为前缀的后一个字符位置
            while(i < s.length()) {
                if(s.charAt(i - 1) == s.charAt(p)) {
                    next[i] = p + 1;  // 匹配到的前缀长度（为前缀最后一个字符下标 + 1）
                    p++;
                    i++;
                }else {
                    if(p == 0) {      // 你连第一个字符都不匹配，前后缀没有，next为0
                        next[i] = 0;
                        i++;
                    }else {
                        p = next[p];  // 前缀还很长，发生不匹配不慌，再找更小的前缀试试
                    }
                }
            }
            return next;
        }
    }