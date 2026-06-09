执行用时 :2 ms, 在所有 java 提交中击败了99.84% 的用户
内存消耗 :33.9 MB, 在所有 java 提交中击败了93.26%的用户
```
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return 0+"";
        StringBuilder sb = new StringBuilder();
        if((numerator > 0) != (denominator > 0))
            sb.append("-");
        long num1 = numerator;
        long num2 = denominator;
        num1 = Math.abs(num1);
        num2 = Math.abs(num2);
        long result = num1/num2;
        long remain = num1%num2;
        sb.append(result+"");
        if(remain == 0)
            return sb.toString();
        sb.append(".");
        Map<Long,Integer> map = new HashMap<>();
        while(remain != 0){
            num1 = remain*10;
            result = num1/num2;
            if(!map.isEmpty() && map.containsKey(remain)){
                sb.insert(map.get(remain),"(");
                sb.append(")");
                break;
            }
            map.put(remain,sb.length());
            remain = num1%num2;
            sb.append(result);
        }
        return sb.toString();
    }
}
```

