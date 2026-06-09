### 解题思路
1. 先转换为字符串，将负号提取为前缀
2. 然后将字符串不断两极对调存入char[]中
3. 如果字符串长度为奇数，则将最中间的字符串赋值给char[]中间位置（注意：不在while循环中判断，不然每次循环都要判断，这样只需要判断一次）
4. 将前缀 + 字符串转换回int
5. 如果抛出异常说明超过最大值了，返回0
#### 复杂度
时间频度，字符串每个char都要被遍历一次：T(n)
时间复杂度：O(n)
空间复杂度，有一个char[]：O(n)

### 代码

```java
class Solution {
    public int reverse(int x) {
        String s = String.valueOf(x);
        String prefix = "";
        if (s.startsWith("-")) {
            prefix = "-";
            s = s.substring(1, s.length());
        }
        int i = 0, j = s.length() - 1;
        char[] temp = new char[s.length()];
        while ( i < (s.length() / 2) && j >= (s.length() / 2)) {
            temp[i] = s.charAt(j);
            temp[j] = s.charAt(i);
            i++;
            j--;
        }
        if (s.length() % 2 == 1) {
            temp[s.length() / 2] = s.charAt(s.length() / 2);
        }
        try {
            return Integer.parseInt(prefix + String.valueOf(temp));
        } catch (Throwable t) {
            return 0;
        }
    }
}
```