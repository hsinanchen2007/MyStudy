# 第一思路-错误
```go
func pivotIndex(nums []int) int {
  count := make([]int, len(nums))
  for i := 0; i < len(nums)-1; i++ {
    count[i+1] = nums[i] + count[i]
  }
  for i := 0; i < len(count); i++ {
    if count[i]*2 == count[len(count)-1] {
      return i
    }
  }
  return -1
}
```

# 学习自
https://leetcode-cn.com/problems/find-pivot-index/solution/724-xun-zhao-shu-zu-de-zhong-xin-suo-yin-by-en-zha/

## 方法：使用两个数组分别进行记录左侧右侧数字总和

```go
func pivotIndex(nums []int) int {
  left := make([]int, len(nums))
  right := make([]int, len(nums))

  sum := 0
  for i, num := range nums {
    sum += num
    left[i] = sum
  }

  sum = 0
  for i := len(nums) - 1; i >= 0; i-- {
    sum += nums[i]
    right[i] = sum
  }

  for i := 0; i < len(nums); i++ {
    if left[i] == right[i] {
      return i
    }
  }
  return -1
}
```

## 优化：只记录右侧 左侧的总和在线性遍历判定的时候一起做

```go
func pivotIndex(nums []int) int {
  right := make([]int, len(nums))

  sum := 0
  for i := len(nums) - 1; i >= 0; i-- {
    sum += nums[i]
    right[i] = sum
  }

  sum = 0
  for i := 0; i < len(nums); i++ {
    sum += nums[i]
    if sum == right[i] {
      return i
    }
  }
  return -1
}
```