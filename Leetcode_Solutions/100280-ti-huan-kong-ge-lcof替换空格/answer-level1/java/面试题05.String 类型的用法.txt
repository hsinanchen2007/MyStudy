```
class Solution {
    public String replaceSpace(String s) {
        int num=s.length();
        String res ="";
        String novel="%20";
        for(int i=0;i<num;i++){
            char a = s.charAt(i);
            if(a==' '){
                res=res+novel;
            }else{
                res=res+String.valueOf(a);
            }
        }
        return res;
    }
}
```