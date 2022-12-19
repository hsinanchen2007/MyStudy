### 解题思路
刚看到的时候，想要使用判断分支以及字符数组累积实现，但是过程有点繁琐，后来采用这种简便的做法。
因为测试量只达到3999，使用四个数组表示每一个位数对应的字符串，比如tens数组记录的是10到90的罗马数字表示形式，同理其他三个分别是个位数、百位数、千位数的字符串数组。最后我们只需要根据对应位数上的数字找到对应的最付出累和相加输出即可。比如说：1314，千位数为1，找到M，百位数为3，找到CCC，十位数为1，找到X，个位数为4，找到IV，结果为MCCCXIV。

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        String[] I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		String[] tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		String[] hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		String[] thousands = {"", "M", "MM", "MMM"};
		return thousands[num/1000] + hundreds[num%1000/100] + tens[num%100/10] + I[num%10];
    }
}
```