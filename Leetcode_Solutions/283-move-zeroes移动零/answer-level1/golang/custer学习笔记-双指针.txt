# 第一思路
时间复杂度O(n) 空间复杂度O(n)

```go
func moveZeroes(nums []int) {
    arr := make([]int, 0) // 去除0的数组
    cnt := 0              // 记录0的个数
    // 1. 遍历数组记录0的个数，和去除0的数组
    for _, n := range nums {
        if n == 0 {
            cnt++
        } else {
            arr = append(arr, n)
        }
    }
    // 2. 在去除0的数组之后追加0
    for i := 0; i < cnt; i++ {
        arr = append(arr, 0)
    }
    // 3. 把arr赋值给nums
    for i := 0; i < len(nums); i++ {
        nums[i] = arr[i]
    }
}
```

# 另一种思路

```go
func moveZeroes(nums []int) {
  var nonZerosElements []int

  // 将nums中所有非0元素放入nonZeroElements中
  for i := 0; i < len(nums); i++ {
    if nums[i] != 0 {
      nonZerosElements = append(nonZerosElements, nums[i])
    }
  }

  // 将nonZerosElements中的所有元素依次放入到nums开始的位置
  for i := 0; i < len(nonZerosElements); i++ {
    nums[i] = nonZerosElements[i]
  }

  // 将nums剩余的位置放置为0
  for i := len(nonZerosElements); i < len(nums); i++ {
    nums[i] = 0
  }
}
```

# 在数组中原地操作
时间复杂度O(n),空间复杂度O(1)

```go
func moveZeroes(nums []int) {
    tmp:=0
    for i := 0; i < len(nums); i++ {
        if nums[i] != 0 {
            nums[tmp] = nums[i]
            tmp++
        }
    }

    for i := tmp; i < len(nums); i++ {
        nums[i] = 0
    }
}
```

# 优化的思路

```go
// 时间复杂度O(n),空间复杂度O(1)
func moveZeroes(nums []int) {
  k := 0 // nums中,[0...k)的元素均为非0元素
  // 遍历到第i个元素后,保证[0...i]中所有非0元素
  // 都按照顺序排序再[0...k)中
  for i := 0; i < len(nums); i++ {
    if nums[i] != 0 {
      nums[k] = nums[i]
      k++
    }
  }

  // 将nums剩余的位置放置0
  for i := k; i < len(nums); i++ {
    nums[i] = 0
  }
}
```


```go
func moveZeroes(nums []int) {
  k := 0 // nums中,[0...k)的元素均为非0元素
  // 遍历到第i个元素后,保证[0...i]中所有非0元素
  // 都按照顺序排序再[0...k)中
  // 同时,[k...i]为0元素
  for i := 0; i < len(nums); i++ {
    if nums[i] != 0 {
      if i != k { // 如果整个数组全是非0元素
        nums[k], nums[i] = nums[i], nums[k]
        k++
      } else { // i == k避免每个非0元素都自己和自己交换位置
        k++
      }
    }
  }
}
```