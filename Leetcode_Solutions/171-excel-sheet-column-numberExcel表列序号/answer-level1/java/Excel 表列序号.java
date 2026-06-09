理解了题目之后就会发现这是一个很简单的二十六进制问题，其思路就和我们平时计算十六进制是一样的，废话不多说，直接看代码：


```
class Solution {
    public int titleToNumber(String s) {
        int result = 0;
        // 表示每位所代表的单位，例如最后一位表示1，倒数第二位表示26，以此类推。
        int scale = 1;
        for (int i = s.length()-1; i >= 0; i --) {
            // 累加每位的数值。
            result += (s.charAt(i) - 'A' + 1) * scale;
            // 更新当前位的单位值，以方便在下次循环中进行正确计算。
            scale *= 26;
        }
        return result;
    }
}
```
