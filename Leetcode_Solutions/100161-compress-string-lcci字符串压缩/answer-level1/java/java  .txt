```
class Solution {
    public String compressString(String S) {
        int n=S.length();
        StringBuffer ss=new StringBuffer();
        int count=1;
        boolean flag=true;
        for(int i=0;i<n;i++){
            if(i==n-1){
                 ss.append(S.charAt(i));
                 ss.append(count);
            }
            else if((S.charAt(i))==(S.charAt(i+1))){
                count++;
            }
            else {
                 ss.append(S.charAt(i));
                 ss.append(count);
                 count=1;
            }

           
        }
        if(ss.length()>=S.length()){
          return S;
        }else{
            return ss.toString();
        }
    }
}
```
