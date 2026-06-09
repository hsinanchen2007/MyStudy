```
class Solution {
    public String toLowerCase(String str) {
        char[] ch = str.toCharArray();
        int i;
        for(i = 0;i < str.length();i++){
            if(ch[i] >= 65 && ch[i] <=90){
                ch[i] = (char)(ch[i] + 32);
            }
        }
        return String.valueOf(ch);
    }
}
```
