题目中要求计算重叠区间，而重叠的区间一定是连续的区间。所以本质上这道题要做的是排序，然后再进行连续区间的合并，最后输入合并结果。

## 1、直接编码插入排序

对输入矩阵直接进行插入排序，每个数组都比较左边界的大小，然后按序插入到动态链表中。时间复杂度是O(N^2). 

新建一个链表，将排序完成后的数组依次转接到新链表中，每次判断新链表最后一个数组的右边界，和第n个数组的左边界的大小。比较后进行合并，或者插入到新链表中。时间复杂度O(N).

最后，将整个合并后的链表重新转换为矩阵。时间复杂度O(N).



168 / 169 个通过测试用例，超出时间限制。

代码：

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        // 对输入矩阵直接进行插入排序
        LinkedList<int[]> inter = new LinkedList();
        for (int[] ele: intervals) {
            if (inter.isEmpty() || inter.getLast()[0]<=ele[0]){
                inter.add(ele);
            }else{
                for (int i = 0; i < inter.size(); i++) {
                    if (inter.get(i)[0]>ele[0]){
                        inter.add(i,ele);
                        break;
                    }
                }
            }

        }
        
        // 转接排序后的链表并同步合并区间
        LinkedList<int[]> result = new LinkedList<>();
        for (int i=0; i<inter.size(); i++){
            if (result.isEmpty() || result.getLast()[1]<inter.get(i)[0]) {
                result.add(inter.get(i));
            }else {
                result.getLast() [1] = Math.max(result.getLast()[1],inter.get(i)[1]);
            }
        }
        
        // 将整个合并后的链表重新转换为矩阵
        int i=0;
        int[][] resultTransfer = new int[result.size()][2];
        for (int[] mergedInterval : result) {
            resultTransfer[i][0] = mergedInterval[0];
            resultTransfer[i][1] = mergedInterval[1];
            i++;
        }
        return resultTransfer;
    }
}
```



## 2、使用sort的比较器

和直接编码相比，自定义了比较器Comparator，比较的同样是每个数组区间的左边界。比较后根据comparator的定义返回-1、0、1, 依次表示数组a 小于、等于、大于b.

新建一个链表，将矩阵中的数组转移到动态链表中。时间复杂度O(N).

然后使用linkedlist的sort函数方法进行排序，并使用自定义的comparator比较器。

新建一个链表，将排序完成后的数组依次转接到新链表中，每次判断新链表最后一个数组的右边界，和第n个数组的左边界的大小。比较后进行合并，或者插入到新链表中。时间复杂度O(N).

最后，将整个合并后的链表重新转换为矩阵。时间复杂度O(N).



这里已经可以通过所有测试用例。可以看到，主要的区别就是使用了sort比较器。sort比较器做到了复杂度O(NlogN)，所以优化了时间。

代码：

```java
class Solution {
    /**
     * Compares its two arguments for order.  Returns a negative integer,
     * zero, or a positive integer as the first argument is less than, equal
     * to, or greater than the second.<p>
     */
    private class IntervalComparator implements Comparator<int[]> {
        @Override
        public int compare(int[] a, int[] b) {
            return a[0] < b[0] ? -1 : a[0] == b[0] ? 0 : 1;
        }
    }

