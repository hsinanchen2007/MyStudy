```java
class Solution {
    public int myAtoi(String str) {
        char[] chars = str.toCharArray();
        //去掉空格
        int index = 0;
        while(index < str.length() && chars[index] == ' '){
            index++;
        }
        if(index == str.length()){
            return 0;
        }
        chars = str.substring(index).toCharArray();

        int res = 0;
        int isNegOrPos = 0;//默认正数

        //先判断符号
        if(chars[0] == '-'){
            isNegOrPos = 1;
        }else if(chars[0] == '+'){
            isNegOrPos = 0;
        }else if(Character.isDigit(chars[0])){
            res = chars[0] - '0';
        }else{
            return 0;
        }
        //避免 "  -42+53"这样的情况发生错误
        chars = str.substring(index + 1).toCharArray();
        
        for(char c : chars){
            if(Character.isDigit(c)){
                int digit = c - '0';
                //res = res*10 + digit;
                //溢出的情况下 res*10 + digit > Integer.MAX_VALUE
                if(res > (Integer.MAX_VALUE - digit) / 10){
                    return isNegOrPos == 1 ? Integer.MIN_VALUE : Integer.MAX_VALUE; 
                }
                res = res * 10 + digit;
            }else{
                break;
            }
        }
        return isNegOrPos == 1 ? (0-res) : res;
    }
}
```