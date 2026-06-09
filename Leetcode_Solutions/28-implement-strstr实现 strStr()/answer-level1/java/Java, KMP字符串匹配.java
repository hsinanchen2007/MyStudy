```
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.equals("")) {
            return 0;
        }
        char[] string = haystack.toCharArray();
        char[] pattern = needle.toCharArray();
        
        // index into pattern
        int k = 0;
        
        // index into text
        int j = 0;
        
        // computed by private utility
        int[] next = findNext(needle);
        
        while (j<string.length) {
            // pattern[0..k] matched thus far
			// when k == -1, need to move j
            if (k == -1 || string[j] == pattern[k]) {
                j++;
                k++;
                
                // matched all characters in pattern
                if (k == pattern.length) {
                    return j-pattern.length;
                }
            } else {
                // reuse suffix of P[0..k]
                k = next[k];
            }
        }
        return -1;
    }
    
    public int[] findNext(String needle) {
        char[] chars = needle.toCharArray();
        
        int length = chars.length;
        int k = -1;
        int j = 0;
        int[] next = new int[length];
        next[0] = -1;
        
        while(j<length-1) {
            // no match found or k characters match thus far
            if (k==-1 || chars[k] == chars[j]) {
                k++;
                j++;
                next[j] = k;
            } else {
                // k - 1  follows a matching prefix
                k = next[k];
            }
        }
        return next;   
    }
}
```
