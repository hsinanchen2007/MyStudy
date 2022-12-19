```
class Solution {
    public String convert(String s, int numRows) {
        StringBuffer ret = new StringBuffer("");
        int len = s.length();
        if (numRows == 1) return s;
        int []step = {0, 0};
        for (int i = 0; i < numRows; ++i) {
            step[0] = 2 * numRows - 2 - i * 2;
            step[1] = 2 * numRows - 2 - step[0];
            int flag = 0, last = -1;
            for (int j = i; j < len; j += step[flag], flag ^= 1) {
                if (j == last) continue;
                ret.append(s.charAt(j) + "");
                last = j;
            }
        }
        return ret.toString();
    }
}
```
