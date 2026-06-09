### 解题思路

大家好，我是 17 

由于这道题的严格限制，才保证可以用快慢指针的方法。

1. 有重复数，这是最重要的保证，有环的条件
2. n+1个整数（必须是整数），且数字都在 1 到 n 之间

快慢指针本来是处理链表中的有环问题的。借助链表的方式来说明一下，链表的链比较直接，好理解。

1. 初始两指针，slow,fast 指向第一个元素
2. slow走一步，fast走两步，因为有环，所以一定相遇，相遇后 break。
3. 设一个指针 p, 指向第一个元素，p走一步，slow走一步，最后相遇的位置就是环的入口。

在环中相遇的时候，slow走了 n 步,fast 走了2n 步，设起点到 环的入口距离是 m,那么slow在环中走的距离是 n-m 步
起点的指针 走 m 步到达环的入口，环中的 slow走 m  步到达环的入口和 p 相遇。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function (nums) {
  nums.sort((a, b) => a - b)
  let low = 0, high = nums.length - 1
  while (low < high) {

    let mid = low + ((high - low) >> 1)
    if (nums[mid] === nums[mid + 1] || nums[mid] === nums[mid - 1]) return nums[mid]
    if (nums[mid] < mid + 1) {
      high = mid
    }
    else {
      low = mid + 1
    }
  }
};
```

因为本题的特殊性，所以还可以用标记法，来复用空间。
因为有 n个数，这n这个数可以对应数组的 1-n+1的位置，而数组恰好有 n+1个位置。每次到出一个数，看看这个数对应的位置是不是有人了，没人设为负数，表示把这个位置占了。下次再有人想占这个位置就知道有重复数了。

最后需要还原现场。因为题目要求的不能改变原数组的嘛。

不能改变的意思是执行完后原数组没变就行，执行的时候变不变外界是不知道的，因为对外界而言程序内部是黑盒，外界只关心结果，而不关心过程

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function (nums) {
  let result = undefined
  for (let i = 0; i < nums.length; i++) {
    let flagIndex = Math.abs(nums[i])
    if (nums[flagIndex] < 0) {
      result = flagIndex
      break
    }
    nums[flagIndex] = -nums[flagIndex]
  }
 //恢复
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] < 0) {
      nums[i] = -nums[i]
    }
  }
  return result
};
```

还有用哈希表的办法，这个办法就容易想到，也最简单。平时一般用这个就行。


