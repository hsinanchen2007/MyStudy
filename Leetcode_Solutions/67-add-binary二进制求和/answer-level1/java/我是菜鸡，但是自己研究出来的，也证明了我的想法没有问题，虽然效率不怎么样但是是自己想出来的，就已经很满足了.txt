### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
       /**
          1010
          1011
         10101 
         如果相加后大于1则和2取余,并且表示有进位，不大于1则正常相加即可
        */
       //先将两个字符串拼为长度一样的字符串,为少的那个被补0
       int len1 = a.length();
       int len2 = b.length();
       //表示更长那位的长度
       int len = len1>len2?len1:len2;
       //表示结果
       StringBuffer sum = new StringBuffer();
       //表示进位
       int one = 0;
       //补0 后计算  
       for(int i = len-1; i >= 0; i--){
           if(len1-1 < i){
               a = "0"+a;
           }
           if(len2-1 < i){
               b = "0"+b;
           }
       }
       for(int i = len-1; i >= 0; i--){
           int num = (a.charAt(i)=='1'?1:0)+(b.charAt(i)=='1'?1:0)+one;
           //表示有进位 
           if(num > 1){
               num %= 2;
               one = 1;
           }else{ one = 0;}
           sum.insert(0,Integer.toString(num));
       }
       //判断最后一次计算有无进位
       if(one != 0)sum.insert(0,"1");
       return sum.toString();
    }
   
}

```