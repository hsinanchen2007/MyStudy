### 解题思路
检查有无 正负号，有的话去掉。对去掉的字符串做reverse()操作，然后再拼接上正负号。
使用long来解决溢出问题。

### 代码

```java
class Solution {
    public int reverse(int x) {
        String a = "" + x;
        String sign = "";
        if(a.startsWith("+") || a.startsWith("-")){
            sign = a.substring(0,1);
            a = a.substring(1,a.length());
        }
        StringBuilder sb = new StringBuilder(a);
        long num = Long.parseLong(sign + sb.reverse().toString());
        if(num >= Integer.MIN_VALUE && num <= Integer.MAX_VALUE){
            return (int)num;
        }else{
            return  0;
        }
        
    }
}
```