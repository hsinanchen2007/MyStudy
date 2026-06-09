# 第一思路

- 先把数组中的元素按个数累加起来，下标0的值就是0，下标1的值就是第一个元素，下标2的值就是第一个元素和第二个元素之和，下标3的值就是第一二三个元素之和
- 因为是连续子数组，所以用k来表示连续子数组的长度，count[i+k]-count[i]就是连续子数组的和
- 取最小的k值即可

执行用时 : 696 ms, 在所有 Go 提交中击败了5.10%的用户
内存消耗 : 4.3 MB, 在所有 Go 提交中击败了7.41%的用户

```go
func minSubArrayLen(s int, nums []int) int {
  count := make([]int, len(nums)+1)
  for i := 0; i < len(nums); i++ {
    count[i+1] = count[i] + nums[i]
  }
  // fmt.Println(count)

  ret := len(nums)
  for i := 0; i < len(nums); i++ {
    for k := len(nums) - i; k > 0; k-- {
      if count[i+k]-count[i] >= s {
        ret = min(ret, k)
      }
    }
  }
  if ret == len(nums) && count[len(count)-1] < s {
    return 0
  }
  return ret
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```

# 学习自[@liuyubobobo](/u/liuyubobobo/)
[<<刘宇波老师的玩转算法面试课程>>](https://github.com/liuyubobobo/Play-with-Algorithm-Interview/tree/master/03-Using-Array/Course%20Code%20(Java)/07-Minimum-Size-Subarray-Sum/src)

## 1. 暴力解
- 遍历所有的连续子数组[i...j]
- 计算其和sum，验证sum>=s
- 时间复杂度O(n^3)
- 超时

```go
// 暴力解法 时间复杂度: O(n^3) 空间复杂度: O(1)-LeetCode超时
func minSubArrayLen(s int, nums []int) int {
  res := len(nums) + 1
  for l := 0; l < len(nums); l++ {
    for r := l; r < len(nums); r++ {
      sum := 0
      for i := l; i <= r; i++ {
        sum += nums[i]
      }
      if sum >= s {
        res = min(res, r-l+1)
      }
    }
  }
  if res == len(nums)+1 {
    return 0
  }
  return res
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```

## 2. 优化暴力解: O(n^2)

```go
// 优化暴力解 时间复杂度: O(n^2) 空间复杂度: O(1)
func minSubArrayLen(s int, nums []int) int {
  sums := make([]int, len(nums)+1) // sums[i]存放nums[0...i-1]的和
  for i := 1; i <= len(nums); i++ {
    sums[i] = sums[i-1] + nums[i-1]
  }

  res := len(nums) + 1
  for l := 0; l < len(nums); l++ {
    for r := l; r < len(nums); r++ {
      // 使用sums[r+1] - sums[l]快速获取nums[l...r]的和
      if sums[r+1]-sums[l] >= s {
        res = min(res, r-l+1)
      }
    }
  }

  if res == len(nums)+1 {
    return 0
  }
  return res
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```

## 3. 滑动窗口思路: O(n)

```go
// 滑动窗口 时间复杂度: O(n) 空间复杂度: O(1)
func minSubArrayLen4(s int, nums []int) int {
  l, r := 0, -1        //nums[l...r]为我们的滑动窗口,如果[0,0]就包含了第一个元素,初始不包含任何元素
  sum := 0             // 合初始设置为0
  res := len(nums) + 1 // 最短数组长度设置为整个数组长度+1,设置为最大值

  for l < len(nums) { // 窗口的左边界在数组范围内,则循环继续
    if r+1 < len(nums) && sum < s {
      r++            // 窗口右边界扩大
      sum += nums[r] // 计算sum值
    } else { // r已经到头,或者sum>=s
      sum -= nums[l]
      l++ // 窗口左边界缩小
    }
    if sum >= s {
      res = min(res, r-l+1)
    }
  }
  if res == len(nums)+1 {
    return 0
  }
  return res
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```

## 4. 另一个滑动窗口实现，参考学习
- 时间复杂度: O(n) 空间复杂度: O(1)

```go
func minSubArrayLen(s int, nums []int) int {
  l, r := 0, -1 // [l...r] 为我们的窗口
  sum := 0
  res := len(nums) + 1

  for r+1 < len(nums) { // 窗口的右边界无法继续扩展了,则循环停止
    for r+1 < len(nums) && sum < s {
      r++
      sum += nums[r]
    }
    if sum >= s {
      res = min(res, r-l+1)
    }

    for l < len(nums) && sum >= s {
      sum -= nums[l]
      l++
      if sum >= s {
        res = min(res, r-l+1)
      }
    }
  }
  if res == len(nums)+1 {
    return 0
  }
  return res
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```

## 5. 二分搜索,扩展优化暴力的方法

- 二分搜索,扩展优化暴力的方法.对于每一个l,可以使用二分搜索法搜索r
- 时间复杂度: O(nlogn) 空间复杂度: O(n)

```go
func minSubArrayLen(s int, nums []int) int {
  sums := make([]int, len(nums)+1) // sums[i]存放nums[0...i-1]的和
  for i := 1; i <= len(nums); i++ {
    sums[i] = sums[i-1] + nums[i-1]
  }
  res := len(nums) + 1
  for l := 0; l < len(nums); l++ {
    // 实现一个基于二分搜索的lowerBound
    r := lowerBound(sums, sums[l]+s)
    if r != len(sums) {
      res = min(res, r-l)
    }
  }
  if res == len(nums)+1 {
    return 0
  }
  return res
}

// 在有序数组nums中寻找大于等于target的最小值
// 如果没有(nums数组中所有值都小于target),则返回nums.length
func lowerBound(nums []int, target int) int {
  if nums == nil /*|| !isSorted(nums)*/ {
    panic("Illegal argument nums in lowerBound.")
  }

  l, r := 0, len(nums) // 在nums[l...r)的范围内寻找解
  for l != r {
    mid := l + (r-l)/2
    if nums[mid] >= target {
      r = mid
    } else {
      l = mid + 1
    }
  }
  return l
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
```