```
class Solution {
    public String longestPrefix(String s) {
        if(s == null || s.length() <2) return "";
        char[] ca = s.toCharArray();
        int[] next = next(ca);
        int n = next.length, k = next[n-1];
        while(k != -1 && ca[k] != ca[n-1]){
            k = next[k];
        }
        return s.substring(0, k+1);
    }

    private int[] next(char[] ca){
        int n = ca.length;
        int[] next = new int[n];
        next[0] = -1;
        int i = 0, k = -1;
        for(; i<n-1;){
            if(k == -1 || ca[i] == ca[k]){
                next[++i] = ++k;
            }else{
                k = next[k];
            }
        }
        return next;
    }
}
```
![kmp.png](https://pic.leetcode-cn.com/c31a7eb156f1d7f30bdf52bb69947a2a04f45df3d75e1a1f8e35af24a30735c5-kmp.png)
