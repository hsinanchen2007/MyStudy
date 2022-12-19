```
class Solution {
    public int lengthOfLastWord(String s) {
        if(s.length()==0)return 0;
        int m=0;
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' '){
                m++;
                k=m;
            }
            else{
                m=0;
            }
        }
        return k;
    }
}
```
