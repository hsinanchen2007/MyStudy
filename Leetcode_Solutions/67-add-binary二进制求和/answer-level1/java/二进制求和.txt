首先想到是将短的那个字符串用0补位，保证两个字符串长度相等。

然后创建新的数组用来接收字符串的和，这个数组的长度为两个字符串中长的那个长度加1。


class Solution {
    public String addBinary(String a, String b) {
        int l1=a.length();
        int l2=b.length();
        int[] res=new int[Math.max(l1,l2)+1];
        String s1="";
        if(l1<l2){
            for(int i=0;i<l2-l1;i++){
                s1+="0";
            }
            a=s1+a;
        }
         if(l1>l2){
            for(int i=0;i<l1-l2;i++){
                s1+="0";
            }
            b=s1+b;
        }
       for(int i=b.length()-1;i>=0;i--){
              int sum=b.charAt(i)+a.charAt(i)-96+res[i+1];
              res[i+1]=sum%2;
              res[i]+=sum/2; 
       }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<res.length;i++){
            if(i==0&&res[i]==0) continue;//如果首位是0跳过继续执行
            sb.append(res[i]);
        }
        return sb.toString();
    }
}