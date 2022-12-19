class Solution {
    public int strStr(String haystack, String needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        if(needleLen==0){
            return 0;
        }
        if(needleLen>haystackLen){
            return -1;
        }else if(needleLen==haystackLen){
            if(haystack.equals(needle)){
                return 0;
            }
        }else{
            for(int i=0;i<=haystackLen-needleLen;i++){
                if(haystack.substring(i,i+needleLen).equals(needle)){
                    return i;
                }
            }
        }
		return -1;
    }
}