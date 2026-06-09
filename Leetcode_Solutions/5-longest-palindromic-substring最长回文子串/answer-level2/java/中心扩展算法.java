class Solution {
    public String longestPalindrome(String s) {
        if(s.length()==0){
            return "";
        }

        int start=0;
        int end=0;
        int len=0;
        for(int i=0;i<s.length();i++){
            int len1=longestLength(i,i,s);
            int len2=longestLength(i,i+1,s);
            len=Math.max(len1,len2);
            if(len>end-start+1){
                start=i-(len-1)/2;
                end=i+len/2;
            }     
        }      
        return s.substring(start,end+1);
    }

    private int longestLength(int L, int R, String s){
            while(L>=0 && R<s.length() && s.charAt(L)==s.charAt(R)){
                --L;
                ++R;
            }
            return R-L-1;
        }
}