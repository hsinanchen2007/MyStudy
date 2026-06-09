### 解题思路
递归还是耗时间啊
### 代码

```java
class Solution {
    private int index;
    public String multiply(String num1, String num2) {
        int a=0,b=0;
        this.index=0;
        if(num1.equals("0")||num2.equals("0"))
            return "0";
        String res="",tmp="";
        for(int i=num2.length()-1;i>=0;i--){
            tmp=_WorkMultplye(num1,num2.charAt(i),0,num1.length()-1);
            for(int j=0;j<index;j++){
                tmp+='0';
            }
            res=_WorkPlus(res,tmp,0,0);
            this.index++;
        }
        return res;
    }

    private String _WorkPlus(String res, String tmp,int Make,int lever) {
        int tmp2=0;
        String tmp1="";
        if(lever>=res.length()&&lever>=tmp.length()&&Make==0)
            return "";
        if(lever>=res.length()&&lever>=tmp.length()){
            return Make+"";
        }
        if(lever<tmp.length()&&lever<res.length()) {
            tmp2 = (res.charAt(res.length() - 1 - lever) - '0') + (tmp.charAt(tmp.length() - 1 - lever) - '0')+Make;
        }
        else if(tmp.length()>res.length()){
            tmp2=(tmp.charAt(tmp.length()-1-lever)-'0')+Make;
        }
        else {
            tmp2=(res.charAt(res.length()-1-lever-'0'))+Make;
        }
        if(tmp2>=10){
            Make=tmp2/10;
            tmp1+=(tmp2-Make*10)+"";
        }
        else {
            Make=0;
            tmp1+=tmp2;
        }
        return _WorkPlus(res,tmp,Make,lever+1)+tmp1;
    }

    private String _WorkMultplye(String num1, char foct,int Make,int lever) {
        if(lever<0&&Make==0)
            return "";
        if(lever<0)
            return Make+"";
        String res="";
        int tmp=((num1.charAt(lever)-'0')*(foct-'0'))+Make;
        if(tmp>=10){
            Make=tmp/10;
            res+=(tmp-Make*10)+"";
        }
        else {
            Make=0;
            res+=tmp+"";
        }
        return _WorkMultplye(num1,foct,Make,lever-1)+res;
    }
}
```