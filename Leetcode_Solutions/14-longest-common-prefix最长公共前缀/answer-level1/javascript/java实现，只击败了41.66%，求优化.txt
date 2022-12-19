```
 //最长公共前缀,最长公共前缀,最长公共前缀
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0){
            return "";
        }
        if(strs.length==1){
            return strs[0];
        }
        String s0 = strs[0];
        int end = 0;
        boolean yes = false;
        for(int j=1;j<=s0.length();j++){
            String regs = s0.substring(0,j);
            boolean b = true;
            for(int k=1;k<strs.length;k++){
                if(!strs[k].startsWith(regs)){
                    b = false;
                    break;
                }
            }
            if(!b){
                 break;  
            }else{
                end = j;
                yes = true;
            }
        }
        if(yes){
            return s0.substring(0,end);
        }
        return "";
    }
```


