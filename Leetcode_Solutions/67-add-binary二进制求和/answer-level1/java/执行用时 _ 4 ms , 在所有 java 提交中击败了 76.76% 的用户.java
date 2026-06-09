```
class Solution {
    public String addBinary(String a, String b) {
        int flag = 0;
        int len1 = a.length();
        int len2 = b.length();
        int len=len1>=len2?len1:len2;
        int result = 0;
        int x1;
        int x2;
        StringBuilder str = new StringBuilder();
        for(int i=0;i<len;i++){
            x1 = len1-i-1>=0?a.charAt(len1-i-1)=='0'?0:1:0;
            x2 = len2-i-1>=0?b.charAt(len2-i-1)=='1'?1:0:0;
            result = x1+x2+flag;
            flag = result>=2?1:0;
            str.insert(0,result%2);
        }
        if(flag==1){
            str.insert(0,1);
        }
        return str.toString();
    }
}
```