    public int[][] merge(int[][] intervals) {
        // 将矩阵中的数组转移到动态链表中，然后使用linkedlist的sort函数方法进行排序
        LinkedList<int[]> inter = new LinkedList();
        for (int[] ele: intervals) {
            inter.add(ele);
        }
        inter.sort(new IntervalComparator());

        // 转接排序后的链表并同步合并区间
        LinkedList<int[]> result = new LinkedList<>();
        for (int i=0; i<inter.size(); i++){
            if (result.isEmpty() || result.getLast()[1]<inter.get(i)[0]) {
                result.add(inter.get(i));
            }else {
                result.getLast() [1] = Math.max(result.getLast()[1],inter.get(i)[1]);
            }
        }
        
        // 将整个合并后的链表重新转换为矩阵
        int i=0;
        int[][] resultTransfer = new int[result.size()][2];
        for (int[] mergedInterval : result) {
            resultTransfer[i][0] = mergedInterval[0];
            resultTransfer[i][1] = mergedInterval[1];
            i++;
        }
        return resultTransfer;
    }
}
```



## 3、sort比较器源码浅析

### 3.1 List的sort源码

先看看List的sort比较方法，要求的输入是自定义的比较器和this指向的list. 这里将list转为对象数组，然后使用Arrays.sort去排序，最后使用Iterator重新改变list.

```java
@SuppressWarnings({"unchecked", "rawtypes"})
default void sort(Comparator<? super E> c) {
    Object[] a = this.toArray();
    Arrays.sort(a, (Comparator) c);
    ListIterator<E> i = this.listIterator();
    for (Object e : a) {
        i.next();
        i.set((E) e);
    }
}
```

### 3.2 调用Arrays的sort方法

Arrays里的sort方法，如果没有比较器会使用默认的升序排序。如果有比较器，除了old version版本要求，则会使用TimSort.

```java
public static <T> void sort(T[] a, Comparator<? super T> c) {
    if (c == null) {
        sort(a);
    } else {
        if (LegacyMergeSort.userRequested)
            legacyMergeSort(a, c);
        else
            TimSort.sort(a, 0, a.length, c, null, 0, 0);
    }
}
```

### 3.3 Timsort函数的三个部分

Timsort是方法实现的核心，总的来说分为三个部分：

1）对象个数小于2个，不再需要排序；

2）对象个数小于32个，使用二分排序；

3）对象个数大于等于32个，使用归并排序+二分排序

```java
static <T> void sort(T[] a, int lo, int hi, Comparator<? super T> c,
                         T[] work, int workBase, int workLen) {
    assert c != null && a != null && lo >= 0 && lo <= hi && hi <= a.length;

    int nRemaining  = hi - lo;
    // 如果对象个数小于2个，代表不再需要排序
    if (nRemaining < 2)
        return;  // Arrays of size 0 and 1 are always sorted

    // If array is small, do a "mini-TimSort" with no merges
    // 翻译：这里MIN_MERGE定义对象个数小于32，则使用二分排序
    if (nRemaining < MIN_MERGE) {
        // 获得最长的递增序列
        int initRunLen = countRunAndMakeAscending(a, lo, hi, c);
        binarySort(a, lo, hi, lo + initRunLen, c);
        return;
    }

    /**
         * March over the array once, left to right, finding natural runs,
         * extending short natural runs to minRun elements, and merging runs
         * to maintain stack invariant.
         */
    // 对象个数大于等于32个，以minRun为准将序列切割，然后归并排序
    TimSort<T> ts = new TimSort<>(a, c, work, workBase, workLen);
    int minRun = minRunLength(nRemaining);
    // 循环将序列切割，使用二分排序，最后归并排序，有效处理大数据量
    do {
        // Identify next run
        int runLen = countRunAndMakeAscending(a, lo, hi, c);

        // If run is short, extend to min(minRun, nRemaining)
        if (runLen < minRun) {
            int force = nRemaining <= minRun ? nRemaining : minRun;
            binarySort(a, lo, lo + force, lo + runLen, c);
            runLen = force;
        }

        // Push run onto pending-run stack, and maybe merge
        ts.pushRun(lo, runLen);
        ts.mergeCollapse();

        // Advance to find next run
        lo += runLen;
        nRemaining -= runLen;
    } while (nRemaining != 0);

    // Merge all remaining runs to complete sort
    assert lo == hi;
    ts.mergeForceCollapse();
    assert ts.stackSize == 1;
}
```

### 3.4 主要的子方法二分排序

```java
@SuppressWarnings("fallthrough")
private static <T> void binarySort(T[] a, int lo, int hi, int start,
                                   Comparator<? super T> c) {
    assert lo <= start && start <= hi;
    if (start == lo)
        start++;
    for ( ; start < hi; start++) {
        T pivot = a[start];

        // Set left (and right) to the index where a[start] (pivot) belongs
        int left = lo;
        int right = start;
        assert left <= right;
        /*
             * Invariants:
             *   pivot >= all in [lo, left).
             *   pivot <  all in [right, start).
             */
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (c.compare(pivot, a[mid]) < 0)
                right = mid;
            else
                left = mid + 1;
        }
        assert left == right;

        /*
             * The invariants still hold: pivot >= all in [lo, left) and
             * pivot < all in [left, start), so pivot belongs at left.  Note
             * that if there are elements equal to pivot, left points to the
             * first slot after them -- that's why this sort is stable.
             * Slide elements over to make room for pivot.
             */
        int n = start - left;  // The number of elements to move
        // Switch is just an optimization for arraycopy in default case
        switch (n) {
            case 2:  a[left + 2] = a[left + 1];
            case 1:  a[left + 1] = a[left];
                break;
            default: System.arraycopy(a, left, a, left + 1, n);
        }
        a[left] = pivot;
    }
}
```

