### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int len1 = num1.length();
        int len2 = num2.length();
        int len3 = len1 + len2;
        int tmp = 0;
        char[] out = new char[len3]; 
        for(int i = 0 ; i < len3 - 1; i++){
            int h = Math.min(len1 - 1,i);
            for(int j = 0; j <= h; j++){
                if(i-j<len2){
                    int l1 = num1.charAt(len1 - j -1) - '0';
                    int l2 = num2.charAt(len2 - i + j -1) - '0'; 
                    tmp = l1 * l2 + tmp;
                }
            }
            out[len3-i-1] = (char)(tmp % 10 + 48);
            tmp = tmp / 10;
        }
        String str = "";
        if( tmp == 0 ){
            str = str.copyValueOf(out, 1, len3-1);
            return str;
        }else{
            out[0] = (char)(tmp + 48);
            return str.copyValueOf(out);
        }
    }
}
```