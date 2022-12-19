### 解题思路 - 最小堆
由于丑数的质因数只有2，3,5，因此我们可以从第一个丑数1开始去乘以2,3,5，得到一批丑数。

在这里选一个最小的数字作为下一个丑数，然后再用它去乘以2,3,5，得到一批新的候选丑数，

这样不断操作下去，直到找到第n个丑数。

这个过程中维护了一个数字集合，并且很方便的取出这些数字的最小值，

于是可以用一个最小堆来维护这些数字，我们需要n次的循环来找到第n个丑数，

并且每次往最小堆中插入数字，时间复杂度是O(logn).因此总的时间复杂度是O(n*logn).

使用了一个辅助的最小堆，因此空间复杂度是O(n)

### 代码

```golang
// Time: O(n*log(n)), Space: O(n)
func nthUglyNumber(n int) int {
  uglyNum := -1 // 首先把丑数初始化为一个不合法的值-1
  var h IntHeap // 然后定义最小堆
  heap.Init(&h)
  heap.Push(&h, 1) // 并且把第一个丑数1，加入到最小堆中
  for n > 0 {      // 当n大于0时执行以下操作
    for h[0] == uglyNum { // 检查堆顶元素是否等于上一个丑数
      heap.Pop(&h) // 如果是就不断丢弃
    } // 这一步的作用是去重
    // 直到不重复就取出堆顶元素,把它作为新的丑数
    uglyNum = heap.Pop(&h).(int)
    // 接着把当前丑数乘以2,3,5后的候选值，加入最小堆中
    // 由于候选集合增长非常快，有可能在还没有求出第n个丑数时，
    // 就已经超出了整数最大值，于是这里使用整数的最大值进行约束
    if 2*uglyNum <= math.MaxInt32 { heap.Push(&h, 2*uglyNum) }
    if 3*uglyNum <= math.MaxInt32 { heap.Push(&h, 3*uglyNum) }
    if 5*uglyNum <= math.MaxInt32 { heap.Push(&h, 5*uglyNum) }
    n-- // 计算出一个新的丑数后n要减一
  }
  // 循环结束后返回记录着的丑数即可
  return uglyNum
}

type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
  res := (*h)[len(*h)-1]
  *h = (*h)[:len(*h)-1]
  return res
}
```

### 解题思路 - 动态规划

上面的方法每次选出一个丑数，都会往候选集合中加入3个数字，所以产生了大的多的候选集合，

我们还是使用这种思想，但是换另一个视角来看这个问题，看如何把候选集合变小。

基本思想不变， 

每一个新的丑数，一定是前面出现过的丑数再乘以2或3或5得到，

- 定义三个游标，指向用于乘以2,3,5的丑数
- 用p2,p3,p5指向的丑数,分别去乘以2,3,5,然后去计算这3个数字的最小值
- 这个最小值就是第i个丑数
- 接着把等于最小值丑数的候选者游标+1,这样才能产生更大的候选丑数
- 循环结束后返回下标为n-1的值即可

但这一次我们不去候选集合中找，而是直接在前面已经出现的丑数中找，

这种方法把每次候选集合都降低到了3个数字，只需要O(1)的时间，就能得到这一轮的丑数，

我们还是需要n次来求得第n个丑数，所以总的时间复杂度是O(n)。

需要一个辅助数组存储求解过程中所有丑数，因此空间复杂度是O(n)
### 代码

```golang
//动态规划方法 Time: O(n), Space: O(n)
func nthUglyNumber(n int) int {
  if n <= 0 { // 非法输入
    return -1 // 返回-1
  }
  uglyNums := make([]int, n) // 定义丑数数组
  uglyNums[0] = 1            // 并且初始化第0个丑数为1
  p2, p3, p5 := 0, 0, 0      //定义三个游标，指向用于乘以2,3,5的丑数
  for i := 1; i < n; i++ {   // i从1开始遍历到n-1一个个计算丑数
    // 我们用p2,p3,p5指向的丑数,分别去乘以2,3,5,然后去计算这3个数字的最小值
    m := min(uglyNums[p2]*2, uglyNums[p3]*3, uglyNums[p5]*5)
    // 这个最小值就是第i个丑数
    uglyNums[i] = m
    // 接着把等于最小值丑数的候选者游标+1,这样才能产生更大的候选丑数
    if m == uglyNums[p2]*2 { p2++ }
    if m == uglyNums[p3]*3 { p3++ }
    if m == uglyNums[p5]*5 { p5++ }
  }
  // 循环结束后返回下标为n-1的值即可
  return uglyNums[n-1]
}

// 辅助函数 求三个整数的最小值
func min(a, b, c int) int {
  return minm(a, minm(b, c))
}

func minm(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```