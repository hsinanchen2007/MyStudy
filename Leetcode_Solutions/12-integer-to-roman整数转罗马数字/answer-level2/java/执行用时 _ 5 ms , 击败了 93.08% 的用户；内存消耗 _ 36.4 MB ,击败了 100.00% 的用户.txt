### 解题思路
获取各十百千位上的数字，分为0~3，5~8，4，9四种情况进行字符串拼接

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        int q = num / 1000 % 10;
        int b = num / 100 % 10;
        int s = num / 10 % 10;
        int g = num % 10;
        if (q != 0 ){
            sb.append("MMM".substring(0,q));
        }
        if (b>=0 &b<4){
            sb.append("CCC".substring(0,b));
        }else if (b>4&b<9){
            sb.append("DCCC".substring(0,b-4));
        }else if (b==4){
            sb.append("CD");
        }else {
            sb.append("CM");
        }
        if (s>=0 &s<4){
            sb.append("XXX".substring(0,s));
        }else if (s>4&s<9){
            sb.append("LXXX".substring(0,s-4));
        }else if (s==4){
            sb.append("XL");
        }else {
            sb.append("XC");
        }
        if (g>=0 &g<4){
            sb.append("III".substring(0,g));
        }else if (g>4&g<9){
            sb.append("VIII".substring(0,g-4));
        }else if (g==4){
            sb.append("IV");
        }else {
            sb.append("IX");
        }
        return sb.toString();
    }
}
```