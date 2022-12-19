```
class Solution {
    public int[] diStringMatch(String S) {
        int[] aa = new int[S.length()+1];
        int end = S.length();
        int start = 0;
        for (int i=0; i<S.length(); i++) {
            if (S.charAt(i) == 'I') {
                aa[i] = start;
                start++;
            }else{
                aa[i] = end;
                end--;
            }
        }
        aa[S.length()] = S.charAt(S.length()-1) == 'I' ? start : end;
        return aa;
    }
}
```