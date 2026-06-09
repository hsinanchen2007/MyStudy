暴力法运行超时
```
class Solution {
    public String longestPalindrome(String s) {
        int length = s.length();
        String maxString = "";
        int maxLength = 0;
        for(int i =0;i<length;i++){
            for(int j = i;j<length;j++){
                String sub = s.substring(i,j+1);
                boolean judgeResult = judge(sub);
                if(judgeResult == true && sub.length()>maxLength){
                    maxLength = sub.length();
                    maxString = sub;
                }
            }
        }
        return maxString;
    }
    private boolean judge(String subString){
        for(int k =0;k<subString.length()/2;k++){
            if(subString.charAt(k)==(subString.charAt(subString.length()-k-1))){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    
}
```
中心扩展算法一是要理解拓展算法什么意思，就是以一个字母(s,i,i)或者两个相同(s,i,i+1)为中心点，向两边扩展查看是否对称。
```
class Solution {
    public String longestPalindrome(String s) {
        if(s==null || s.equals("")){
            return "";
        }
        int start = 0;
        int end = 0;
        for(int i = 0;i<s.length();i++){
            int len1 = extendString(s,i,i);
            int len2 = extendString(s,i,i+1);
            int len = Math.max(len1,len2);
            if(len>end-start){
                //计算起点时，这里len-1是为了双点时，消除i点本身的影响，当双点扩展时，假设最终长度为4，如果不剪去1，最终结果就多减了1.
                start = i-(len-1)/2;
                
                end = i+len/2;
            }
        }
        return s.substring(start,end+1);
    }
    protected int extendString(String s,int left,int right){
        int l = left;
        int r = right;
        while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
            l--;
            r++;
        }
        //当比较是否相等的时候，l和r实际都是已经加减过了。也就是说比较的是当前位置的l和r。如果失败了，那么当前位置之前的一组位置长度才是应该返回的长度。计算起来就是r-l-1
        return r-l-1;
    }
}
```
时复O（n^2）里外两层循环。空复O（1）