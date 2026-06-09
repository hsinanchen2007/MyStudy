找规律，按行输出即可
定义：n行
第一行：0, 0+((n - 1) * 2), ...

第n行：n - 1, n - 1+((n - 1) * 2), ...
每两个竖行的间隔是一样的，如：8-0 == 9-7 + 7-1
![image.png](https://pic.leetcode-cn.com/e1bf69888d49427f230805e4e1b56b82f6a1a58d59231a6f228198e55ad37b25-image.png)
```java []
class Solution {
    public String convert(String s, int numRows) {
        //画图 自己看，有规律
        //先找出竖行
        if (numRows == 1) {
            return s;
        }
        int len = s.length();
        if (len <= numRows) {
            return s;
        }
        StringBuilder sb = new StringBuilder();
        //最大间距
        int max = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++) {
            int ind = i;
            sb.append(s.charAt(ind));
            if (ind == 0 || ind == numRows - 1) {
                while ((ind = ind + max) < len) {
                    sb.append(s.charAt(ind));
                }
            } else {
                int temp = max - (i * 2);
                while ((ind = ind + temp) < len) {
                    sb.append(s.charAt(ind));
                    if ((ind = ind + max - temp) < len) {
                        sb.append(s.charAt(ind));
                    }
                }
            }
        }
        return sb.toString();
    }
}
```

