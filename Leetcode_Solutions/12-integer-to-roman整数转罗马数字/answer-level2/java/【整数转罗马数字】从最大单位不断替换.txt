### 思路
>首先把罗马数字和阿拉伯数字的转换关系用两个数组表示，然后不断将当前数字与当前最大单位作比较，每次转换完就减去已转换的数字，再比较...直到当前数字等于`0`.

### 示例
对于`3690`，一开始最大单位是`"M"`,表示`1000`,那么就用`3`个`M`转换出`3000`，既然`3000`已经用`MMM`转换出来了，就减去`3000`，剩下`690`；
对于`690`，目前最大单位是`CM`表示`900`，但是`690`不够一个单位，就看下一个比较小的单位`D`，也就是`500`，而`690`可以先用一个`D`转换，然后再减去已经转换的`500`剩下`190`，
...
之后步骤同理，一直到剩下的数字等于`0`结束转换。


### 代码
```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder ans = new StringBuilder();
        String[] roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};  // 罗马数字
        int[] arab = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};  // 阿拉伯数字
        int index = 0;
        while (num > 0) {
            int count = num / arab[index];
            while (count-- > 0) {
                ans.append(roman[index]);
            }
            num %= arab[index];
            index++;
        }
        return ans.toString();
    }
}
```
