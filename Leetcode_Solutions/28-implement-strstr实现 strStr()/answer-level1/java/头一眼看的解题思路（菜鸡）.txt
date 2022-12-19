    public int strStr(String haystack, String needle) {
        //空字符串返回0
        if(needle.equals("")) return 0;
        //先判断needle是否存在于haystack中
        if(!haystack.contains(needle)) return -1;
        int j=0;int i=0;
        int needleLength=needle.length();

        while(i<haystack.length()){
            if(haystack.charAt(i)==needle.charAt(j)){
                j++;
            }else {
                i=i-j;
                j=0; 
            }
            if(j==needleLength){
                break;
            }

            i++;
        }
        return i-needleLength+1;
    }
}