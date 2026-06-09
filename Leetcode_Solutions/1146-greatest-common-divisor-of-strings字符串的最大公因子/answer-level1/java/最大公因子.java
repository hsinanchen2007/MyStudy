```
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int la=str1.length(),lb=str2.length(),lmax=0,lmin=0;
        String out="",smin=new String(),smax=new String();
        if(la==lb){
            if(str1.equals(str2)) return str1;
            return "";
            }
        if(la<lb){
            lmin=la;
            lmax=lb;
            smin=str1;
            smax=str2;
            }
        else if(la>lb){
             lmin=lb;
             lmax=la;
             smin=str2;
             smax=str1;
             }
        if(smax.indexOf(smin) == -1) return out;
        int gcd=gcdme(lmin,lmax);
        int i=0;
        String yz=smin.substring(i,i+gcd);
        while(i+gcd<=lmin){
            if(! yz.equals(smin.substring(i,i+gcd))) return out;
            i+=gcd;
        }
        i=0;
        while(i+gcd<=lmax){
            if(! yz.equals(smax.substring(i,i+gcd))) return out;
            i+=gcd;
        }
        return yz;  
    }
    public int gcdme(int min,int max){
        if (max % min != 0) {
            return gcdme(max % min,min);
        } else
            return min;
    }
}
代码块
```
