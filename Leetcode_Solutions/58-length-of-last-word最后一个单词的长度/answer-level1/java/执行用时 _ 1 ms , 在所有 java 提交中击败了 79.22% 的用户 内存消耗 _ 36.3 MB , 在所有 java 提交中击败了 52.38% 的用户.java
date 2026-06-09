```
class Solution {
    public int lengthOfLastWord(String s) {
        
        String[] str = s.split(" ");
        int a=str.length;
        return a==0?0:str[a-1].length();
    }
}
```
