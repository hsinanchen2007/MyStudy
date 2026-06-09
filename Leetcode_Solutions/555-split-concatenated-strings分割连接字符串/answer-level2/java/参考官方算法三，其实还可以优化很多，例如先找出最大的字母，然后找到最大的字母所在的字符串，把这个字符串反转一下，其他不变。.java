class Solution {
    public String splitLoopedString(String[] strs) {
        int n=strs.length;
        int i,j,k;
        String ret="";
        String [] strBiger = new String[strs.length];
        String [] strRever = new String[strs.length];        
        for(i=0;i<n;i++){
            String rev = (new StringBuilder(strs[i])).reverse().toString();
            strRever[i]=rev;
            if(strs[i].compareTo(rev)>0){
                strBiger[i]=strs[i];
            }
            else{
                strBiger[i]=rev;
            }
        }
        for(i=0;i<n;i++){
            for(String str:new  String [] {strs[i],strRever[i]}){
                int count=n-1;
                j=i+1; 
                StringBuilder tmp = new StringBuilder();
                tmp.append(str);
                while(count>0){
                    if(j==n){
                        j=0;
                    }
                    tmp.append(strBiger[j]);
                    count--;
                    j++;
                }
                for(k=0;k<str.length();k++){
                    StringBuilder ss = new StringBuilder();
                    ss.append(tmp.substring(k));
                    ss.append(tmp.substring(0,k));
                    if(ret.compareTo(ss.toString())<0){
                        ret = ss.toString();
                    }
                }
            }
        }
        return ret;
    }
}