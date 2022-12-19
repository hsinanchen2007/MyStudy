```
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0,j = 0;
        while(j < typed.length() || i < name.length()){
            char c1 = '1';
            char c2 = '2';
            if(i < name.length()){
            c1 = name.charAt(i);}
            if(j < typed.length()){
            c2 = typed.charAt(j);}
            if(c1 == c2){
                i++;j++;
            }
            else if(c1 != c2 && j != 0 && c2 == typed.charAt(j - 1))
                j++;
            else
                return false;
        }
        return true;
    }
}
```
