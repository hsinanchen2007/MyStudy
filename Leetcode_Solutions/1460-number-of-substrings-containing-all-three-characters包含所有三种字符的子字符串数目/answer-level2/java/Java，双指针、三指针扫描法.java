
[第 20 场双周赛](https://leetcode-cn.com/contest/biweekly-contest-20/) 第三题


  - **直接解法**：遍历所有位置开始包含 `abc` 的最短子串，每个子串的后续字符数量之和就是答案。因为题目的字符串长度非常长，显然会超时

假设 `S(n)` 是从 `n` 位置开始的包含 `abc` 的最短子串，我们希望在获得 `S(n+1)` 时能够利用到 `S(n)` 的值：
- **双指针扫描（滑动窗口）**：记录 `n` 位置开始的最短子串 `(n, m)` 范围内，`abc` 出现的次数，这样 `(n+1, m)` 范围的 `abc` 的数量只要将 `n` 位置对应字符数量减一即可，如果都大于 `0` 则 `(n+1, m)` 就是最短子串，如果有一个值为 `0` 则继续从向后搜索。
- **三指针扫描（最早出现位置）**：记录 `n` 位置开始的最短子串 `(n, m)` 范围内，`abc` 最早出现的位置，这样 `(n+1, m)` 范围的 abc 是否都存在，就相当于 `(n+1, m)` 范围是否出现过 `n` 位置的字符，出现过则 `(n+1, m)` 就是最短子串，没出现则向后搜索。（为了避免重新检查一遍 `(n+1, m)`，可以将每个字符出现的位置存储起来。）
 - **三指针扫描（最晚出现位置）**：记录 `n` 位置开始的最短子串 `(n, m)` 范围内，`abc` 出现的最晚位置。在最早出现位置方式中，每次从 `(n, m)` 变为 `(n+1, m)` 范围时，都会截断最前面的元素，此时不得不检查 `(n+1, m)` 内有没有出现过被截断的字符，而如果记录的是最晚出现位置，我们可以立即检查被截断的字符的最晚出现位置，如果是 n ，则说明 `(n+1, m)` 范围内没有出现过，需要向后搜索，否则说明已经出现过，`(n+1, m)` 就是最短子串。

以上三种做法都相当于减少了 (n+1, m) 范围的查找。

**下面是方法一的 Java 解法：** （其他代码待补充，明天又要周赛，不知道有没有时间补）
```java
class Solution {
    public int numberOfSubstrings(String s) {
        int countA = 0, countB = 0, countC = 0,count = 0;
        int start = 0;
        for(int i = 0; i <= s.length(); i++) {
            if (countA > 0 && countB > 0 && countC > 0) {
                count += s.length() - i + 1;
                switch(s.charAt(start++)) {
                    case 'a': countA--; i--; break;
                    case 'b': countB--; i--; break;
                    case 'c': countC--; i--; break;
                }
                
            } else if (i < s.length()){
                switch(s.charAt(i)) {
                    case 'a': countA++; break;
                    case 'b': countB++; break;
                    case 'c': countC++; break;
                }
            }
        }
        
        return count;
    }
}
```

解法备注：
- 代码不是很简洁，主要是 abc 的保存问题，可以修改为 Map 或数组保存。