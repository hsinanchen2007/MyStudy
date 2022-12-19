class Solution {
    public String replaceSpace(String s) {
        char[] chars = s.toCharArray();
        int len = chars.length;
        for(int i=0;i<chars.length;i++){
            if(chars[i]==' '){
                len+=3;
            }
        }
        char[] res = new char[len];
        for(int j=chars.length-1;j>=0;j--){
            if(chars[j]==' '){
                res[--len]='0';
                res[--len]='2';
                res[--len]='%';
            }else{
                res[--len]=chars[j];
            }
        }
        return  new String(res,len,res.length-len);  // "\u0000"
    }
}