```
class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sB = new StringBuilder();
        for(char c: S.toCharArray()) {
            if(sB.length() != 0 && sB.charAt(sB.length()-1) == c) {
                sB.delete(sB.length() - 1, sB.length());
                continue;
            }
            sB.append(c);
        }
        return sB.toString();
    }
}
```
