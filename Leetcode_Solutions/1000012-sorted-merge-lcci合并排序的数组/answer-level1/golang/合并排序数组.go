### 解题思路
1. 找到来自B数组中元素在A数组中的插入位置`position`
2. 腾出`position`的空间，将A数组中位置为`position`至A数组末尾`tail`的子数组往后平移一格。
3. 填入元素后，再一次填入B数组中的所有元素完成。

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    var tail = m - 1
    // before 用于记录填入B数组后的位置，避免算法总是从头开始比较，查找插入位置position
    var before = 0
    for i := 0; i < n; i++ {
        // 找到来自B数组中元素在A数组中的插入位置
        var position = before
        for j := before; j <= tail ; j++ {
            if A[j] > B[i] {
                break
            }
            position++
            before = position
        }
        // 子数组向后平移一格
        for h := tail+1 ; h > position; h-- {
            A[h] = A[h-1]
        }
        // 填入元素
        A[position] = B[i]
        tail++
    }
}
```