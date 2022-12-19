好像是级别定错了，应该是简单级别的。

class Solution {
    public int distinctEchoSubstrings(String text) {
        Map<String,Integer> map0= new HashMap<>();
        int i = 0 ;
        int j = 1 ;
        int len =text.length();
        for(i=0;i<len;i++){
            j=i+1;
            while(j+j-i<=len)
               {
                    String str0 = text.substring(i,j);
                    String str1 = text.substring(j,j-i+j);
                    j++ ;
                    if(str0.equals(str1)){
                        map0.put(str0,map0.getOrDefault(str0,0)+1);
                    }
                }
            }
        return map0.size() ;
    }
}