```
class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer cs = new StringBuffer();
        for(char c:s.toLowerCase().toCharArray()){
            if(c>='0'&&c<='9'||c>='a'&&c<='z'){
                cs.append(c);
            }
        }
        return cs.toString().indexOf(cs.reverse().toString())==0;
    }
}
```
