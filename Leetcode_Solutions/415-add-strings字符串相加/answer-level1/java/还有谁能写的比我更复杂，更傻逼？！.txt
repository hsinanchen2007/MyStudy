### 解题思路
执行用时 :
68 ms
, 在所有 java 提交中击败了
5.00%
的用户
内存消耗 :
96.2 MB
, 在所有 java 提交中击败了
6.07%
的用户
纯模拟十进制加减法

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
         String res="";
       char[] chars_num1=num1.toCharArray();
       char [] chars_num2=num2.toCharArray();

       if(chars_num1.length>=chars_num2.length){
           char [] chars_num2_add=new char[chars_num1.length];
           for(int i=0;i<chars_num2_add.length;i++){
               if(i<chars_num1.length-chars_num2.length){
                   chars_num2_add[i]='0';
               }else{
                   chars_num2_add[i]=chars_num2[i-(chars_num1.length-chars_num2.length)];
               }
           }
           char [] chars_res=new char[chars_num2_add.length+1];
           chars_res[0]='0';
           int carry=0;
           for(int i=chars_num2_add.length-1;i>=0;i--){
               chars_res[i+1]=(char)(carry+chars_num1[i]+chars_num2_add[i]-'0');//字符使用+-符号将自动转换成其ASCII码进行加减运算得到运算后的ASCII码值
               /* char a='1';ASCII=49
        char b='2';ASCII=50
        System.out.println(a+b);
        输出99*/
               if(chars_res[i+1]>'9'){
                   chars_res[i+1]=(char)(chars_res[i+1]-10);
                   carry=1;
               }else{
                   carry=0;
               }
           }
           if(carry==1){
               chars_res[0]='1';
               for(char c:chars_res) res+=String.valueOf(c);
           }else{
               for(int i=1;i<chars_res.length;i++){
                   res+=String.valueOf(chars_res[i]);
               }
           }



       }else {
           char [] chars_num1_add=new char[chars_num2.length];
           for(int i=0;i<chars_num1_add.length;i++){
               if(i<chars_num2.length-chars_num1.length){
                   chars_num1_add[i]='0';
               }else{
                   chars_num1_add[i]=chars_num1[i-(chars_num2.length-chars_num1.length)];
               }
           }
           char [] chars_res=new char[chars_num1_add.length+1];
           chars_res[0]='0';
           int carry=0;
           for(int i=chars_num1_add.length-1;i>=0;i--){
               chars_res[i+1]=(char)(carry+chars_num2[i]+chars_num1_add[i]-'0');//字符使用+-符号将自动转换成其ASCII码进行加减运算得到运算后的ASCII码值
              
               if(chars_res[i+1]>'9'){
                   chars_res[i+1]=(char)(chars_res[i+1]-10);
                   carry=1;
               }else{
                   carry=0;
               }
           }
           if(carry==1){
               chars_res[0]='1';
               for(char c:chars_res) res+=String.valueOf(c);
           }else{
               for(int i=1;i<chars_res.length;i++){
                   res+=String.valueOf(chars_res[i]);
               }
           }

       }

       return res;

    }
}
```