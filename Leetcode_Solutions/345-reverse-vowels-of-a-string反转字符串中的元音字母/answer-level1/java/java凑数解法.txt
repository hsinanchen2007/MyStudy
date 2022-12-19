```
class Solution {
    public String reverseVowels(String s) {
        char[] vowels = new char[]{'a', 'e', 'i', 'o', 'u'};
        char[] source = s.toCharArray();
        boolean lb = false;
        boolean rb = false;
        int l = 0, r = source.length - 1;
        while(l < r) {
            if(source[l] == 'a' || source[l] == 'e' || source[l] == 'i' || source[l] == 'o' || source[l] == 'u' || source[l] == 'A' || source[l] == 'E' || source[l] == 'I' || source[l] == 'O' || source[l] == 'U') {
                lb = true;
            }
            if(source[r] == 'a' || source[r] == 'e' || source[r] == 'i' || source[r] == 'o' || source[r] == 'u' || source[r] == 'A' || source[r] == 'E' || source[r] == 'I' || source[r] == 'O' || source[r] == 'U') {
                rb = true;
            }
            if(lb && rb) {
                char temp = source[l];
                source[l] = source[r];
                source[r] = temp;
                l++;
                r--;
                lb = false;
                rb = false;
            } else if(lb) {
                r--;
            } else if(rb) {
                l++;
            } else {
                l++;
                r--;
            }
        }
        StringBuilder sb  = new StringBuilder();
        for(char c : source) {
            sb.append(c);
        }
        return sb.toString();
    }
}
```
