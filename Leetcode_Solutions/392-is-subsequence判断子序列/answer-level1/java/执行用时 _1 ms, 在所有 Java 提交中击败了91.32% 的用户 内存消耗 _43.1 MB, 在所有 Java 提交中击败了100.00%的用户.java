```
class Solution {
    public boolean isSubsequence(String s, String t) {
        int i=0;
        for(char c:s.toCharArray()){
            int index=t.indexOf(c,i);
            if(index==-1) return false;
            i=index+1;
        }
        return true;
    }
}
```
