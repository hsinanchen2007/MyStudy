
执行用时 :4 ms, 在所有 Java 提交中击败了99.90%的用户

内存消耗 :37 MB, 在所有 Java 提交中击败了99.33%的用户

思路：一共有numRows行，则通过观察可以进行numRows+numRows-2进行分组。

我们直接计算每一行的元素是什么。使用等差数列的方式，i表示行号

先看第一行，元素是(numRows+numRows - 2)*j + 0，即(numRows+numRows - 2)*j + i

再看最后一行，元素是((numRows+numRows - 2)*j + nums - 1，即(numRows+numRows - 2)*j + i

再看中间行，中间行每组多了一个元素，我们先不考虑多出来的那个中间元素，通过上面的规律，我们发现肯定也有一个(numRows+numRows - 2)*j + i

最后我们看中间的元素，根据等差数列，我们可以计算出对应的索引为(numRows+numRows - 2)*j + numRows+numRows - 2 -i。

```java
public String convert(String s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    int len = s.length();
    StringBuilder stringBuilder = new StringBuilder();
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j * (2 * numRows - 2) + i < len; j++) {
            stringBuilder.append(s.charAt(j * (2 * numRows - 2) + i));
            if (i < numRows - 1 && i > 0) {
                if (j * (2 * numRows - 2) + 2 * numRows - 2 - i < len) {
                    stringBuilder.append(s.charAt(j * (2 * numRows - 2) + 2 * numRows - 2 - i));
                }
            }
        }
    }
    return stringBuilder.toString();
}
```