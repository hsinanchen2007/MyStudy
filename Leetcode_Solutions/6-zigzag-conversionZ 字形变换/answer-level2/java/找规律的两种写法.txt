因为在N中，每一个位置的下一次出现是间隔(numRows - 1) * 2的，然而除了首位两行之外的行，会在这个间隔中还多出现一次，所以可以依次以固定间隔获取元素并添加到String中，类似于
```
while (循环条件) {
    buffer.append(s.charAt(n));
    if (特殊情况) {
        buffer.append(s.charAt());
    }
    n = (numRows - 1) * 2 + n;
}
```
然后只需在特殊情况中加上间隔中多的元素即可，并且从第一行起，每下降一行，减少的为2，所以
```
if(numRows == 1) return s;
        StringBuffer buffer = new StringBuffer();
        int n;
        for (int i = 0; i < numRows; i++) {
            n = i;
            while (n < s.length()) {
                buffer.append(s.charAt(n));
                if (i != 0 || numRows - 1 != i) {
                    int k = (numRows - 1 - i) * 2 + n;
                    if(k < s.length()) buffer.append(s.charAt(k));
                    else break;
                }
                n = (numRows - 1) * 2 + n;
            }
        }
        return buffer.toString();
```
需要注意的是中间间隔的元素下标判断越界


还有一种类似的写法是利用有间隔的行数连续两次相加次数应该等于固定次数，所以用boolean去判断
```
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        StringBuffer buffer = new StringBuffer();
        int n;
        boolean b ;
        for (int i = 0; i < numRows; i++) {
            n = i;
            b = true;
            while (n < s.length()) {
                buffer.append(s.charAt(n));
                if (i == 0 || numRows - 1 == i) {
                    n = (numRows - 1) * 2 + n;
                } else {
                    if (b) {
                        n = (numRows - 1) * 2 + n - 2 * i;
                        b = false;
                    } else {
                        n = 2 *i+ n ;
                        b = true;
                    }
                }
            }
        }
        return buffer.toString();
    }
}
```
