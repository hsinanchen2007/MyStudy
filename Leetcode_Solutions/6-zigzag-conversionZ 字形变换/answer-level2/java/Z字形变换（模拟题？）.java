### 同官方方法一
最开始看到这个题想到了CCF的一道小球碰撞的模拟题，这个Z字形无疑也就是先从上往下，然后从下往上，两个方向相反，每一次方向上最多走numRows距离，每次在第0行和第numRows-1行就会转变方向，所以开头创建一个长度为numRows长度的StringBuilder数组，然后根据定义的curRow存储当前的行数，往StringBuilder数组对应下标的StringBuilder对象添加字符，最后集中在一个StringBuilder对象中即为答案。

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1) return s;
        int len = Math.min(s.length(),numRows);
        StringBuilder[] stringBuilders = new StringBuilder[len];
        for (int i = 0; i < len ; i++)
            stringBuilders[i] = new StringBuilder();
        int curRow = 0;
        boolean goingDown = false;
        for (int i=0;i<s.length();i++) {
            stringBuilders[curRow].append(s.charAt(i));
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        StringBuilder ret = new StringBuilder();
        for (int i = 0; i < len; i++) {
            ret.append(stringBuilders[i]);
        }
        return ret.toString();
    }
}
```