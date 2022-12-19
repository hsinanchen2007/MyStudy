```
class Solution {
    private final char[][] mapping = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    public int count = 0;
    public int strobogrammaticInRange(String low, String high) {
        int lo = low.length();
        int hi = high.length();
        for(int n = lo; n <= hi; n++) {
            char[] chs = new char[n];
            getStrobogrammatic(chs, 0, chs.length - 1, low, high);
        }
        return count;

    }

    public void getStrobogrammatic(char[] chs, int lo, int hi, String low, String high) {
        if(lo > hi) {
            if(chs.length == 1 || chs[0] != '0') {
                String str = String.valueOf(chs);
                if(compare(str, low) && compare(high, str)) {
                    count++;
                }
            }
            return;
        }
        for(char[] map : mapping) {
            if(lo == hi && map[0] != map[1]) continue;
            chs[lo] = map[0];
            chs[hi] = map[1];
            getStrobogrammatic(chs, lo + 1, hi - 1, low, high);
        }
    }

    public boolean compare(String s1, String s2) {
        if(s1.length() == s2.length()) {
            if(s1.compareTo(s2) >= 0) {
                return true;
            }else {
                return false;
            }
        }
        return true;
    }
}
```
