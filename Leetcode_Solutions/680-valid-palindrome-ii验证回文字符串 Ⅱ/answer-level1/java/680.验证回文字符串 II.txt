```
class Solution {
    public boolean validPalindrome(String s) {
        int length = s.length();
        int flag = -1;
        for(int i = 0; i < length/2 ; i ++){
            if(s.charAt(i) != s.charAt(length-1-i))
            {
                flag = i;
                break;
            }
        }
        boolean f = true;
        if(flag != -1){
            for(int i = flag; i < length/2 ; i ++){
                if(s.charAt(i+1) != s.charAt(length-1-i))
                {
                    f = false;
                    break;
                }
            }
        }
        if(f == false){
            f = true;
            for(int i = flag; i < length/2 ; i ++){
                if(s.charAt(i) != s.charAt(length-2-i))
                {
                    f = false;
                    break;
                }
            }
        }
        return f;
    }
}
```
