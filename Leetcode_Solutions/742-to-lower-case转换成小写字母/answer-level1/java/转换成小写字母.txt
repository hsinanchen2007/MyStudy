```
class Solution {
    public String toLowerCase(String str) {
        if(str==null)return null;
        char[] c=str.toCharArray();
        for(int i=0;i<c.length;i++){
            if(c[i]>=65&&c[i]<=90)c[i]+=32;
            else if(c[i]>=97&&c[i]<=122)continue;
            
        }
        
        return new String(c);
    }
}