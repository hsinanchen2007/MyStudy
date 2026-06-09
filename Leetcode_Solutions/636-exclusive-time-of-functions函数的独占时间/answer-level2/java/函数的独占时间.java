#### 方法一：栈

我们可以使用栈来模拟函数的调用，即在遇到一条包含 `start` 的日志时，我们将对应的函数 `id` 入栈；在遇到一条包含 `end` 的日志时，我们将对应的函数 `id` 出栈。在每一个时刻，栈中的所有函数均为被调用的函数，而栈顶的函数为正在执行的函数。

在每条日志的时间戳后，栈顶的函数会独占执行，直到下一条日志的时间戳，因此我们可以根据相邻两条日志的时间戳差值，来计算函数的独占时间。我们依次遍历所有的日志，对于第 `i` 条日志，如果它包含 `start`，那么栈顶函数从其时间戳 `time[i]` 开始运行，即 `prev = time[i]`；如果它包含 `end`，那么栈顶函数从其时间戳 `time[i]` 的下一个时间开始运行，即 `prev = time[i] + 1`。对于第 `i + 1` 条日志，如果它包含 `start`，那么在时间戳 `time[i + 1]` 时，有新的函数被调用，因此原来的栈顶函数的独占时间为 `time[i + 1] - prev`；如果它包含 `end`，那么在时间戳 `time[i + 1]` 时，原来的栈顶函数执行结束，独占时间为 `time[i + 1] - prev + 1`。在这之后，我们更新 `prev` 并遍历第 `i + 2` 条日志。在遍历结束后，我们就可以得到所有函数的独占时间。

<![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/636/636_Exclusive_Time_of_FunctionsSlide8.PNG)>


```Java [sol1]
public class Solution {
    public int[] exclusiveTime(int n, List < String > logs) {
        Stack < Integer > stack = new Stack < > ();
        int[] res = new int[n];
        String[] s = logs.get(0).split(":");
        stack.push(Integer.parseInt(s[0]));
        int i = 1, prev = Integer.parseInt(s[2]);
        while (i < logs.size()) {
            s = logs.get(i).split(":");
            if (s[1].equals("start")) {
                if (!stack.isEmpty())
                    res[stack.peek()] += Integer.parseInt(s[2]) - prev;
                stack.push(Integer.parseInt(s[0]));
                prev = Integer.parseInt(s[2]);
            } else {
                res[stack.peek()] += Integer.parseInt(s[2]) - prev + 1;
                stack.pop();
                prev = Integer.parseInt(s[2]) + 1;
            }
            i++;
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。我们需要遍历所有的日志，因为有 $N$ 个函数，因此日志的数量为 $2N$。

* 空间复杂度：$O(N)$，为栈占用的空间。