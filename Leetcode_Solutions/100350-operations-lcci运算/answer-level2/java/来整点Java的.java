思路其他语言也通用。严格按照魔鬼的要求`只允许使用加法运算符和逻辑运算符，不允许使用位运算。`

乘法和除法容易想到的是通过累加和递减来计算结果，但是会超时。要改进下方法：
1. 减法通过把b变成相反数来相加得到；
2. 乘法可以参照手写计算的流程来实现，先用累加实现一个乘数在10以内的乘法，如果乘数超过10，就用乘数的每一位和被乘数相乘，积再相加，注意移位（这里只能用乘10来补0）；
3. 除法的基本思路也是通过递减来实现，不过这里不是挨个去减了，详情见代码。


```
class Operations {
    public Operations() { }
    
    public int minus(int a, int b) {
        String sb = String.valueOf(b);
        if(b > 0){
            b = Integer.parseInt("-"+sb);
        } else if(b < 0){
            b = Integer.parseInt(sb.substring(1, sb.length()));
        }
        return a+b;
    }
    
    public int multiply(int a, int b) {
        if(b == 0)  return 0;
        boolean negative = (a>0&&b<0) || (a<0&&b>0);
        a = Math.abs(a);
        b = Math.abs(b);

        int ans = 0;
        if(b<=10){
            for(int i=0; i<b; i++)  ans += a;
            return negative ? -ans : ans;
        }

        String sb = String.valueOf(b);
        for(int i=sb.length()-1; i>=0; i--){
            int bit = sb.charAt(i)-'0';
            int multi = multiply(a, bit);
            for(int j=0; j<sb.length()-1-i; j++){
                multi = multiply(multi, 10);
            }
            ans += multi;
        }   
        return negative ? -ans : ans; 
    }
    
    public int divide(int a, int b) {
        if(b==1)    return a;
        if(b==-1)   return minus(0, a);
        boolean negative = (a>0&&b<0) || (a<0&&b>0);
        a = Math.abs(a);
        b = Math.abs(b);
        if(a < b)   return 0;

        int ans = 0;
        int cur = 0;
        String sa = String.valueOf(a);
        for(int i=0; i<sa.length(); i++){
            int c = sa.charAt(i)-'0';
            cur = multiply(cur, 10) + c;
            int count = 0;
            while(cur >= b){
                cur = minus(cur, b);
                count++;
            }
            ans = multiply(ans, 10) + count;
        }
        return negative ? -ans : ans;
    }
}
```

运行耗时25ms还不错，提交记录里最快的16ms似乎还是通过赖皮手法直接 - * / 运行的。
