### 解题思路
BigInteger大法好！！！

### 代码

```java

import java.math.BigInteger;

class Solution {

    public int myAtoi(String str) {

        if (str.length()==1){
            if(is_number(str.charAt(0))) return Integer.parseInt(str);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length()-1; i++) {

            if (str.charAt(i) == ' ') continue;

            char now = str.charAt(i);
            char next = str.charAt(i + 1);

            //判断是否是有效字符
            if (!is_valid(now)) return 0;

            if (now == '+' && next == '+') {
                return 0;
            } else if (now == '+' && next == '-') {
                return 0;
            } else if (now == '-' && next == '+') {
                return 0;
            } else if (now == '-' && next == '-') {
                return 0;
            }

            sb.append(now);
            //如果下一个不是数字
            if (!is_number(next)) {
                break;
            }else if (i+1==str.length()-1)
                sb.append(next);

        }

        String st = sb.toString();

        if (st.equals("-")||st.equals("+")||st.equals("")) return 0;

        BigInteger number = new BigInteger(st);
        BigInteger max = new BigInteger(String.valueOf(Integer.MAX_VALUE));
        BigInteger min = new BigInteger(String.valueOf(Integer.MIN_VALUE));

        if (number.max(max).equals(number)) return Integer.MAX_VALUE;

        if (number.min(min).equals(number)) return Integer.MIN_VALUE;

        return number.intValue();
    }


    public boolean is_valid(char a) {

        boolean flag = true;
        switch (a) {
            case '0':
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '-':
                break;
            case '+':
                break;
            default:
                flag = false;
                break;
        }

        return flag;

    }


    public boolean is_number(char a) {

        boolean flag = true;
        switch (a) {
            case '0':
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            default:
                flag = false;
                break;
        }

        return flag;

    }


}
```