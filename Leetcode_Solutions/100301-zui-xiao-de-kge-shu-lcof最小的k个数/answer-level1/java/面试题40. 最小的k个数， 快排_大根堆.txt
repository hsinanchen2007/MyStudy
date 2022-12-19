### 解题思路
#### 快排
区间`[l, r]`, 按照`pivot` 的值分割成两部分。$values_{i-1}=pivot$
 * $[values_{l}, values_{i-1}]$ 都小于等于`pivot`，
 * $[values_{i}, values_{r}]$ 都大于`pivot`。

在区间`[l, r]`里的查找过程：`[l, i-2], [i-1], [i, r]`
* 如果`i-1 = k`: 已经成功找到答案了，答案为`[l, i-1]`。
* 如果`i-1 > k`: 在`[l, i-2]`里继续找答案，丢弃`[i-1, r]`（都大于第k大元素）这一半。
* 如果`i < k`: 在`[i, r]`里继续找答案，`[l, i-1]`这部分已经找到答案了（都小于第k大元素）。

时间复杂度： $O(N)$ 
空间复杂度： $O(logN)$ (系统调用堆栈空间)

#### 大根堆
维护一个大小为`k`的堆，**堆顶为最大元素**。每当新遇到一个元素：
 * 如果堆的大小小于`k`，直接加入堆。
 * 否则跟堆顶的元素做比较，如果**小于**堆顶的元素，那么替换掉它。

时间复杂度： $O(NlogK)$
空间复杂度： $O(K)$

### 代码（快排）

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0) return new int[0];
        if (arr.length < k) return arr;
        
        topK(arr, 0, arr.length-1, k);
        int[] res = new int[k];
        for (int i = 0; i < k; ++i) {
            res[i] = arr[i];
        }
        return res;
    }

    private void exchange(int[] values, int a, int b) {
        int tmp = values[a];
        values[a] = values[b];
        values[b] = tmp;
    }

    public long topK(int[] values, int l, int r, int k) {
        long compareTime = r - l;
        int pivot = values[l];

        int i = l + 1;
        int j = l + 1;
        for (; j <= r; ++j) {
            if (values[j] <= pivot) {
                exchange(values, i, j);
                ++i;
            }
        }
        exchange(values, l, i - 1);

        if (i-1 > k) {
            compareTime += topK(values, l, i-2, k);
        } else if (i < k) {
            compareTime += topK(values, i, r, k);
        }

        return compareTime;
    }
}
```

### 代码（大根堆）

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0) return new int[0];
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(k ,new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        for (int num: arr) {
            if (pq.size() < k) pq.add(num);
            else if (pq.peek() > num) {
                pq.poll();
                pq.add(num);
            }
        }
        int[] res = new int[pq.size()];
        int i = 0;
        for (Iterator<Integer> it = pq.iterator(); it.hasNext();) {
            res[i++] = it.next();
        }
        return res;
    }
}
```