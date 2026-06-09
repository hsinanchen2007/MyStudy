```
class Solution {
    public String countAndSay(int n) {
        String[] strings = new String[31];
        strings[1] = "1";
        strings[2] = "11";
        strings[3] = "21";
        strings[4] = "1211";
        strings[5] = "111221";
        for (int i = 6; i <= n; i++) {
            String ts = strings[i - 1], rs = "";
            char tc = ts.charAt(0);
            int cnt = 0;
            for (char c: ts.toCharArray()) {
                if (c == tc) {
                    cnt++;
                } else {
                    rs = rs + cnt + tc;
                    tc = c;
                    cnt = 1;
                }
            }
            rs = rs + cnt + tc;
            strings[i] = rs;
        }
        return strings[n];
    }
}

```
