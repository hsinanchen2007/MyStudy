```
class Solution {
    public boolean isUnique(String astr) {
        for(int i=0; i<astr.length()-1;i++){
            char c = astr.charAt(i);
            if(astr.indexOf(c)!=astr.lastIndexOf(c)){
                return false;
            }
        }
        return true;
    }
}
```