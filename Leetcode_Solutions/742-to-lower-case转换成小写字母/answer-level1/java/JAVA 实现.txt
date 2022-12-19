```
class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i=0;i<str.length(); i++) {
            char tmp = str.charAt(i);
            if (str.charAt(i)>='A' && str.charAt(i)<='Z') {
                tmp = (char)(tmp + 32);
            }
            sb.append(String.valueOf(tmp));
        }
        return sb.toString();
    }
}
```