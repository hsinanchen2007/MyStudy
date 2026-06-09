
```
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index = -1;
        for (char a : s.toCharArray()){
            index = t.indexOf(a,index + 1);
            if (index == -1)
                return false;
        }
        return true;
    }
}
```
