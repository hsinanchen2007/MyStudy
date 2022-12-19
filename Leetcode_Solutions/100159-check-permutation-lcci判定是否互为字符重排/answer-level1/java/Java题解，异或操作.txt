```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        // 异或操作：0^0=0， 1^0=1， 0^1=1， 1^1=0
        if(s1.length()!=s2.length()){
            return false;
        }
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        int res = 0;
        for(int i=0;i<c1.length;i++){
            res ^= c1[i]^c2[i];
        }
        return res==0;
    }
}
```
