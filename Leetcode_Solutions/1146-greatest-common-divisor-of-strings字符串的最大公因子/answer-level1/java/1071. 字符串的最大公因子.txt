```
class Solution {
    public int gcd(int a, int b){
         if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }

    public String gcdOfStrings(String str1, String str2) {
        if((str1 + str2).equals(str2 + str1)){ //str1 + str2与str2 + str1相等是有解的充要条件
             int len = gcd(str1.length(), str2.length());
             return str1.substring(0,len);  //最大公因子的长度是两个字符串长度的最大公因数
        }else{
            return "";
        }
    }
}
```
