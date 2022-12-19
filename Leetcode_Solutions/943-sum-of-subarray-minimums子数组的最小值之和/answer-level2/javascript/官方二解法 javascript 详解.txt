### 单调栈

大家好，我是 17

官方给出了两个解法，都是用的单调栈。所以首先需要讲下单调栈的作用。

单调栈是为了找寻数组中离 `A[i]` 最近的大于A[i],或小于`A[i]` 的` A[j]` ,或 `A[k]` 的 ,其中 `j<i ， k>i `
比如 `[1,3,2]`,找寻 `2` 的左面第一个比较它小的数

先说下 A[i] 左面最小值的情况，右面类似
如果不用单调栈的话，需要从 2 开始向左一个一个的找。这样当每个数都需要这样查找的话，需要 O(n2) 时间
单调栈是一次性把 A[i] 左面的 最小值求出并记录下来，用的时候可以直接用。时间 是 O(n)

构造左栈，初始 stack=[],记录左面第一个最小值索引的数组 left=[]

1. 数字 1， 栈为空，当前没有比 1小的数，比1小的数的索引记为 -1，` left=[-1]`  ，1 直接入栈 ` stack=[1] `
1. 数字 3 , 栈不为空，3 大于 1，比3小的左面第一个数就是 1，索引是0 ，`left=[-1,0]` , 3 直接入栈 `stack=[1,3]`
2. 数字 2， 栈不为空，2 大于 3，为了找比2小的数，把 3 弹出，比 1 大，left=`[-1,0,0]`,2 入栈` stack=[1,2]`

构造右栈的时候，注意是从后向前构造，其它都一样。

### 方法一解题思路

既然是求子数组中最小值的和，就是求 以 A[i] 作为最小数能构成的数组有多少个。

比如 ` [2,4,1,2]` ,以1 为最小数。能构成的数组数为 (2+1)*(1+1) ，2 表示 1 左面有两个比它大的数，1 表示 1 右面有一个比它大的数。

用单调栈求出 A[i] 对应的左右最近比 A[i] 小的数，记索引为 prev,next，A[i] 为最小数能形成的数组为

```javascript
(i-prev[i])*(next[i]-i)
```

这里为什么没有加 1 了呢，因为 `prev[i]`已经是比` A[i]` 小的数了，能和 A[i] 形成数组的都是比` A[i]` 大的数。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var sumSubarrayMins = function (A) {
  const mod = 1e9 + 7
  let stack = []
  let prev = []
  for (let i = 0; i < A.length; i++) {
    //这里的 A[stack[stack.length - 1]] >= A[i] 大于等于了，后面的就只能是大于了，不然会重复计算相等的值
    while (stack.length !== 0 && A[stack[stack.length - 1]] >= A[i]) stack.pop()
    prev[i] = stack.length ? stack[stack.length - 1] : -1
    stack.push(i)
  }
  stack = []
  let next = []
  for (let i = A.length - 1; i >= 0; i--) {
    while (stack.length !== 0 && A[stack[stack.length - 1]] > A[i]) stack.pop()
    next[i] = stack.length ? stack[stack.length - 1] : A.length
    stack.push(i)
  }

  let sum = 0
  for (let i = 0; i < A.length; i++) {
    sum += (i - prev[i]) * (next[i] - i) * A[i]
    sum %= mod
  }
  return sum
};

```

### 方法二解题思路

方法二和方法一的整体思想是一样的，但是处理比较巧妙，是用的一次遍历。思想不是左右看，是向前看，就是每加进来一个元素，会对整体造成怎样的影响。

比如 当前最小值是` A[i] ` 能形成的最小数组数集合是 `group=[[],[]...]`,数量是 count ，后面来的 `A[j]>A[i] `那么 `A[j]`与 group 中每个数组都能形成新的子数组，所以 加入 `A[j]` 后，还是`A[i]`为最小值，没变，`以A[i]`为底的最小子数组的 和为 `count *= 2`,也就是加倍。

再说下`A[j]<A[i]` 的情况，`A[j]`会形成新的最小值，`A[j]`会接管`A[i]`的地盘，所以把` A[i]`弹出，`A[j]`的 ` count` 等于`A[i]`的`count`

最后说下累积的情况。想象一下如果把数组的值连成线的话，会是一个高低起伏的状态。如果  `A[p]>A[i]>A[q]  i>p && i<q`，那么`A[i]`就是谷底值，两边的都它大。加入`A[j]`后，可能前面有多个这样的谷底值，`A[j]`对每个谷底值能形成的子数组都是有贡献的。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var sumSubarrayMins = function (A) {
  const mod = 1e9 + 7
  let stack = []
  let tmp = 0, allCount = 0, sum = 0
  for (let i = 0; i < A.length; i++) {
    allCount = 1
    while (stack.length !== 0 && stack[stack.length - 1].val > A[i]) {
      let { count, val } = stack.pop()
      tmp -= count * val
      allCount += count
    }

    tmp += allCount * A[i]
    stack.push({
      val: A[i],
      count:allCount
    })

    sum += tmp
    
    sum%=mod
  }
  return sum
};
```

### 总结

单调栈是一个通用技巧，可以解决好多问题。