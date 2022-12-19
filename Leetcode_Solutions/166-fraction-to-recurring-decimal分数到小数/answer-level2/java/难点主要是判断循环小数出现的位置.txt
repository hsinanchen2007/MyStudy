余数重复的位置便是小数循环出现的地方，使用Hashmap记录余数值和其出现位置，发现重复余数则在重复余数第一次出现位置插入括号。

这破题目特别容易掉坑了，一不小心结果就出错，大家小心

```
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        /* 分母为零，直接返回零 **/
        if (numerator==0)
            return "0";
        
        /* 异或取符号位, 结果res使用StringBuilder保存，提高性能 **/
        boolean negetive= (numerator^ denominator)< 0;
        StringBuilder res= new StringBuilder();
        
        /* 计算整数部分，若取模无余数，则无小数部分，直接返回结果 **/
        long numerator_p= Math.abs((long)numerator);
        long denominator_p= Math.abs((long)denominator);
        res.append(numerator_p/ denominator_p);
        if (numerator_p% denominator_p ==0)
            return (negetive)? "-"+ res.toString() : res.toString();
        
        
        /* 小数部分处理，取模余数*10，和小数位置index一起寸入map中
        *  余数*10除以denominator_p即算出小数部分当前位置的数字
        *  若余数*10的值重复，则答案的小数值也会重复，
        *  取得第一次重复余数出现的index位置，插入括号，输出答案
        **/
        res.append(".");
        int index= res.length();
        Map<Long, Integer> circle_num= new HashMap<>();
        long remain= numerator_p% denominator;
        
        while (remain!=0) {
            remain*= 10;
            if (circle_num.containsKey(remain)) {
                index= circle_num.get(remain);
                res.insert(index, "(").append(")");
                break;
            }
            circle_num.put(remain, index);
            res.append(remain/ denominator_p);
            remain%= denominator_p;
            index++;
        }
        
        return (negetive)? "-"+ res.toString() : res.toString();
    }
}
```