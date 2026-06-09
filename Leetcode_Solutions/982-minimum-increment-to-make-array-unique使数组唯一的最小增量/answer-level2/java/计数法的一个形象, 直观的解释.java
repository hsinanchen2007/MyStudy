想象每个元素是一个乒乓球, 元素值为其编号.
假设有无限个水桶, 从0开始编号.

每个球放入对应编号的水桶中.
**目标就是使每个水桶最后至多有一个乒乓球.**

前提是只允许将一个球从桶里拿出来并放入右边的桶中.

我们可以从第一个桶起, 如果桶中的球数量大于1, 就将多余的球移动到右边的桶中.
需要移动的次数就是桶中球数减去1.

来到第40001个桶时, 我们需要将这个桶中的**所有多余的球**(假设为n个)放入其后边的桶中.
由于后边的桶中都没有球, 所以只需依次将球放入第40002, 40003, ... 40001 + n个桶中.
分别需要移动1, 2, ... n次. 即(n + 1) * n / 2次;

Java:

```java
public int minIncrementForUnique(int[] A) {
    int[] buckets = new int[40001];
    for (int a: A) {
        ++buckets[a];
    }

    int increments = 0;
    for (int a = 0; a < 40000; a++) {
        if (buckets[a] > 1) {
            increments += (buckets[a] - 1);
            buckets[a + 1] += (buckets[a] - 1);
        }
    }
    increments += (buckets[40000] - 1) * buckets[40000] / 2;
    
    return increments;
}
```
