* L     D     R         0    6     12
* E   O E   I I         1  5 7  11 13
* E C   I H   N         2 4  8 10  14
* T     S     G         3    9     15


//代码有点不优雅,不过蛮快的
public static String convert(String s, int numRows) {
    String result = null;
    if (s != null && numRows > 0) {
        if (numRows == 1 || s.length() <= numRows) return s;

        int len = s.length();
        char[] chars = s.toCharArray();
        char[] targetChars = new char[len];
        int[] targetIdxs = new int[len];

        //建立原字符串字符跟目标字符串字符之间的映射关系
        int targetIdx = 0;
        int loop = numRows - 1;
        for (int i = 0; i <= loop; i++) {
            int j = i;
            while (j < len) {
                targetIdxs[targetIdx] = j;
                targetChars[targetIdx] = chars[j];
                if (i == 0 || i == loop) {
                    //首or尾
                    j += loop * 2;
                } else {
                    //中间
                    if (j < loop * 2) {
                        //起始竖线:走势向下,与右侧线差距逐渐变小;起始斜线:走势向上,与右侧线差距逐渐变大
                        j += 2 * (j < loop ? loop - i : i);
                    } else {
                        //直接往后叠
                        j = targetIdxs[targetIdx - 1] + loop * 2;
                    }
                }
                targetIdx++;
            }
        }
        result = String.valueOf(targetChars);
    }
    return result;
}