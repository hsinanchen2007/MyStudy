```
class Solution {
    public String toHexspeak(String num) {
        String numStr1 = Long.toHexString(Long.parseLong(num));
        String target = "ABCDEF10";
        String numStr = numStr1.toUpperCase();
        String s = "";
        for (int i =0 ;i<numStr.length();i++) {
            char c = numStr.charAt(i);
            if (! target.contains(c + "") ) {
                return "ERROR";
            }
            if (c == '1') {
                s += 'I';
                continue;
            }

            if ( c == '0') {
                s += 'O';
                continue;
            }

            s += c;
        }
        return s;
    }
}
```
