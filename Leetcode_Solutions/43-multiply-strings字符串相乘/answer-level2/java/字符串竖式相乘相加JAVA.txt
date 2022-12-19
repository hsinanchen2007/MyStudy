# 解题思路：

首先，`String`类型只有运算符重载的 ‘+’ ，用于拼接字符串的简化操作， 不支持常规的四则运算

但是，`Char`类型可以进行加减乘除的运算，可以想到将`String`中的每个字符转换为`char`类型进行计算

**第一次尝试：**
首先是一个取巧的做法，想直接利用`sum = (num2.charAt(i)-'0')*s+sum;`取巧
很明显，题目给的数值结果是大于`Integer.MAXVALUE`的，导致下面这个取巧解法在大数下直接溢出成负数，结果惨不忍睹
```
class Solution {
    public String multiply(String num1, String num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int s = 0;
        for (int i=0;i<l1;i++){
            s = num1.charAt(i)-'0'+s;
            if (i!=l1-1)
                s=s*10;
        }
        int sum = 0;
        for (int i=0;i<l2;i++){
            sum = (num2.charAt(i)-'0')*s+sum;
            if (i!=l2-1)
                sum=sum*10;
        }
        StringBuffer save = new StringBuffer();
        while(sum!=0){
            save.append(sum%10);
            sum = sum/10;
        }
    
        return save.reverse().toString();
    }
}
```
**第二次尝试：**
想到既然相加的时候`Int`会溢出，相乘的时候`Int`不会溢出，所以想到把每一个对位相乘的结果存入数组
然后使用https://leetcode-cn.com/problems/add-strings/ NO145的字符串相加来对数组进行相加
尝试的结果是原来相乘`int`也会溢出
```
public class NO43 {
    public String multiply(String num1, String num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        if (num1=="0" || num2=="0")
            return "0";
        int s = 0;
        for (int i=0;i<l1;i++){
            s = num1.charAt(i)-'0'+s;
            if (i!=l1-1)
                s=s*10;
        }
        int []sum = new int[l2];
        for (int i=0;i<l2;i++){
            sum[i] = (num2.charAt(i)-'0')*s;
        }
        String saves = "0";
        for (int i =0;i<l2;i++){
            saves = addStrings(Integer.toString(sum[i]),saves);
            if (i+1!=l2)
                saves = saves + "0";
        }

        return saves;
    }
    public String addStrings(String num1, String num2) {
        int L = num1.length() >= num2.length() ? num1.length() : num2.length();
        String s="";
        if (num1.length()<L) {
            for (int i=0;i<L-num1.length();i++)
                s = s + '0';
            num1 = s+num1;
        }
        if (num2.length()<L) {
            for (int i=0;i<L-num2.length();i++)
                s = s + '0';
            num2 = s+num2;
        }
        StringBuffer save = new StringBuffer();
        boolean res = false;
        for (int i = L - 1; i >= 0; i--) {
            int n1 = num1.charAt(i)-'0';
            int n2 = num2.charAt(i)-'0';
            int temp = res?n1+n2+1:n1+n2;
            if (temp>=10) {
                res=true;
            }else res=false;
            save.append(temp%10);
        }
        if (res) save.append(1);
        return save.reverse().toString();
    }
    public static void main(String[] args) {
        NO43 so = new NO43();
        String a = so.multiply("123456789","987654321");
        System.out.println(a);
    }
}
```
**第三次尝试**
老老实实按位相乘再相加去做乘法运算，总算结束了，附上breezean的代码，回过头一看思路还是很相似的
都是用了后面N0415的相加的函数，然后按位相乘相加了
```
class Solution {
    /**
    * 计算形式
    *    num1
    *  x num2
    *  ------
    *  result
    */
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        // 保存计算结果
        String res = "0";
        
        // num2 逐位与 num1 相乘
        for (int i = num2.length() - 1; i >= 0; i--) {
            int carry = 0;
            // 保存 num2 第i位数字与 num1 相乘的结果
            StringBuilder temp = new StringBuilder();
            // 补 0 
            for (int j = 0; j < num2.length() - 1 - i; j++) {
                temp.append(0);
            }
            int n2 = num2.charAt(i) - '0';
            
            // num2 的第 i 位数字 n2 与 num1 相乘
            for (int j = num1.length() - 1; j >= 0 || carry != 0; j--) {
                int n1 = j < 0 ? 0 : num1.charAt(j) - '0';
                int product = (n1 * n2 + carry) % 10;
                temp.append(product);
                carry = (n1 * n2 + carry) / 10;
            }
            // 将当前结果与新计算的结果求和作为新的结果
            res = addStrings(res, temp.reverse().toString());
        }
        return res;
    }

    /**
     * 对两个字符串数字进行相加，返回字符串形式的和
     */
    public String addStrings(String num1, String num2) {
        StringBuilder builder = new StringBuilder();
        int carry = 0;
        for (int i = num1.length() - 1, j = num2.length() - 1;
             i >= 0 || j >= 0 || carry != 0;
             i--, j--) {
            int x = i < 0 ? 0 : num1.charAt(i) - '0';
            int y = j < 0 ? 0 : num2.charAt(j) - '0';
            int sum = (x + y + carry) % 10;
            builder.append(sum);
            carry = (x + y + carry) / 10;
        }
        return builder.reverse().toString();
    }
}

```
