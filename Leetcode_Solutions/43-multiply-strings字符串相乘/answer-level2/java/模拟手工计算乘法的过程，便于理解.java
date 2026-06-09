代码稍稍有些长，但是便于理解算是抛砖引玉吧。
算法的核心思想就是模拟手工乘法计算的步骤

这里举个例子，我们计算25×36的时候一般是这么计算：
第一步：计算25×3=75
第二步：计算25×6=150
第三步：计算75×10+150 =900

所以这里需要把算法分解成两部分：
第一部分：多位整数数乘以一位整数
第二部分：整数相加

代码如下：

```
class Solution {
    public String multiply(String num1, String num2) {
        String result = "";
        for(int i = 0; i < num2.length(); i++){
            /*模拟手工计算两数相乘的过程
            *举两个例子
            *25×36 = (25×3)×10 + 25×6
            *33×444 =((33×4)×10 + (33×4))×10) + 33×4
            */
            result = add((result.equals("0") ? result : result+"0"), simpleMultiply(num1, num2.substring(i,i+1)));
        }
        return result;
    }
    
    
    /*
    *实现多位整数乘以个位整数
    */
    private String simpleMultiply(String a, String b) {
        if(a.equals("0") || b.equals("0")) return "0";
        
        StringBuilder result = new StringBuilder();
        int carryBit = 0;//进位
        int resultPerBit = 0;//每一位的乘法结果
        
        for(int i = a.length()-1; i >= 0; i--) {
            resultPerBit = carryBit;
            resultPerBit += ((a.charAt(i)-'0')*(b.charAt(0)-'0'));
            carryBit = resultPerBit/10;
            result.append(resultPerBit%10);
        }
        
        result.append((carryBit > 0 ? carryBit : ""));
        return result.reverse().toString();
    }
    
    /*
    *实现两数相加
    */
    private String add(String a, String b) {
        StringBuilder result = new StringBuilder();
        int carryBit = 0;//进位
        int sumPerBit = 0;//每一位的加法结果
        
        for(int i = a.length()-1, j = b.length()-1; i >= 0 || j >=0; i--, j--) {
            sumPerBit = carryBit;
            sumPerBit += (i >= 0 ? a.charAt(i)-'0' : 0);
            sumPerBit += (j >= 0 ? b.charAt(j)-'0' : 0);
            carryBit = sumPerBit/10;
            result.append(sumPerBit%10);
        }
        
        result.append((carryBit > 0 ? carryBit : ""));
        return result.reverse().toString();
    }
}
```
