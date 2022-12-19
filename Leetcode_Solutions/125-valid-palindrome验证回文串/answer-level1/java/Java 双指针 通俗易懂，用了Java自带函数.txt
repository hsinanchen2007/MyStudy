```

class Solution {
    public boolean isPalindrome(String s) {

        if( s == null)
            return false;
        int i = 0;
        int j = s.length() - 1;
        while( i < j ){
            Character leftC = Character.toLowerCase(s.charAt(i));
            Character rightC = Character.toLowerCase(s.charAt(j));
            if( !Character.isLetterOrDigit(leftC)) 
                i++;
            else if( !Character.isLetterOrDigit(rightC) )
                j--;
            else{
                if( leftC != rightC)
                    return false;
                else{
                    i++;
                    j--;
                }
            }
        }
        return true;
    } 

}
```
