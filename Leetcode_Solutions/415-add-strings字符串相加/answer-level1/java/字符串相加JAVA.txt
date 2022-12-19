# 解题思路：

首先，`String`类型只有运算符重载的 ‘+’ ，用于拼接字符串的简化操作， 不支持常规的四则运算

但是，`Char`类型可以进行加减乘除的运算，可以想到将`String`中的每个字符转换为`char`类型进行计算

# 算法流程：

　　首先确定`num1`与`num2`的长度`L`，因为 `num1` 和`num2` 都不包含任何前导零，题目明显暗示我们短的字符串需要前导补`0`

　　需要两个变量，`temp`来储存 `num1`与`num2` 的`char`值相加的结果 ，`res`来储存是否有进位，进位则加一

　　结果需要存回字符串，由于先从末位开始计算，存进去的字符串需要逆序。
![演示文稿1.mp4](97ed5a95-a2c8-4e1b-9c07-a8d0d417313d)


```
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
```
耗时很长，参考了一下Krahets的解法，思路是一致的，使用双指针进行解答
```
 public String addStrings(String num1, String num2) {
        StringBuilder res = new StringBuilder("");
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while(i >= 0 || j >= 0){
            int n1 = i >= 0 ? num1.charAt(i) - '0' : 0;
            int n2 = j >= 0 ? num2.charAt(j) - '0' : 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            res.append(tmp % 10);
            i--; j--;
        }
        if(carry == 1) res.append(1);
        return res.reverse().toString();
    }
```
Krahets的解法少了进行补0字符串相加的操作，时间少减少很多。