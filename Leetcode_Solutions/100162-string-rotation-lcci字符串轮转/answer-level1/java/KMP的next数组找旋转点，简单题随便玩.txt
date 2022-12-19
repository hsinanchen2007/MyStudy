    // 找到旋转点拼接起来看和s2是否一样
    class Solution {
        public boolean isFlipedString(String s1, String s2) {
            if(s1.length() != s2.length()) {
                return false;
            }
            if(s1.equals(s2)) {
                return true;
            }
            String s = s1 + "#" + s2 + "@";
            int[] next = new int[s.length()];
            next[0] = -1;
            next[1] = 0;
            int p = 0, i = 2;
            while(i < next.length) {
                if(s.charAt(p) == s.charAt(i - 1)) {
                    next[i] = p + 1;
                    i++;
                    p++;
                }else {
                    if(p == 0) {
                        next[i] = 0;
                        i++;
                    }else {
                        p = next[p];
                    }
                }
            }
            int rotate = next[next.length - 1];
            String cur = s1.substring(rotate) + s1.substring(0, rotate);
            //System.out.println(cur);
            return cur.equals(s2);
        }
    }