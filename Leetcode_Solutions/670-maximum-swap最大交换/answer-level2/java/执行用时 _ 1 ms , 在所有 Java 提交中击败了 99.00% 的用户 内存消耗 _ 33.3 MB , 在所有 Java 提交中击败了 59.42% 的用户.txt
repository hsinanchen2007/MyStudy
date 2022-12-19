class Solution {
    public int maximumSwap(int num) {
        String s = String.valueOf(num);
        StringBuilder sb = new StringBuilder();
        int n = 0;
        int m = 0;
        for (int i = 0; i < s.length(); i++) {
            int res = 0;
            boolean flag = false;
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) < s.charAt(j)) {
                    if ((s.charAt(j)-'0') >= res) {
                        n = i;
                        m = j;
                    }
                    res = Math.max(res, s.charAt(j) - '0');
                    flag = true;
                }
            }
            if (flag) {
                break;
            }
        }
        if (n == 0 && m == 0) {
            return num;
        }
        for (int i = 0; i < s.length(); i++) {
            if (n == i) {
                sb.append(s.charAt(m));
            } else if (m == i) {
                sb.append(s.charAt(n));
            } else {
                sb.append(s.charAt(i));
            }
        }
        return Integer.valueOf(sb.toString()); 
    }
}