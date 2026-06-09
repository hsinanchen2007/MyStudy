### 解题思路
O(n^2)
官方题解是2n-1个中心，这里是n个，每次向两边扩展一个字符，就是情况多点：
0. 单个越界就按2号情况判断，两边都越界，说明整个字符串就是回文，直接返回
1. 两边的字符相同，直接加入字串，记录是否是相同的字符
2. 不同但是有一边的字符和初始字符相同且目前回文全部都是这个字符，加入字串
3. 其他情况说明字串接不下去了，保存结果，如果目前最长子串的一半比接下来中心位置到整个字符串结尾还大，说明后面推算的子串没机会了，直接返回

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        char[] cs = s.toCharArray();
        String ret = "";
        char tmp1, tmp2, error = (char) -1;
        for (int i = 0; i < cs.length; i++) {
            char c = cs[i];
            boolean isAllSame = true;
            StringBuilder sb = new StringBuilder("" + c);
            int h = i - 1, t = i + 1;

            while(true) {
                if (h < 0)
                    tmp1 = error;
                else
                    tmp1 = cs[h];

                if (t >= cs.length)
                    tmp2 = error;
                else
                    tmp2 = cs[t];

                if (tmp1 == tmp2) {
                    if (tmp1 == error)
                        return sb.toString();
                    sb.insert(0, tmp1);
                    sb.append(tmp2);
                    isAllSame &= tmp1 == c;
                    h--;
                    t++;
                } else if (isAllSame && (tmp1 == c || tmp2 == c)) {
                    if (tmp1 == c) {
                        sb.insert(0, tmp1);
                        h--;
                    }
                    if (tmp2 == c) {
                        sb.append(tmp2);
                        t++;
                    }
                } else {
                    if (sb.length() > ret.length())
                        ret = sb.toString();
                    // 没可能了，安心返回吧
                    if (ret.length() / 2 > cs.length - i)
                        return ret;
                    break;
                }
            }
        }

        return ret;

    }
}
```