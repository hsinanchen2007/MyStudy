思路：此题考察复数的乘法，(a+bi)(c+di) = ac - bd + (ad + bc)i，只需抽象出复数类即可解答。<br/><br/>
代码：
```
class Solution {
    public String complexNumberMultiply(String a, String b) {
        return new ComplexNumber(a).multiply(new ComplexNumber(b)).toString();
    }
    // why need ComplexNumber?因为面向对象的设计，会使得代码的复用率更好
    static class ComplexNumber {
        int r;// 实部
        int v;// 虚部
        
        public ComplexNumber(String a) {
            int index = a.indexOf('+');// why not split?因为split是根据正则表达式匹配，效率太低，很慢
            
            this.r = Integer.valueOf(a.substring(0,index));// why not parseInt?因为valueOf比parseInt效率高。
            this.v = Integer.valueOf(a.substring(index + 1,a.length() - 1));
        }
        
        public ComplexNumber multiply(ComplexNumber n) {
            int a = this.r;
            int b = this.v;
            int c = n.r;
            int d = n.v;
            this.r = a * c - b * d;
            this.v = a * d + b * c;
            return this;
        }
        
        public String toString() {
            return r + "+" + v + "i";
        }
    }
}
```

![image.png](https://pic.leetcode-cn.com/e98d04aa57d3146364dea9767fe33caee4915816ee70e358c5529ccf3228a1ba-image.png)