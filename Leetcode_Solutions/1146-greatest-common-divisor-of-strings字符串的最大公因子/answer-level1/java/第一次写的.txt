### 解题思路
反正这种方法虽然鱼唇但是一次过了就先打个卡。
### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String x="";
        int length=Math.min(str1.length(),str2.length());
        for(int i=length;i>=1;i--){
            x=str2.substring(0,i);
            if(str1.length()%i==0&&str2.length()%i==0){
                if(check(str1,x)&&check(str2,x)){
                    return x;
                }
            }
        }
        return "";
    }
    public boolean check(String main,String sub){
        int mlen=main.length();
        int slen=sub.length();
        int times=mlen/slen;
        boolean result=false;
        String temp="";
        for(int i=0;i<times;i++){
            temp+=sub;
            if(temp.equals(main)){
                result=true;
            }
        }
        return result;
    }
}
```