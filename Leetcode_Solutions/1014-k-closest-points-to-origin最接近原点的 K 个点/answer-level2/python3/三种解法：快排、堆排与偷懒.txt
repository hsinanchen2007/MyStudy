本质是排序。按照欧几里得距离从小到大对 `points` 进行升序排序，然后取出前 K 个点即可。

其实就是三个步骤：

1. 计算距离
2. 排序
3. 取 K 个

### 解一：偷懒大法

直接用系统提供的排序函数进行排序。

```python
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        distance = []
        res = []
        for i in range(len(points)):
            point = points[i]
            dis = point[0]**2 + point[1]**2
            distance.append([i, dis])
            
        distance.sort(key=lambda x:x[1])
        
        for i in range(K):
            res.append(points[distance[i][0]])
        return res
```

上面写的比较啰嗦，可以用列表生成式简化一下：

```python
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        points.sort(key=lambda x: x[0]**2 + x[1] ** 2)
        return points[:K]
```

### 解二：快速排序

这里的快速排序无需使整个数组有序，只需要筛选出最小的 K 个值即可。

假设第一次排序后，哨兵值 `pivot` 将原数组分为两个部分：

1. 左侧部分，元素值均小于 `pivot`，假设下标范围是 `[begin, i - 1]`，长度为 `left_length`
2. 右侧部分，元素值均大于或等于 `pivot`，假设下标范围是 `[i + 1, end]`，长度为 `right_length`

此时：

- 如果 `left_length >= K`，最小的 `K` 个值均在左侧，因此下轮递归只需对左侧部分进行排序
- 如果 `left_length < K`，我们已经获得了 `left_length` 个最小值，因此下轮递归只需对右侧部分进行排序

```python []
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        # 计算欧几里得距离
        distance = lambda i: points[i][0] ** 2 + points[i][1] ** 2
        
        def work(i, j, K):
            if i > j:
                return
            # 记录初始值
            oi, oj = i, j
            # 取最左边为哨兵值
            pivot = distance(oi)
            while i != j:
                while i < j and distance(j) >= pivot:
                    j -= 1
                while i < j and distance(i) <= pivot:
                    i += 1
                if i < j:
                    # 交换值
                    points[i], points[j] = points[j], points[i] 
                
            # 交换哨兵
            points[i], points[oi] = points[oi], points[i]
            
            # 递归
            if K <= i - oi + 1:
                # 左半边排序
                work(oi, i - 1, K)
            else:
                # 右半边排序
                work(i + 1, oj, K - (i - oi + 1))
                
        work(0, len(points) - 1, K)
        return points[:K]
```
```java []
class Solution {
     public int[][] kClosest(int[][] points, int K) {
        int start = 0;
        int end = points.length - 1;
        while (start < end) {
            # 计算欧几里得距离
            int index = patition(points, start, end);
            if (index == K) {
                break;
            } else if (index < K) {
                start = index + 1;
            } else {
                end = index - 1;
            }
        }

        return Arrays.copyOf(points, K);
    }

    private int patition(int[][] points, int start, int end) {
        int i = start;
        int j = end + 1;
        int mid = distance(points[i][0], points[i][1]);
        while (true) {
            while (distance(points[++i][0], points[i][1]) < mid && i < end);
            while (distance(points[--j][0], points[j][1]) > mid && j > start);
            if (i >= j) {
                break;
            }
            swap(points, i, j);
        }
        swap(points, start, j);
        return j;
    }

    private int distance(int a, int b) {
        return a * a + b * b;
    }

    private void swap(int[][] points, int a, int b) {
        int[] temp = points[a];
        points[a] = points[b];
        points[b] = temp;
    }
}
```
```php []
class Solution {

    /**
     * @param Integer[][] $points
     * @param Integer $K
     * @return Integer[][]
     */
    function kClosest($points, $K) {
        $length = count($points);
        $this->quickSelect($points, 0, $length - 1, $K);
        return array_slice($points, 0, $K);
    }
    
    // 快速选择
    function quickSelect(&$points, $i, $j, $k) {
        
        // 递归结束条件
        if ($i > $j) {
            return;
        }
        
        $begin = $i;
        $end = $j;
        // 哨兵
        $pivot = $this->getDistance($points, $begin);
        
        while ($i != $j) {
            while ($i < $j && $this->getDistance($points, $j) >= $pivot) {
                $j--;
            }
            while ($i < $j && $this->getDistance($points, $i) <= $pivot) {
                $i++;
            }
            if ($i < $j) {
                // 交换
                $tmp = $points[$i];
                $points[$i] = $points[$j];
                $points[$j] = $tmp;
            }
        }
        
        // 交换哨兵
        $tmp = $points[$begin];
        $points[$begin] = $points[$i];
        $points[$i] = $tmp;
        
        // 递归
        if ($i - $begin + 1 >= $k) {
            $this->quickSelect($points, $begin, $i - 1, $k);
        } else {
            $this->quickSelect($points, $i + 1, $end, $k - ($i - $begin + 1));
        }
    }
    
    // 计算欧几里得距离
    function getDistance($points, $x) {
        return $points[$x][0]*$points[$x][0] + $points[$x][1] * $points[$x][1];
    }
}
```


### 解三：堆排序

这个问题的本质其实就是对于点到原点的距离，求 Top K 元素。那么，除了排序的方法，以及快速排序以外，还可以利用 **堆** 来得到 Top K 的元素。

```java []
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        // 在 `Java` 里面，可以利用优先队列：PriorityQueue 来处理，其内部实现是堆。
        Queue<int[]> priorityQueue = new PriorityQueue<>(K, (o1, o2) -> o1[0] * o1[0] + o1[1] * o1[1] - o2[0] * o2[0] - o2[1] * o2[1]);
        for (int[] point : points) {
            priorityQueue.add(point);
        }
        int[][] result = new int[K][2];
        for (int i = 0; i < K; i++) {
            result[i] = priorityQueue.poll();
        }
        return result;
    }
}
```
```python []
from heapq import heappush, heappop 

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        queue = []
        distance = lambda x: points[x][0]**2 + points[x][1]**2
        length = len(points)
        for i in range(length):
            heappush(queue, (distance(i), points[i]))
        res = []
        for i in range(K):
            res.append(heappop(queue)[1])
        return res
```

----

Ps：本题 Java 解法来自 [@csming1995](/u/csming1995/)