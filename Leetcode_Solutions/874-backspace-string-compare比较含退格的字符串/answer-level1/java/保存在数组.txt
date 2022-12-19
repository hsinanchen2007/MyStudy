```
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i, j, k;
        char[] charS, charT;

        i = 0;
        j = 0;
        charS = new char[S.length()];
        charT = new char[T.length()];
        for(k = 0; k < S.length(); k++){
            if(S.charAt(k) == '#'){
                if(i > 0)
                    i--;
            }
            else
                charS[i++] = S.charAt(k);
        } 
        for(k = 0; k < T.length(); k++){
            if(T.charAt(k) == '#'){
                if(j > 0)
                    j--;
            }
            else{
                charT[j++] = T.charAt(k);
            }
        } 
        if(i != j)
            return false;
        for(k = 0; k < i; k++)
            if(charS[k] != charT[k])
                return false;
        return true;
    }
}
```
