```java
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        //map的key存放分子,value存放序号
        boolean 负数 = (numerator > 0) ^ (denominator > 0);
        long 分子 = numerator > 0 ? numerator : - (long)numerator;
        long 分母 = denominator > 0 ? denominator : - (long)denominator;
        long 整数部分 = 分子 / 分母;
        StringBuilder sb = new StringBuilder();
        if(负数) sb.append('-');
        sb.append(整数部分);
        sb.append('.');
        //index += 2;
        int index = sb.length();
        int 小数部分开始 = index;
        分子 %= 分母;
        while(true) {
            if(map.containsKey(分子)) break;
            map.put(分子, index++);
            分子 *= 10;
            long digit = 分子 / 分母;
            sb.append(digit);
            分子 %= 分母;
            if(分子 == 0) break;
        }
        
        if(分子 != 0){
            sb.append(')');
            sb.insert((int)map.get(分子), '(');
        }

        if(sb.charAt(sb.length() - 1) == '0') {
            sb.deleteCharAt(sb.length() - 1);
            sb.deleteCharAt(sb.length() - 1);
            if(sb.charAt(0) == '-' && sb.charAt(1) == '0')
                sb.deleteCharAt(0);
        }
        return sb.toString();
    }
}
```
