```
class Solution {
    public int myAtoi(String str) {
        int index = 0;
        int n = str.length();
        char[] chars = str.toCharArray();

        while(index<n && chars[index]==' '){    //去除开头空格字符
            index++;
        }
        if(index == n){ //空字符串
            return 0;
        }

        boolean positive = true;
        if(chars[index] == '+'){
            index++;
        }else if(chars[index] == '-'){
            positive = false;
            index++;
        }else if(!Character.isDigit(chars[index])){ //正负号之后不是数字，返回0
            return 0;
        }

        int num = 0;
        while(index<n && Character.isDigit(chars[index])){
            int digit = chars[index] - '0';
            // 判断越界 ans * 10 + digit > Integer.MAX_VALUE
            if(num > (Integer.MAX_VALUE-digit)/10){
                return positive? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            num = num * 10 + digit;
            index++;
        }
        return positive ? num : -num;
    }
}
```
