### 解题思路

官方的题解已经很不错了，在这里针对一些测试用例给出优化方法。

#### 1.存储剩余参议员的数据结构（主要优化）

许多题解采用的方法是在已被淘汰的议员上增加标记，例如将已淘汰的议员从R或D换成其他的字符。

这样做的一大问题是：由于选举可以重复执行，绝大多数情况下字符串将会遍历多次。随着被淘汰者增加，遍历的效率会越来越低。

该问题可以通过环形链表可以解决，被淘汰的议员直接删除即可。

官方使用的双向队列效率也很高，并且实现代码简洁，也可以使用。

#### 2.循环终止条件（次要优化）

通过对问题的分析发现，淘汰对方参议员的行动可以推迟至对方行动前执行，而不改变最终结果。因此我们可以增加一个“淘汰许可”的概念，以存储一方可以淘汰对方的人数。

只要针对某一方的淘汰许可的数目超过对方剩余成员数，不需要实际将剩余成员全部淘汰就可以决出胜负。循环就可以结束。

### 代码

代码使用数组来实现环形链表。其实代码有不少赘余之处，可以进一步优化。

```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        int member = senate.size();
        int r_member = 0;
        int d_member = 0;
        int jmp_table[member];
        for (int i = 0; i < member; ++i) {
            jmp_table[i] = i + 1;
            if (senate[i] == 'R') ++r_member;
        }
        jmp_table[member - 1] = 0;
        d_member = member - r_member;
        int r_vote = 0;
        int d_vote = 0;
        int pos = 0;
        int prev_pos = 0;
        while (true) {
            if (senate[pos] == 'R') {
                if (d_vote > 0) {
                    jmp_table[prev_pos] = jmp_table[pos];
                    --r_member;
                    --d_vote;
                } else {
                    ++r_vote;
                    prev_pos = pos;
                }
                if (r_vote >= d_member) return "Radiant";
            } else {
                if (r_vote > 0) {
                    jmp_table[prev_pos] = jmp_table[pos];
                    --d_member;
                    --r_vote;
                } else {
                    ++d_vote;
                    prev_pos = pos;
                }
                if (d_vote >= r_member) return "Dire";
            }
            pos = jmp_table[pos];
        }
    }
};
```