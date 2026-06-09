```
class Solution {
    public String reverseOnlyLetters(String S) {
        char[] ch = S.toCharArray();
        int i = 0,j = 0;
        StringBuilder sb = new StringBuilder();
        for(i = 0 ; i < S.length();i++){
            if((S.charAt(i) > 64 && S.charAt(i) < 91) || (S.charAt(i) > 96 && S.charAt(i) < 123))
                sb.append(S.charAt(i));
        }
        char[] ch1 = sb.toString().toCharArray();
        i = 0;
        j = ch1.length - 1;
        while(i < ch.length || j >= 0){
            if(i == ch.length || j == -1) break;
            if((ch[i] > 64 && ch[i] < 91) || (ch[i] > 96 && ch[i] < 123)){
                ch[i] = ch1[j];
                i++;j--;
            }
            else
                i++;
        }
        String ss = String.valueOf(ch);
        return ss;
    }
}
```
