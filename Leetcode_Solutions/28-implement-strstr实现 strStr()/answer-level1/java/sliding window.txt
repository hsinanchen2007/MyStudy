```
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length()>haystack.length()) return -1;
        if(needle.length()==0 && haystack.length()==0 ) return 0;
         char[] hay = haystack.toCharArray();
         char[] nee= needle.toCharArray();
         int i;
         int j=needle.length()-1;
         for( i=0;j<haystack.length();i++,j++){
            char []arr= Arrays.copyOfRange(hay, i, j+1);
             if(Arrays.equals(arr, nee)){
                 return i;
             }
         }
         return -1; 
    }
}
```
