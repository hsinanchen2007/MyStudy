```
class Solution {
    public String toLowerCase(String str) {
        // return str.toLowerCase();
        
        char[] chr = str.toCharArray();
        for (int i=0; i< chr.length; i++) {
            chr[i] = (char) (chr[i] | ' ');
        }
        return String.valueOf(chr);
        
    }
}
```
遍历字符串，一个一个转