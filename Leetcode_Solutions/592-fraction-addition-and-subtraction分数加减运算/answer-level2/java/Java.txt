因为是分数相加，为了便于编写和理解我抽象出了Number表示分数，并实现了分数相加的add方法（通分+分子相加）。
通分要利用到求最小公倍数，约分要用到求最大公因数。
之后就是字符串切割，切出每个带符号的分数，相加即可。

```java
class Solution {
    class Number {
        //分子
        public int numerator;
        //分母
        public int dinominator;
        Number(int numerator, int dinominator){
            this.numerator = numerator;
            this.dinominator = dinominator;
        }
        public void add(Number number) {
            int tmpD = getMinMultiple(this.dinominator, number.dinominator);
            int tmpN = this.numerator * tmpD / this.dinominator + number.numerator * tmpD / number.dinominator;
            this.numerator = tmpN;
            this.dinominator = tmpD;
        }
    }

    public String fractionAddition(String expression) {
        List<Number> list = new LinkedList<>();
        int pre = 0;
        for(int i = 0; i < expression.length(); i++) {
            if(i != 0 && (expression.charAt(i) == '+' || expression.charAt(i) == '-')) {
                list.add(stringToNumber(expression.substring(pre, i)));
                pre = i;
            }
        }
        list.add(stringToNumber(expression.substring(pre, expression.length())));
        Number number = new Number(0, 1);
        for(Number n : list) {
            number.add(n);
        }
        int gcd = gcd(number.numerator, number.dinominator);
        number.numerator = number.numerator / gcd;
        number.dinominator = number.dinominator / gcd;
        if(number.dinominator < 0) {
            number.numerator *= -1;
            number.dinominator *= -1;
        }
        return number.numerator + "/" + number.dinominator;
    }
    
    //字符串转换为分数
    public Number stringToNumber(String expression) {
        String[] strs = expression.split("/");
        return new Number(Integer.valueOf(strs[0]), Integer.valueOf(strs[1]));
    }

    //求最大公因数
     public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b , a % b);
        }
    }
 
    //求最小公倍数
    public int getMinMultiple(int a, int b) {
        return a * b / gcd(a, b);
    }

}
```