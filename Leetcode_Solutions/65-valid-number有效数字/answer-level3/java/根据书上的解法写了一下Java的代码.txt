```
class Solution {
    int i=0;
    public boolean isNumber(String s) {
        s=s.trim();/*去掉首尾空格*/
        int len=s.length();
        if(len==0) return false;
        boolean numeric=scanInteger(s);
        if(i<len&&s.charAt(i)=='.'){
            i++;
            numeric=scanUnsignedInteger(s)||numeric;
        }
        if((i<len)&&(s.charAt(i)=='e'||s.charAt(i)=='E')){
            i++;
            numeric=scanInteger(s)&&numeric;
        }
        return numeric&&i==len;
    }
    public boolean scanInteger(String s){/*用于判断整数部分和指数部分*/
        if((i<s.length())&&(s.charAt(i)=='+'||s.charAt(i)=='-')){
            i++;
        }
        return scanUnsignedInteger(s);
    }
    public boolean scanUnsignedInteger(String s){/*用于判断是否有0到9的数字*/
        boolean flag=false;
        while(i<s.length()&&s.charAt(i)>='0'&&s.charAt(i)<='9'){
            i++;
            flag=true;
        }
        return flag;
    }
}
```
