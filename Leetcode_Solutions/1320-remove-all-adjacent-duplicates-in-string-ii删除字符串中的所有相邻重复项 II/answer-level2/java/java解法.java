```
class Solution {
    public String removeDuplicates(String s, int k) {
        StringBuilder sb=new StringBuilder(s);
        int left=0;
        int right=left;
        int count=0;
        while(left<=right && right<sb.length()){
            if(sb.charAt(right)!=sb.charAt(left)){
                left=right;
                right=left;
                count=0;
            }else{
                count++;
                right++;
                if(count==k){
                    sb.delete(left,right);
                    while(left<sb.length() && left-1>=0 && sb.charAt(left-1)==sb.charAt(left)){
                        left--; 
                    }
                    right=left;
                    count=0;
                }

            }
        }
        return sb.toString();
    }
}
```
