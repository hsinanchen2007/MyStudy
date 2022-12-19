class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int len1=s.length();
        int len2=t.length();
        int duration=len1-len2;

        if (duration<-1||duration>1) return false;
        if (len2<len1) {
            return isOneEditDistance(t,s);
        }

        int count=0;

        if (len1!=len2){
        for (int i=0;i<len1;i++){
            if (s.charAt(i)!=t.charAt(i+count)){
                count+=1;
                i--;
                if(count>1) return false;
                }
            }
        }
        if (len1==len2){
            for (int i=0;i<len1;i++){
                if (s.charAt(i)-t.charAt(i)!=0){
                    count+=1;
                    if (count>1) return false;
                }
            }
        }
        if ((len1==len2)&&(count==0)) return false;
        return true;
    }
}

