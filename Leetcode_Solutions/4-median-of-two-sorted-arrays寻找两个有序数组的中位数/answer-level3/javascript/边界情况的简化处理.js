## 算法描述

这个算法在其它很多题解里已经提过了，这里再啰嗦一遍：

首先我们在第一个数组里选一个位置进行切分，共有`n + 1`种切法，第`i`种切法表示左边有`i`个元素，对应的，切割线左边的第一个元素是`nums1[i - 1]`，右边第一个是`nums1[i]`。

当我们确定了第一个数组的切割点之后，就可以确定数组二的一个唯一的切割点，以保证切割之后左右数组的总数相等或中位数位于左边。令`i`等于第一个数组的切割点，则可得到第二个数组的切割点`j = Math.floor((m + n + 1) / 2)`。至于为什么这么算举几个例子就可以验证了，这里不做证明。

另外为了保证对于每个给定的i，都能得到有效的j，我们必须保证 n <= m。
为什么呢？举个例子，如果第一个数组个数较多，而我们切割之后的子数组个数比第二个数组还大，那么在第二个数组里是找不到有效的切割点的。
所以一开始需要比较下两个数组的大小关系进行处理。

确定i和j的值之后接下来就要判断是否是我们要的位置了。
我们的目的是切割后的两个左数组里的任意值都不大于两个右数组里的任意值，即

```javascript
nums1[i - 1] <= nums2[j] && nums1[i] >= nums2[j - 1]
```

如果不符合条件，我们继续判断i是过大或是过小，然后使用二分法继续更新直到条件符合为止。

找到符合条件的i后，就可以找到对应的中位数了。
如果总数为奇数，那么中位数就是左边最大的值`max(nums1[i - 1], nums2[j - 1])`。
如果是偶数，就是左边最大值与右边最小值的平均`(maxLeft + minRight) / 2`。

## 边界情况

麻烦的地方就在于边界情况的处理，记的i的取值范围是`[0, m]`，所以`i - 1`和`i`都有可能超出数组的边界，`j`同理。
这样我们不得不写很多判断代码来处理越界的情况。

我们可以考虑在数组开头与末尾插入正负无穷大作为哨兵元素，同时调整i，j的取值范围来避免越界的判断。
具体到实现，我们可以借助js的代理对象对两个数组进行代理，当下标过小时返回-Infinity，过大时返回Infinity以达到同样的目的。
这样即不用手动插入哨兵，也避免了繁琐的越界判断。

代码如下：

```javascript
var findMedianSortedArrays = function(nums1, nums2) {
  const m = nums1.length
  const n = nums2.length
  // 调换长度
  if (m > n) return findMedianSortedArrays(nums2, nums1)
  // 代理nums1与nums2
  const n1 = makeProxy(nums1)
  const n2 = makeProxy(nums2)
  
  let i, j
  let left = 0, right = m, half = ~~((m + n + 1) / 2)
  // 寻找正确的切割点
  while(left <= right) {
    i = ~~((left + right) / 2)
    j = half - i
    if (n1[i - 1] > n2[j]) right = i - 1
    else if (n1[i] < n2[j - 1]) left = i + 1
    else break
  }
  // 找到切割点后，分别找出左右极值
  const maxLeft = Math.max(n1[i - 1], n2[j - 1])
  const minRight = Math.min(n1[i], n2[j])
  // 根据奇偶性返回对应的中位数
  return ((m + n) % 2 === 0) ? (maxLeft + minRight) / 2 : maxLeft
};

function makeProxy (target) {
  return new Proxy(target, {
    get: (obj, attr) => {
      if (+attr < 0) return -Infinity
      else if (+attr >= target.length) return Infinity
      else return obj[attr]
    }
  })
}
```

