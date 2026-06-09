```
class Solution {
    public int strStr(String haystack, String needle) {
        if( needle == null || needle.length() == 0)
            return 0;
        if(haystack == null || haystack.length() == 0)
            return -1;
        int i,j;
        for(i = 0;i < haystack.length();i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                j = 0;
                while(haystack.charAt(i + j) == needle.charAt(j)){
                    j++;
                    if(i + j == haystack.length() || j == needle.length())
                        break;
                }
                if(j == needle.length())
                    return i;
            }
        }
        return -1;
    }
}
```
