# DP从二维空间到一维再到常数级

## 解法一
### 思路
方法一
* 二维DP
* 状态定义：
    * a[i][0] 表示如果第i天不偷的金额，a[i][1] 如果表示第i天偷的金额
* DP方程：
    * a[i][0] = max(a[i-1][0], a[i-1][1])
    * a[i][1] = a[i-1][0] + nums[i]
* 解：max(a[n-1][0], a[n-1][1])

### 代码
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (!nums || nums.length === 0) return 0

    const n = nums.length
    const a = Array(n).fill(0).map(i => [])
    a[0][0] = 0
    a[0][1] = nums[0]
    for (let i = 1; i < n; i++) {
        a[i][0] = Math.max(a[i-1][0], a[i-1][1])
        a[i][1] = a[i-1][0]+nums[i]
    }

    return Math.max(a[n-1][0], a[n-1][1])
};
```

### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(n)，每个元素有两个状态，所以也是O(2n)

## 解法二
### 思路
* 一维DP
* 状态定义：
    * a[i] 表示前i个房子的最大价值
    * 它可以表示为第i-1房子偷的价值(a[i-1])与当前房子偷的价值(a[i-2]+nums[i])中的最大者
* DP方程：
    * a[i] = max(a[i-1], a[i-2]+nums[i])
* 解：a的最后一个元素值


### 代码
```js
var rob = function(nums) {
    if (!nums || nums.length === 0) return 0
    if (nums.length === 1) return nums[0]

    const a = [nums[0], Math.max(nums[0], nums[1])]
    for (let i = 2; i < nums.length; i++) {
        a[i] = Math.max(a[i-1], a[i-2] + nums[i])
    }

    return a[a.length - 1]
}
```

### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(n)

## 解法三
### 思路
* 最简洁的DP
* 从一维DP中可看出，计算的时候只需要i-1和i-2两个状态，最后是求最大值，且最大值是每次递推后都在i-1或i状态上
* 我们可以每次递推后改变状态：i-1, i-2 = i, i-1，所以只需要两个变量加一个中间临时变量就可以

### 代码
```js
var rob = function(nums) {
    let [prev, now] = [0, 0] // prev为i-2，now为i-1
    for (let i = 0; i < nums.length; i ++) {
        const tmp = now
        now = Math.max(now, prev + nums[i]) // i的状态
        prev = tmp
    }
    return now
}
```

### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(1)
