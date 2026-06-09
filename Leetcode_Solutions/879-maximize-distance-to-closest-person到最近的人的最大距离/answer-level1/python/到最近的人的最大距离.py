#### 方法一：计算座位到最近的人的最大距离【通过】

**思路**

令 `left[i]` 为座位 `i` 到坐在 `i` 左边的人的最近距离。同理 `right[i]` 为座位 `i` 到坐在 `i` 右边的人的最近距离。那么该座位到最近的人的距离为 `min(left[i], right[i])`。

**算法**

如果 `i` 左边的位置是空的，那么 `left[i] = left[i - 1] + 1`；否则 `left[i] = 0`。`right[i]` 的计算方法类似。

```java [solution1-Java]
class Solution {
    public int maxDistToClosest(int[] seats) {
        int N = seats.length;
        int[] left = new int[N], right = new int[N];
        Arrays.fill(left, N);
        Arrays.fill(right, N);

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) left[i] = 0;
            else if (i > 0) left[i] = left[i-1] + 1;
        }

        for (int i = N-1; i >= 0; --i) {
            if (seats[i] == 1) right[i] = 0;
            else if (i < N-1) right[i] = right[i+1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < N; ++i)
            if (seats[i] == 0)
                ans = Math.max(ans, Math.min(left[i], right[i]));
        return ans;
    }
}

```

```python [solution1-Python]
class Solution(object):
    def maxDistToClosest(self, seats):
        N = len(seats)
        left, right = [N] * N, [N] * N

        for i in xrange(N):
            if seats[i] == 1: left[i] = 0
            elif i > 0: left[i] = left[i-1] + 1

        for i in xrange(N-1, -1, -1):
            if seats[i] == 1: right[i] = 0
            elif i < N-1: right[i] = right[i+1] + 1

        return max(min(left[i], right[i])
                   for i, seat in enumerate(seats) if not seat)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `seats` 的长度。

* 空间复杂度：$O(N)$，存储 `left` 和 `right` 的空间。


#### 方法二：双指针【通过】

**思路**

遍历所有座位 `seats`，找出每个空位左边最近的人和右边最近的人，更新当前空位到最近的人的距离。

**算法**

使用 `prev` 记录 `i` 最左边第一个有人的位置，`future` 记录 `i` 最右边第一个有人的位置。

座位 `i` 到最近的人的距离为 `min(i - prev, future - i)`。另外有一种特殊情况，如果座位 `i` 左边没有人，则认为到左边第一个人的距离是无限大，右边同理。

```java [solution2-Java]
class Solution {
    public int maxDistToClosest(int[] seats) {
        int N = seats.length;
        int prev = -1, future = 0;
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while (future < N && seats[future] == 0 || future < i)
                    future++;

                int left = prev == -1 ? N : i - prev;
                int right = future == N ? N : future - i;
                ans = Math.max(ans, Math.min(left, right));
            }
        }

        return ans;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def maxDistToClosest(self, seats):
        people = (i for i, seat in enumerate(seats) if seat)
        prev, future = None, next(people)

        ans = 0
        for i, seat in enumerate(seats):
            if seat:
                prev = i
            else:
                while future is not None and future < i:
                    future = next(people, None)

                left = float('inf') if prev is None else i - prev
                right = float('inf') if future is None else future - i
                ans = max(ans, min(left, right))

        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `seats` 的长度。

* 空间复杂度：$O(1)$。


#### 方法三：按零分组【通过】

**思路**

如果两人之间有连续 `K` 个空座位，那么其中存在至少一个座位到两边最近的人的距离为 `(K+1) / 2`。

**算法**

假设两个人之间有 `K` 个空座位，则存在座位到最近的人的距离为 `(K+1) / 2`。

对于边缘的座位，它们的一侧没有人，那么认为它们到该侧最近的人的距离为 `K`。

```java [solution3-Java]
class Solution {
    public int maxDistToClosest(int[] seats) {
        int N = seats.length;
        int K = 0; //current longest group of empty seats
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                K = 0;
            } else {
                K++;
                ans = Math.max(ans, (K + 1) / 2);
            }
        }

        for (int i = 0; i < N; ++i)  if (seats[i] == 1) {
            ans = Math.max(ans, i);
            break;
        }

        for (int i = N-1; i >= 0; --i)  if (seats[i] == 1) {
            ans = Math.max(ans, N - 1 - i);
            break;
        }

        return ans;
    }
}
```

```python [solution3-Python]
class Solution(object):
    def maxDistToClosest(self, seats):
        ans = 0
        for seat, group in itertools.groupby(seats):
            if not seat:
                K = len(list(group))
                ans = max(ans, (K+1)/2)

        return max(ans, seats.index(1), seats[::-1].index(1))
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `seats` 的长度。

* 空间复杂度：$O(1)$。在 Python中 `seats[::-1]` 的空间为 $O(N)$，但它可以被省略。