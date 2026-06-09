### 解题思路
1.由于字符串a和字符串b可能存在长度不一致，因此将其化为同等的长度(短一点的字符串前面补'0')
2.二进制相加无非就是11，10，01，00四种情况求和
3.求和过程中也许会存在进位的情况，所以用flag表示是否进位

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        int lena = a.length();
        int lenb = b.length();
        int len = lena > lenb ? lena : lenb;         //求两字符串中最长的长度
        int flag = 0;      //0表示没有进位，1表示进位了
        //在短的那个字符串前面补'0'
        int na = len - lena ;
        int nb = len - lenb ;
        while(na > 0){
            a = '0' + a;
            na--;
        }
        while(nb > 0){
            b = '0' + b;
            nb--;
        }
        String str = "";
        //while(len != 0 ){
            for(int i = len - 1; i >= 0 ; --i){
                if(a.charAt(i) == '1'){
                     if(b.charAt(i) == '1'){ //11
                         if(flag == 1){
                             str = '1' + str;
                         }else{
                             str = '0' + str; 
                         }
                         flag = 1;
                     }else{       //10
                         if(flag == 1){
                             str = '0' + str;
                             flag = 1;
                         }else{
                             str = '1' + str;
                             flag = 0;
                         }
                     }
                }else{
                     if(b.charAt(i) == '1'){//01
                         if(flag == 1){
                             str = '0' + str;
                             flag = 1;
                         }else{
                             str = '1' + str; 
                             flag = 0;
                         } 
                     }else{     //00
                         if(flag == 1){
                             str = '1' + str;
                         }else{
                             str = '0' + str; 
                         }
                         flag = 0;  
                     }
                }
            }
            //System.out.println(str);
            //len--;
        //}
        if(flag == 1){
            str = '1' + str;
        }
        return str;
    }
}
```