```
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuilder tmp = new StringBuilder();

        for(int i = n;i < s.length();i++){
            tmp.append(s.charAt(i));
        }

        for(int i = 0;i < n;i++){
            tmp.append(s.charAt(i));
        }

        return tmp.toString();
    }
}
```
