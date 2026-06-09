观察z变换图形
```
   0 1 2 3 4 5 6 7 8 9

0  L     D     R     T
1  E   O E   I I   O
2  E C   I H   N D
3  T     S     G

```
将图形拆分为从左到右排列的多个有规律的区块，如下为第一个区块
```
L
E   O
E C
T
```
设行数为`m`，区块满字符的情况下字符数为`k = 2m - 2`，给定字符串长度为`n = s.length()`，则区块数量为`blockNum = n / k + (n % k == 0 ? 0 : 1)`。每个区块可以分为两个部分，第一列部分与其余列部分。定义一个二元组`(p, q)`，`p`代表字符的列位置，`q`代表字符在原字符串中的位置，则：
1. 在第`j`个区块中的第一部分（每行一个字符），第`i`行的字符为`(m * j - j, k * j + i)`
2. 在第`j`个区块中的第二部分（除头尾两行没有字符外每行一个字符），第`i`行的字符为`(m * j - j + m - i - 1, k * j + 2 * m - i - 2)`

好了，有了上面的计算结果，就能很容易地编码出输出后的字符串了，甚至可以输出带空格和换行符的字符串，代码如下（注释掉的部分是带空格和换行符的版本）：
```java
    public String convert(String s, int m) {
        if (m == 1 || s.length() == 0) return s;
        int k = (m - 2) + m;
        int n = s.length();
        int blockNum = n / k + (n % k == 0 ? 0 : 1);
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            int cursor = 0;
            for (int j = 0; j < blockNum; j++) {
                int charIndex = k * j + i;
                if (charIndex >= n) break;
                cursor = addCharInIndex(sb, cursor, m * j - j, s.charAt(charIndex));
                if (i > 0 && i < m - 1) {
                    charIndex = k * j + 2 * m - i - 2;
                    if (charIndex >= n) break;
                    cursor = addCharInIndex(sb, cursor, m * j - j + m - i - 1, s.charAt(charIndex));
                }
            }
            addLineSeparator(sb);
        }
        
        return sb.toString();
    }
    
//    private int addCharInIndex(StringBuilder sb, int cursor, int index, char c) {
//        while(cursor <= index) {
//            if (cursor == index) {
//                sb.append(c);
//            } else {
//                sb.append(" ");
//            }
//            cursor++;
//        }
//        return cursor;
//    }
    
//    private void addLineSeparator(StringBuilder sb) {
//        sb.append("\n");
//    }
    
    private int addCharInIndex(StringBuilder sb, int cursor, int index, char c) {
        sb.append(c);
        return cursor++;
    }
    
    private void addLineSeparator(StringBuilder sb) {
    }
```

运行击败：99.3%，内存击败：97.3%