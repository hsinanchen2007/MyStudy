# C
```
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";
    char *commonPrefix = *strs;
    for(int i = 1; i < strsSize; i++) {
        int j = 0;
        while(*(commonPrefix + j) != '\0' && *(*(strs + i) + j) != '\0' && *(commonPrefix + j) == *(*(strs + i) + j)) {
            j++;
        }
        *(commonPrefix+j) = '\0';
    }
    return commonPrefix;
}
```
# Java
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
        String first = strs[0];
        for(int i = 1; i < strs.length; i++) {
            int length = first.length() < strs[i].length()? first.length() : strs[i].length();
            int j = 0;
            for(; j < length; j++) {
                if(first.charAt(j) != strs[i].charAt(j)) {
                    break;
                } 
            }
            first = first.substring(0, j);
        }
        return first;
    }
}
```
