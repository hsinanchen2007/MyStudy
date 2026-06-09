### 解题思路
平日的题好像是简单一些

本题使用一前一后两个指针，统计相同字符连续出现的个数，构建新字符串返回

具体来说，两指针在`0`位初始，后指针`b`每次一直移动到所指字符与前指针`a`所指字符不同的地方，
则`a`所指的字符出现次数为`b-a`，将字符及其次数插入新字符串中，
最后`a`跳转到`b`的位置，进入下一个循环

### 代码

```java
class Solution {
    public String compressString(String S) {
        StringBuilder sb = new StringBuilder();
        int a = 0;
        int b = 0;
        while(a < S.length()) {
            while(b < S.length() && S.charAt(a) == S.charAt(b)) {
                b++;
            }
            sb.append(S.charAt(a)).append(String.valueOf(b - a));
            a = b;
        }
        return sb.length() >= S.length() ? S : sb.toString();
    }
}
```