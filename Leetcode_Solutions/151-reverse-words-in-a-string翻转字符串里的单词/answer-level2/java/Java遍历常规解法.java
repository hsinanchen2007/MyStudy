```
class Solution {
    public String reverseWords(String s) {
    s = s.trim();
    StringBuilder sb = new StringBuilder();
    int j=s.length(),i=s.length()-1;
    while(i>=0){
        while(i>=0 && s.charAt(i)!=' ') i--;
        sb.append(s.substring(i+1,j));
        sb.append(" ");
        while(i>=0 && s.charAt(i)==' ') i--;
        j=i+1;
        
    }
    return sb.toString().trim();
    }
}
```
