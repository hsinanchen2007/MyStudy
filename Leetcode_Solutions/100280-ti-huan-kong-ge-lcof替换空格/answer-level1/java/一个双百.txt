```
class Solution {
    public String replaceSpace(String s) {
        StringBuilder sb=new StringBuilder();
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' '){
                sb.append(s.substring(temp,i));
                sb.append("%20");
                temp=i+1;
            }
        }
        sb.append(s.substring(temp,s.length()));
        return sb.toString();
    }
}
```
思路很正常，就是从前往后遍历，但是写的时候还是遇到了一点问题的，主要是处理特殊情况，比如全“ ”，最开始用的split，不过没想出来好的方法。
在这个常规遍历中，temp是一个很关键的点，要记录上一次append时在s的位置。