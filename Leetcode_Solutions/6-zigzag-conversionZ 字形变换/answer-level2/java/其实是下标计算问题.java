### 解题思路
1. 把每个竖线看做一个柱子，每个柱子字母间的水平距离为：(numRows * 2) - 2
2. 除了第一行和最后一行，中间的行非第一个柱子，其他柱子的字母前面都有一个字母，下标为当前柱子字母下标减去(row * 2)
#### 边界
1. 如果numRows = 1，那么(numRows * 2) - 2 = 0，就会陷入死循环，需要特殊处理，这时结果就是s
2. 如果最后一个柱子少于s.length()，但是依然也要看看柱子前面那个值是否少于s.lengt()否则会漏算
#### 时间复杂度
字符串中每个char都遍历一遍，时间复杂度为O(n)
创建了额外的char[]，空间复杂度为O(n)，感觉这个题目空间复杂度不能省，一定要有地方存储中间结果

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if (s == null || s.length() == 0) {
            return "";
        }
        if(numRows == 1) {
            return s;
        }
        char[] newArr = new char[s.length()];
        int idx = 0;
        // 遍历每一行
        for (int row = 0; row < numRows; row++) {
            // 每一行开始的下标就是行号
            // 把竖着的看做柱子，每一个柱子到另一个柱子的下标距离为(numRows * 2) - 2
            int i = row;
            for (; i < s.length(); i += ((numRows * 2) - 2)) {
                // 不是第一行和最后一行，计算柱子前面的值
                if (row > 0 && row < (numRows - 1) && i > row) {
                    newArr[idx++] = s.charAt(i - (row * 2));
                }
                newArr[idx++] = s.charAt(i);
            }
            //有的时候最后一个柱子为空，但是前面有值
            if (row > 0 && row < (numRows - 1) && i > row
                    && (i - (row * 2)) < s.length()) {
                newArr[idx++] = s.charAt(i - (row * 2));
            }
        }
        return String.valueOf(newArr);
    }
}
```