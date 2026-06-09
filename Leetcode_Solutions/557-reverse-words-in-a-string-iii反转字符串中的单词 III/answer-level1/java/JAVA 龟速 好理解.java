
```
class Solution {
    public String reverseWords(String s) {
     StringBuilder str=new StringBuilder(s);
        int j=0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==' '){
                rev(str,j,i-1);
                j=i+1;
            }
               if(i==str.length()-1){//末尾没有空格，则i到最后一个单独解决
                   rev(str,j,i);
               }
        }
        return str.toString();
    }
    public StringBuilder rev(StringBuilder ss,int ii,int jj){//换位函数
        for(int i=ii,j=jj;i<j;i++,j--){   
            char temp=ss.charAt(i);
            ss.setCharAt(i,ss.charAt(j));
            ss.setCharAt(j,temp);
            
        }
        return ss;
    }
}
```