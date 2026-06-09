### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        if(null==str||str.length()==0) return 0;
        int start=0;
        boolean isMinus=false;
        char[] ch=str.toCharArray();
        if((str.charAt(0)>57||str.charAt(0)<48)){
            while(start<ch.length&&ch[start]==' '){
                start++;
            }
            if(start==ch.length) return 0;
            if(ch[start]!='-'&&ch[start]!='+'&&ch[start]!='0'&&!checkNum(ch[start])){
                return 0;
            }
        }
        if((ch[start]>57||ch[start]<48)) isMinus=ch[start++]=='-'?true:false;
        while(start<ch.length&&ch[start]=='0'){
                start++;
        }
        if(start==ch.length) return 0;
        return getCalculatorNum(ch,start,isMinus);
        //return getStringNum(ch,start,isMinus);
    }
    /**
    ** 计算方式
    **/
    private int getCalculatorNum(char[] ch,int start,boolean isMinus){
        int ans=0;
        while(start<ch.length&&checkNum(ch[start])){
            int num=ch[start++]-'0';
            if(ans>((Integer.MAX_VALUE-num)/10)){
                return isMinus?Integer.MIN_VALUE:Integer.MAX_VALUE;
            }
            
            ans=ans*10+num;
        }
        return isMinus?-ans:ans;
    }
    /**
    **字符串处理方式
    **/
    private int getStringNum(char[] ch,int start,boolean isMinus){
        String startStr="";
        if(isMinus){
            startStr="-";
        }else{
            startStr="+";
        }
        StringBuilder sb=new StringBuilder(startStr);
        while(start<ch.length&&checkNum(ch[start])){
            sb.append(ch[start++]);
        }
        String num=sb.toString();
        if(num.equals("-")||num.equals("+")) return 0;
        if(!isMinus&&num.length()>11) return Integer.MAX_VALUE;
        if(isMinus&&num.length()>11) return Integer.MIN_VALUE;
        if(!isMinus&&num.length()==11){
            double d=Double.parseDouble(num);
            if(d>Integer.MAX_VALUE) return Integer.MAX_VALUE;
        }
        if(isMinus&&num.length()==11){
            double d=Double.parseDouble(num);
            if(d<Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        return Integer.parseInt(sb.toString());
    }
    private boolean checkNum(char c){
        if(c>57||c<48){
            return false;
        }
        return true;
    }
}
```