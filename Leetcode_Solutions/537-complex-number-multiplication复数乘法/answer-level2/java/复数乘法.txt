### 解题思路

需要掌握的Java语法知识：
（1）分割字符串中如果分割部分含有转义字符需要在转义字符前加\\，如果分割符包括两个字符，第二个字符前需要加|。
（2）String类型转化为Integer类型方法Integer.parseInt(x[0])。
（3）返回字符串时数字可以与字符串直接相加。

### 代码

```java
class Solution {
    public String complexNumberMultiply(String a, String b) {
       String x[]= a.split("\\+|i");
       String y[]= b.split("\\+|i");
       int x_Rea=Integer.parseInt(x[0]);
       int x_Img=Integer.parseInt(x[1]);
       int y_Rea=Integer.parseInt(y[0]);
       int y_Img=Integer.parseInt(y[1]);
       return (x_Rea*y_Rea-x_Img*y_Img)+"+"+(x_Rea*y_Img+x_Img*y_Rea)+"i";
    }
}
```