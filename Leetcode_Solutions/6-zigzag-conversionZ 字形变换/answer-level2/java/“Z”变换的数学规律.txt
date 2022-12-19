### 解题思路
研究发现此题“Z”变换的数学规律：
在“Z”的顶部和底部（就是在两竖）的时候，后一个元素是前一个元素增加2\*numRows-2；
在中间的元素需要增加一个数，数的位置规律是i+2\*numRows - 2*row；

这题实际上的图形又不是“Z”也不是“N”。。。。
执行用时 :3 ms, 在所有 Java 提交中击败了99.27%的用户内存消耗 :41 MB, 在所有 Java 提交中击败了6.98%的用户**
### 代码

```java
class Solution {
    public static String convert(String s, int numRows) {
        int len = s.length();
        if (numRows == 1 || len <= numRows) {
            return s;
        }
        char[] chars = s.toCharArray();
        char[] result = new char[len];
        // 用row来代表每一行
        int row = 1;
        int i;
        int j = 0;
        while (row <= numRows){
            i = row - 1;
            result[j] = chars[i];
            j++;
            while ((i+2*numRows-2 < len) || (i+2*numRows - 2*row)<len){
                // 当位置在Z的顶和底部之间，需多增一位数
                if (i+2*numRows - 2*row < len && row != 1 && row !=numRows){
                    result[j] = chars[i+2*numRows - 2*row];
                    j++;
                }
                // 当位置在Z的顶部或者底部
                if (i+2*numRows-2 < len){
                    result[j] = chars[i+2*numRows-2];
                    j++;
                }
                i = i+2*numRows-2;
            }
            row++;
        }
        return String.copyValueOf(result);
    }
}
```