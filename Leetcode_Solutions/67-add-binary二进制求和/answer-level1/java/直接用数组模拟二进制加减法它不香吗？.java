### 解题思路
执行用时 :
2 ms
, 在所有 java 提交中击败了
97.41%
的用户
内存消耗 :
36.2 MB
, 在所有 java 提交中击败了
55.06%
的用户

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        String res="";
        char [] chars_a=a.toCharArray();
        char [] chars_b=b.toCharArray();
        //字符数组实现二进制数相加
        int temp=chars_a.length>chars_b.length?chars_a.length:chars_b.length;
        char [] short_temp=chars_a.length>chars_b.length?chars_b:chars_a;
        char [] chars_temp=new char [temp];
        for(int i=0;i<temp;i++){
            if(i<(temp-short_temp.length)){
                chars_temp[i]='0';
            }else {
                chars_temp[i] =short_temp[i-(temp-short_temp.length)];
            }
        }
        char [] long_temp=chars_a==short_temp?chars_b:chars_a;
        char [] chars_res=new char[temp+1];
        char carry='0';
        //接下来用等长的两个字符数组chars_temp和long_temp相加
        for(int i=temp-1;i>=0;i--){//低位到高位相加
            if(long_temp[i]=='0'&&chars_temp[i]=='0'&&carry=='0'){
                chars_res[i+1]='0';
                carry='0';
            }else if(long_temp[i]=='1'&&chars_temp[i]=='0'&&carry=='0'){
                chars_res[i+1]='1';
                carry='0';
            }else if(long_temp[i]=='0'&&chars_temp[i]=='1'&&carry=='0'){
                chars_res[i+1]='1';
                carry='0';
            }else if(long_temp[i]=='1'&&chars_temp[i]=='1'&&carry=='0'){
                chars_res[i+1]='0';
                carry='1';
            }else if(long_temp[i]=='0'&&chars_temp[i]=='0'&&carry=='1'){
                chars_res[i+1]='1';
                carry='0';
            }else if(long_temp[i]=='1'&&chars_temp[i]=='0'&&carry=='1'){
                chars_res[i+1]='0';
                carry='1';
            }else if(long_temp[i]=='0'&&chars_temp[i]=='1'&&carry=='1'){
                chars_res[i+1]='0';
                carry='1';
            }else if(long_temp[i]=='1'&&chars_temp[i]=='1'&&carry=='1'){
                chars_res[i+1]='1';
                carry='1';
            }
        }
        if(carry=='1') chars_res[0]='1';
        else chars_res[0]='0';
        for(int i=0;i<chars_res.length;i++){
            if(i==0&&chars_res[i]=='0'){}
            else{
                res+=String.valueOf(chars_res[i]);
            }
        }
        return res;
    }
}
```