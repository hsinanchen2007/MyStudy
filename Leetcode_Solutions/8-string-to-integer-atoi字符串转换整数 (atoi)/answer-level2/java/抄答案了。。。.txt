### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        char[] chars = str.toCharArray();
        int n = chars.length;
        int idx = 0;

        while(idx < n && chars[idx] == ' '){
            //去掉空格 通过索引前移
            idx++;
        }
        if(idx == n){
            //去掉前导空格以后到了末尾了
            return 0;
        }

        boolean negative = false;
        if(chars[idx] == '-'){
            //遇到负号
            negative = true;
            idx++;
        }else if(chars[idx] == '+'){
            //遇到正好
            idx++;
        }else if(!Character.isDigit(chars[idx])){
            //其他符号
            return 0;
        }

        int ans = 0;
        while(idx < n && Character.isDigit(chars[idx])){
            int digit = chars[idx] - '0';
            if(ans > (Integer.MAX_VALUE - digit) / 10) {
                return negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            ans = ans * 10 + digit;
            idx++;
        }

        return negative? -ans : ans;


    }
}
```