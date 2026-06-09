### 解题思路
二进制运算,考虑末位相加,获取位数最大的char数组,位数不足的数组前面取0,声明一个变量表示是否存在进位,for循环从最长数组的末位开始,最后判断是否进位

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        char[] charsa = a.toCharArray();
        char[] charsb = b.toCharArray();
        char[] max = charsa.length > charsb.length ? charsa : charsb;
        int c = 0;
        for(int i = 0;i < max.length;i++) {
            int a1 = (charsa.length - 1 - i) >= 0 ? (charsa[charsa.length - 1 - i] - '0') : 0;
            int b1 = (charsb.length - 1 - i) >= 0 ? (charsb[charsb.length - 1 - i] - '0') : 0;
            int res = a1 + b1 + c;
            if(res == 0) {
                max[max.length - 1 - i] = '0';
                c = 0;
            } else if(res == 1) {
                max[max.length - 1 - i] = '1';
                c = 0;
            } else if(res == 2) {
                max[max.length - 1 - i] = '0';
                c = 1;
            } else if(res == 3) {
                max[max.length - 1 - i] = '1';
                c = 1;
            }
        }
        return c == 0 ? new String(max): "1"+new String(max);
    }
}
```