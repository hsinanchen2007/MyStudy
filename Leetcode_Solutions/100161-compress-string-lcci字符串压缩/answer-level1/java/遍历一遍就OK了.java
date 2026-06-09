```
class Solution {
    public String compressString(String S) {
        if(S==null || S.length()<3)
            return S;
        int len=S.length();
        StringBuilder sb=new StringBuilder();
        int nums=1;
        char c=S.charAt(0);
        for(int i=1;i<len;i++){
            if(S.charAt(i)==c)
                nums++;
            else {
                sb.append(c).append(nums);
                c=S.charAt(i);
                nums=1;
            }
        }
        sb.append(c).append(nums);
               
        return sb.toString().length()<len?sb.toString():S;
    }
}
```
