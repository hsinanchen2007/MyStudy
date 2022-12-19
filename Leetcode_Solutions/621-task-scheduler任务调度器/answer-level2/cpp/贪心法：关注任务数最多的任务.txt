解题思路：

贪心法：关注任务数最多的任务

因为题目要求相同种类的任务之间必须有长度为 n 的冷却时间，所以任务数最多的任务决定了最短时间的底线。

首先将输入任务进行统计。

假设最多的任务数是 q，不失一般性，假设至少其中的任务A的任务数是 q，那么这q个A最少需要(q - 1) * (n + 1) + 1的时间，即类似这样的模式：

A - 空 - 空 - 空 | A - 空 - 空 - 空 | A - 空 - 空 - 空 | A

可以将 A - n个空 作为一段，则一共有(q - 1) * n个空位。

A - n个空 | A - n个空 | A - n个空 | A 

其余的任务可以填入这些空位。

如果这些个空位填不满，最短时间由最后一段填充的情况决定。

以这个用例为例：

tasks1 = ["A","A","A","B","B","B","C"], n = 2

A的任务数最多，有3个，最少要求空2位，所以首先有A的排列：

A - 空 - 空 | A - 空 - 空 | A

将B填入空位：

A - B - 空 | A - B - 空 | A - B 

再将C填入空位：

A - B - C | A - B - 空 | A - B 

最短时间是7，到最后一个B为止。

最后一段填充了两个任务A、B，因为它们的任务数都是最大值3。

即计算任务数等于最大值的任务的个数，可以知道最后一段填充的情况。


如果其余的任务填满所有的空位后，可以将剩余的任务插入已经填入的任务序列，总时间就是任务总数。

例如

tasks2 = ["A","A","A","B","B","B","D","D","E","E"], n = 2

任务总数是10，空位可以全部填满。

在填充了A、B之后的状态是：

A - B - 空 | A - B - 空 | A - B

接着填两个D，填入前两段：

A - B - D | A - B - D | A - B 

接着要填两个E，也插入前两段：

A - B - D - E | A - B - D - E | A - B 

总时间为10，等于任务总数。前面的空位都已经填满。

这样可以保证不会违反题目的规定，相同种类的任务之间至少有长度为 n 的冷却时间，而且空闲时间最少，为0空闲。

max(res, tasks.length)这个最大值比较是怎么来的？

上面给出了具体的解释，就是tasks不能填满最大任务数给出的空位，需要根据最后一段的空位数来确定最小时间。
而tasks总数可以填满空位，时间等于tasks总数。

以下是代码：

```python []
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt =  collections.Counter(tasks)
        tasksSize, maxCnt = len(tasks), cnt.most_common(1)[0][1]
        res = (maxCnt - 1) * (n + 1) + list(cnt.values()).count(maxCnt)
        return max(res, tasksSize)
```
```c++ []
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tasksSize = tasks.size();
        int charNum = 26;
        vector<int> cnt(charNum, 0);
        for (int i = 0; i < tasksSize; i++) {
            cnt[tasks[i] - 'A']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int res = 0;
        int maxCnt = cnt[0];
        res = (maxCnt - 1) * (n + 1) + 1;
        for (int idx = 1; idx < charNum && idx <= n && cnt[idx] == maxCnt; idx++) {
            res++;
        }
        return max(res, tasksSize);
    }
};
```
```java []
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int tasksSize = tasks.length;
        int charNum = 26;
        int[] cnt = new int[charNum];
        for (char c: tasks) {
            cnt[c - 'A']++;
        }
        Arrays.sort(cnt);
        int res = 0;
        int maxCnt = cnt[charNum - 1];
        res = (maxCnt - 1) * (n + 1) + 1;
        for (int idx = charNum - 2; idx >= 0 && idx >= charNum - n && cnt[idx] == maxCnt; idx--) {
            res++;
        }
        return Math.max(res, tasksSize);
    }
};
```


