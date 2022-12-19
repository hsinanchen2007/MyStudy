#### 方法 1：开始结束事件 [Accepted]

**想法**

我们可以把问题想象为在一条数字直线上画区间。这让我们想到开始结束事件。

为了说明这个概念，我们假设有 `nums = [10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13]` ，没有 `9` 和 `14` 。我们必须有 2 个序列从 10 开始， 2 个序列从 11 开始， 3 个序列到 12 结束。

总的来说，当考虑一连串连续的整数 `x` ，令 `C = count[x+1] - count[x]` ，如果 `C > 0` ，必须有 `C` 个子序列从 `x+1` 开始，如果 `C < 0` ，必须有 `-C` 个子序列在 `x` 结束。即使区间内有更多的结束端点，`C` 至少是一个下界。

在上面的例子中， `count[11] - count[10] = 2` 和 `count[13] - count[12] = -3` 表明有两个子序列从 `11` 开始，且有三个子序列在 `12` 结束。

如果我们知道有一些子序列从 `1` 和 `4` 开始，同时有一些子序列在 `5` 和 `7` 结束，为了最大化最短子序列，我们应该让 `1` 与 `5` 配对， `4` 与 `7` 配对。

**算法**

对于每一组数字，我们求出数字是 `t` 的次数 `count` 。进一步地，令 `prev, prev_count` 为前一个数字和它出现的次数。

然后，总共会有 `abs(count - prev_count)` 个事件发生：如果 `count > prev_count` ，那么我们增加 `count - prev_count` 个以 `t` 开始的事件到 `starts`，如果 `count < prev_count` ，我们将从 `starts.popleft()` 获取以 `t-1` 为结束的子区间的开始数字。

更具体的，当我们结束一个连续的组，我们会得到 `prev_count` 个结束的子数组，而当我们在一个连续的组中时，我们会有 `count - prev_count` 个开始或者 `prev_count - count` 个结束。

比方说， `nums = [1,2,3,3,4,5]` ，那么开始的位置在 `1` 和 `3`，结束的位置在 `3` 和 `5`。我们的算法会如下进行：

* 当 `t = 1, count = 1` 时： `starts = [1]`
* 当 `t = 2, count = 1` 时： `starts = [1]`
* 当 `t = 3, count = 2` 时：  `starts = [1, 3]`
* 当 `t = 4, count = 1` 时： `starts = [3]` ，由于 `prev_count - count = 1` ，我们会结束一个事件，当 `t-1 >= starts.popleft() + 2` 成立时我们才认为这是一个合法的事件。
* 当 `t = 5, count = 1` 时： `starts = [3]`

在最后，我们将 `prev_count` 与 `nums[-1]` 作为最后一次结束事件的次数和数字。

```Python []
class Solution(object):
    def isPossible(self, nums):
        prev, prev_count = None, 0
        starts = collections.deque()
        for t, grp in itertools.groupby(nums):
            count = len(list(grp))
            if prev is not None and t - prev != 1:
                for _ in xrange(prev_count):
                    if prev < starts.popleft() + 2:
                        return False
                prev, prev_count = None, 0

            if prev is None or t - prev == 1:
                if count > prev_count:
                    for _ in xrange(count - prev_count):
                        starts.append(t)
                elif count < prev_count:
                    for _ in xrange(prev_count - count):
                        if t-1 < starts.popleft() + 2:
                            return False

            prev, prev_count = t, count

        return all(nums[-1] >= x+2 for x in starts)
```

```Java []
class Solution {
    public boolean isPossible(int[] nums) {
        Integer prev = null;
        int prevCount = 0;
        Queue<Integer> starts = new LinkedList();
        int anchor = 0;
        for (int i = 0; i < nums.length; ++i) {
            int t = nums[i];
            if (i == nums.length - 1 || nums[i+1] != t) {
                int count = i - anchor + 1;
                if (prev != null && t - prev != 1) {
                    while (prevCount-- > 0)
                        if (prev < starts.poll() + 2) return false;
                    prev = null;
                }

                if (prev == null || t - prev == 1) {
                    while (prevCount > count) {
                        prevCount--;
                        if (t-1 < starts.poll() + 2)
                            return false;
                    }
                    while (prevCount++ < count)
                        starts.add(t);
                }
                prev = t;
                prevCount = count;
                anchor = i+1;
            }
        }

        while (prevCount-- > 0)
            if (nums[nums.length - 1] < starts.poll() + 2)
                return false;
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是 `nums` 的长度。我们遍历整个数组，每个时间被添加到 `starts` 和弹出最多一次。

* 空间复杂度： $O(N)$，`starts` 的大小。

#### 方法 2：贪心 [Accepted]

**想法**

我们把 3 个或更多的连续数字称作 *chain*。

我们从左到右考虑每一个数字 `x`，如果 `x` 可以被添加到当前的 chain 中，我们将 `x` 添加到 chain 中，这一定会比创建一个新的 chain 要更好。

为什么呢？如果我们以 `x` 为起点新创建一个 chain ，这条新创建更短的链是可以接在之前的链上的，这可能会帮助我们避免创建一个从 `x` 开始的长度为 1 或者 2 的短链。

**算法**

我们将每个数字的出现次数统计好，记 `tails[x]` 是恰好在 `x` 之前结束的链的数目。

现在我们逐一考虑每个数字，如果有一个链恰好在 `x` 之前结束，我们将 `x` 加入此链中。否则，如果我们可以新建立一条链就新建。

我们可以优化额外空间到 $O(1)$，因为我们可以像 *方法 1* 一样统计数字的出现次数，而且我们只需要知道最后 3 个数字的出现次数即可。

```Python []
class Solution(object):
    def isPossible(self, nums):
        count = collections.Counter(nums)
        tails = collections.Counter()
        for x in nums:
            if count[x] == 0:
                continue
            elif tails[x] > 0:
                tails[x] -= 1
                tails[x+1] += 1
            elif count[x+1] > 0 and count[x+2] > 0:
                count[x+1] -= 1
                count[x+2] -= 1
                tails[x+3] += 1
            else:
                return False
            count[x] -= 1
        return True
```

```Java []
class Solution {
    public boolean isPossible(int[] nums) {
        Counter count = new Counter();
        Counter tails = new Counter();
        for (int x: nums) count.add(x, 1);

        for (int x: nums) {
            if (count.get(x) == 0) {
                continue;
            } else if (tails.get(x) > 0) {
                tails.add(x, -1);
                tails.add(x+1, 1);
            } else if (count.get(x+1) > 0 && count.get(x+2) > 0) {
                count.add(x+1, -1);
                count.add(x+2, -1);
                tails.add(x+3, 1);
            } else {
                return false;
            }
            count.add(x, -1);
        }
        return true;
    }
}

class Counter extends HashMap<Integer, Integer> {
    public int get(int k) {
        return containsKey(k) ? super.get(k) : 0;
    }

    public void add(int k, int v) {
        put(k, get(k) + v);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是 `nums` 的长度。我们需要遍历整个数组一次。

* 空间复杂度： $O(N)$，`count` 和 `tail` 的大小为 $N$。
