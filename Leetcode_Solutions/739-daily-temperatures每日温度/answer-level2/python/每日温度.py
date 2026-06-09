####  方法一：
题目要求我们找出下一次温度比当天高距离的天数。因为温度只能在 `[30，100]` 之内，如果现在的温度是 `T[i]=50`，我们只需要找到下一个出现的 `51，52，…，100`，然后取最快出现的那个位置。

**算法：**
- 我们按逆序遍历列表，对于每个 `T[i]`，我们要知道 `(T[i],100]` 温度所出现的位置，为此我们用一个 `next` 数组记录该数据，若当前位置出现 `T[i]=100`，则我们将该索引记录在 `next[100]`。
- `warmer_index` 记录比当前温度高的索引位置，它等于 `next[T[i]+1], next[T[i]+2], ..., next[100]` 的最小值。

```Python [ ]
class Solution(object):
    def dailyTemperatures(self, T):
        nxt = [float('inf')] * 102
        ans = [0] * len(T)
        for i in xrange(len(T) - 1, -1, -1):
            #Use 102 so min(nxt[t]) has a default value
            warmer_index = min(nxt[t] for t in xrange(T[i]+1, 102))
            if warmer_index < float('inf'):
                ans[i] = warmer_index - i
            nxt[T[i]] = i
        return ans
```

```Java [ ]
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        int[] next = new int[101];
        Arrays.fill(next, Integer.MAX_VALUE);
        for (int i = T.length - 1; i >= 0; --i) {
            int warmer_index = Integer.MAX_VALUE;
            for (int t = T[i] + 1; t <= 100; ++t) {
                if (next[t] < warmer_index)
                    warmer_index = next[t];
            }
            if (warmer_index < Integer.MAX_VALUE)
                ans[i] = warmer_index - i;
            next[T[i]] = i;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(NW)$。其中 $N$ 是温度列表的长度，$W$ 是 `T[i]` 的可取值的数目。若 $W = 71$，则时间复杂度可以看作 $O(N)$。
* 空间复杂度：$O(N + W)$，`next` 数组和答案所用的空间。


####  方法二：栈
- 我们需要找到比当前 `T[i]` 温度更高的位置，那么必须要记录哪些信息？
- 我们试着找到 `T[0]` 过后温度升高的位置。如果知道 `T[10]=50`，则 `T[20]=50` 是无效信息，因为 `T[i]` 在 `T[20]` 以前已经到达了 50。如果 `t[20]=100` 将是有用的信息，因为如果 `t[0]=80`，那么 `T[20]` 将有可能是它的下一个温度升高的位置，而 `T[10]` 则不可能是。
- 因此，我们需要记住一个索引的列表，索引代表的温度严格递增。我们可以利用栈来实现这样的效果。

**算法：**
- 我们用栈记录索引，满足 `T[stack[-1]] < T[stack[-2]] < ...`，其中 `stack[-1]` 是栈的顶部，`stack[-2]` 是从顶部开始的第二个元素，依此类推；我们将在处理每个 `T[i]` 时保持 `stack[-1] > stack[-2] > ...`。
- 我们通过当前温度和栈顶索引所代表的温度比较来找到温度升高的位置。
- 举个例子：我们反向遍历处理 `t=[73，74，75，71，69，72，76，73]` ，通过看栈元素的变化来理解是如何工作的。为了清楚 `stack` 只包含索引 `i`，但是将把 `T[i]` 的值写在旁边的括号中，例如 `0 (73)`。
	- 当 `i = 7`，`stack = [7 (73)]`。`ans[i] = 0`。
	- 当 `i = 6`，`stack = [6 (76)]`。`ans[i] = 0`。
	- 当 `i = 5`，`stack = [5 (72), 6 (76)]`。`ans[i] = 1`。
	- 当 `i = 4`，`stack = [4 (69), 5 (72), 6 (76)]`。`ans[i] = 1`。
	- 当 `i = 3`，`stack = [3 (71), 5 (72), 6 (76)]`。`ans[i] = 2`。
	- 当 `i = 2`，`stack = [2 (75), 6 (76)]`。`ans[i] = 4`。
	- 当 `i = 1`，`stack = [1 (74), 2 (75), 6 (76)]`。`ans[i] = 1`。
	- 当 `i = 0`，`stack = [0 (73), 1 (74), 2 (75), 6 (76)]`。`ans[i] = 1`。

```Python [ ]
class Solution(object):
    def dailyTemperatures(self, T):
        ans = [0] * len(T)
        stack = [] #indexes from hottest to coldest
        for i in xrange(len(T) - 1, -1, -1):
            while stack and T[i] >= T[stack[-1]]:
                stack.pop()
            if stack:
                ans[i] = stack[-1] - i
            stack.append(i)
        return ans
```

```Java [ ]
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        Stack<Integer> stack = new Stack();
        for (int i = T.length - 1; i >= 0; --i) {
            while (!stack.isEmpty() && T[i] >= T[stack.peek()]) stack.pop();
            ans[i] = stack.isEmpty() ? 0 : stack.peek() - i;
            stack.push(i);
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 是 `T` 的长度，每个索引最多做一次压栈和出栈的操作。
* 空间复杂度：$O(W)$，其中 $W$ 是 `T[i]` 的可取值的数目。