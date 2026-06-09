 1. 暴力法. 我们找到一个指定的数字, 从数组的第二个位置开始, 如果他的左边有比他小的, 让变量 left 记为true,
 如果右边有比他小的, 在次过程中又比左边的大, 让他的 right 记为true. 两个同时为true, 则返回True, 否则返回Flase.
 这样需要的空间复杂度为: O(n³), 空间复杂度为: O(1). (最后超时了)
```
var find132pattern = function(nums) {
  if (nums.length <= 2) return false
  for (let i = 1; i < nums.length - 1; i++) {
    for (let j = 0; j < i; j++) {
      console.log(1)
      if (nums[j] >= nums[i]) continue
      for (let x = i + 1; x < nums.length; x++) {
        if (nums[i] > nums[x] && nums[x] > nums[j]) return true
      }
      // while (nums[j + 1] > nums[j]) j++
    }
    // while (nums[i + 1] <= nums[i]) i++
  }
  return false
};
```

 2. 在暴力法的基础上, 我们知道, 每次循环 i 只会移动一个数字, 我们期望的情况是j最小, 那么记录一个变量去定义
 j, 当移动的时候产生的数字, 比j还小, 那么就替换他, 这样时间复杂度就降低到了O(n²). (大概600ms)

```
var find132pattern = function(nums) {
  if (nums.length <= 2) return false
  let min = nums[0]
  for (let i = 1; i < nums.length - 1; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[j] > min && nums[j] < nums[i]) return true
    }
    min = Math.min(min, nums[i])
  }
  return false
};
```
 3. 二分法. 在方法2的基础上, 我们可以对搜寻right进行优化. 在寻找left的时候,我们的方式仍然不变, 用一个最小值去寻找,
在寻找right的时候, 我们可以给定搜寻条件, 用二分法去寻找, 从而把复杂度从O(n) 降低到了O(logn). 这题是一个二分法的特
例, 因为整个数组是无序的.试着想一下, 当我们指定的数字i对应的nums[i]大于min(min为前i - 1个最小数), 右边如果只有一个
数字, 他介于min和num[i]之间结果即为true, 也只有一个数需要二分法去搜寻, 与结果相符. 然而如果有两个数是升序的, 二分法
可能会漏掉题解, 比如nums[i] 为10, 右边的数字为15, 5, 第一次搜到了5的话, 第二次就直接跳出循环了, 但是你会在i下标对应
的数字为15的时候获得true, 对于右边是一系列数字都一样, 你总会碰见这种情况: 要么升序返回了对应的结果, 要么在降序的情况
下通过i + 1的下标获得了你想要的结果.
 本题最终的时间复杂度为: O(nlogn), 空间复杂度为: O(1).(大概100ms)


```
var find132pattern = function(nums) {
  let min = nums[0]
  for (let i = 1; i < nums.length - 1; i++) {
    let left = i + 1
    let right = nums.length - 1
    let mid
    if (nums[mid] > min && nums[mid] < nums[i]) return true
    while (right >= left) {
      mid = Math.floor((left + right) / 2)
      if (nums[mid] >= nums[i] && nums[mid] > min) { // 一定要写, 因为可能出现 nums[i] 小于外面min的情况,
        // 因为外部循环是n的复杂度, 所以把判断加在这里, 可以降低一定的复杂度.
        right = mid - 1
      } else if (nums[mid] < nums[i] && nums[mid] <= min) {
        left = mid + 1
      } else if (nums[mid] > min && nums[mid] < nums[i]) {
        return true
      } else { // 这里就说明了nums[i] < min
        break
      }
    }
    min = Math.min(min, nums[i])
  }
  return false
}
```
 4.栈. 继续3的优化.我们是依靠二分法进行搜寻, 他很快, 但过程扔有一定的重复性, 我们可以依靠栈储存进行搜寻.
 我们把数组前i项最小的数字存在一个数组min内, 倒叙进行搜索right, 首先确定当前项不是最小的那一个, 
 然后保持栈内的数据都会比min[i]大, 一但栈顶小于num[i], 就立马返回true.
 时间复杂度: O(n), 空间复杂度: O(n).(大概60ms)

```
var find132pattern = function(nums) {
  if (nums.length <= 2) return false
  const min = [nums[0]]
  const stack = []
  for (let i = 1; i < nums.length; i++) {
    min[i] = Math.min(min[i - 1], nums[i])
  }
  for (let i = nums.length - 1; i > 0; i--) {
    if (nums[i] > min[i]) {
      while (stack.length !== 0 && stack[stack.length - 1] <= min[i]) {
        stack.pop()
      }
      if (stack.length !== 0 && stack[stack.length - 1] < nums[i]) {
        return true
      }
      stack.push(nums[i])
    }
  }
  return false
}
```
关于栈可能会有点难以理解, 你可以参照官方题解java的代码同步参考, 如果还有不解或者怕漏的情况, 你可以拿个笔和纸一一记录.

这是官方题解英文的链接, 他包含了5种解法: [链接](https://leetcode.com/problems/132-pattern/solution/)

不过不是javascript的, 你可以参照他的代码.