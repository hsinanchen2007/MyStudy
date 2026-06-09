#### 方法一：排序

**思路**

将所有点到原点的距离进行排序，然后输出距离最近的 K 个点。

**算法**

有两种版本的代码。

使用 JAVA 语言，我们创建一个距离数组，然后排序找到第 K 大的距离，然后我们返回距离小于等于这个第 K 大距离的 K 个点。

使用 Python 语言，我们通过自定义一个排序的键值比较函数来完成排序，然后我们返回列表中的前 K 个点。

```java [RrAfn88e-Java]
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        int N = points.length;
        int[] dists = new int[N];
        for (int i = 0; i < N; ++i)
            dists[i] = dist(points[i]);

        Arrays.sort(dists);
        int distK = dists[K-1];

        int[][] ans = new int[K][2];
        int t = 0;
        for (int i = 0; i < N; ++i)
            if (dist(points[i]) <= distK)
                ans[t++] = points[i];
        return ans;
    }

    public int dist(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
}
```
```python [RrAfn88e-Python]
class Solution(object):
    def kClosest(self, points, K):
        points.sort(key = lambda P: P[0]**2 + P[1]**2)
        return points[:K]
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是给定点的数量。

* 空间复杂度：$O(N)$。





---
#### 方法二：分治法

**思路**

我们想要一个复杂度比 $N \log N$ 更低的算法。  显然，做到这件事情的唯一办法就是利用题目中可以按照任何顺序返回 K 个点的条件，否则的话，必要的排序将会话费我们 $N \log N$ 的时间。

我们随机地选择一个元素 `x = A[i]` 然后将数组分为两部分： 一部分是到原点距离小于 `x` 的，另一部分是到原点距离大于等于 `x` 的。  这个快速选择的过程与快速排序中选择一个关键元素将数组分为两部分的过程类似。

如果我们快速选择一些关键元素，那么每次就可以将问题规模缩减为原来的一半，平均下来时间复杂度就是线性的。

**算法**

我们定义一个函数 `work(i, j, K)`，它的功能是部分排序 `(points[i], points[i+1], ..., points[j])` 使得最小的 `K` 个元素出现在数组的首部，也就是 `(i, i+1, ..., i+K-1)`。

首先，我们从数组中选择一个随机的元素作为关键元素，然后使用这个元素将数组分为上述的两部分。为了能使用线性时间的完成这件事，我们需要两个指针 `i` 与 `j`，然后将它们移动到放错了位置元素的地方，然后交换这些元素。

然后，我们就有了两个部分 `[oi, i]` 与 `[i+1, oj]`，其中 `(oi, oj)` 是原来调用 `work(i, j, K)` 时候 `(i, j)` 的值。假设第一部分有 `10` 个元，第二部分有`15` 个元素。如果 `K = 5` 的话，我们只需要对第一部分调用 `work(oi, i, 5)`。否则的话，假如说 `K = 17`，那么第一部分的 `10` 个元素应该都需要被选择，我们只需要对第二部分调用 `work(i+1, oj, 7)` 就行了。

```java [348Dy3nk-Java]
import java.util.concurrent.ThreadLocalRandom;

class Solution {
    int[][] points;
    public int[][] kClosest(int[][] points, int K) {
        this.points = points;
        work(0, points.length - 1, K);
        return Arrays.copyOfRange(points, 0, K);
    }

    public void work(int i, int j, int K) {
        if (i >= j) return;
        int oi = i, oj = j;
        int pivot = dist(ThreadLocalRandom.current().nextInt(i, j));

        while (i < j) {
            while (i < j && dist(i) < pivot) i++;
            while (i < j && dist(j) > pivot) j--;
            swap(i, j);
        }

        if (K <= i - oi + 1)
            work(oi, i, K);
        else
            work(i+1, oj, K - (i - oi + 1));
    }

    public int dist(int i) {
        return points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }

    public void swap(int i, int j) {
        int t0 = points[i][0], t1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = t0;
        points[j][1] = t1;
    }
}
```
```python [348Dy3nk-Python]
class Solution(object):
    def kClosest(self, points, K):
        dist = lambda i: points[i][0]**2 + points[i][1]**2

        def work(i, j, K):
            if i >= j: return
            oi, oj = i, j
            pivot = dist(random.randint(i, j))
            while i < j:
                while i < j and dist(i) < pivot: i += 1
                while i < j and dist(j) > pivot: j -= 1
                points[i], points[j] = points[j], points[i]

            if K <= i - oi + 1:
                work(oi, i, K)
            else:
                work(i+1, oj, K - (i - oi + 1))

        work(0, len(points) - 1, K)
        return points[:K]
```


**复杂度分析**

* 时间复杂度：$O(N)$ ，这是在*平均情况下* 的时间复杂度， 其中 $N$ 是给定点的数量。

* 空间复杂度：$O(N)$。



