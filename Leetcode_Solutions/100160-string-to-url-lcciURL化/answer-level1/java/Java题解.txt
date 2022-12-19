```
class Solution {
    public String replaceSpaces(String S, int length) {
        int len = length;
        char[] chars = S.toCharArray();
        for(int i=0;i<length;i++){
            if(chars[i]==' '){
                len +=3;
            }
        }
        char[] res = new char[len];
        for(int i=length-1;i>=0;i--){
            if(chars[i]==' '){
                res[--len]='0';
                res[--len]='2';
                res[--len]='%';
            }else{
                res[--len]=chars[i];
            }
        }
        return new String(res,len,res.length-len);
    }
}
```
