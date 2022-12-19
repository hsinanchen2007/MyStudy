### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        int length = s.length();
        if (numRows == 1)    return s;
        StringBuilder res = new StringBuilder();
        //第0行
        int i0 = 0;
        while (i0 < length) {
            res.append(s.charAt(i0));
            i0 += 2 * numRows - 2;
        }
        //中间行
        if (numRows >= 3) {
            for (int k = 1; k < numRows - 1; k++) {//中间的每一行
                int i = k;//第一个元素的下标
                int j = 2 * numRows - k - 2;//第二个元素的下标
                while (i < length || j < length){
                    if (i < length) {
                        res.append(s.charAt(i));
                        i += 2 * numRows - 2;
                    }
                    if (j < length) {
                        res.append(s.charAt(j));
                        j += 2 * numRows - 2;
                    }
                }
            }
        }
        //第-1行
        int i3 = numRows - 1;
        while (i3 < length) {
            res.append(s.charAt(i3));
            i3 += 2 * numRows - 2;
        }
        //将numRows个sb连接,再toString
        return res.toString();
    }
}
```