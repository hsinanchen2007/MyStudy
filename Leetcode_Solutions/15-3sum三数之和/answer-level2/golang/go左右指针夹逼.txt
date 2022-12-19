### 解题思路
```
执行用时 :
40 ms
, 在所有 golang 提交中击败了
88.71%
的用户
内存消耗 :
6.9 MB
, 在所有 golang 提交中击败了
100.00%
的用户
```
1.首先对数组进行排序
2.对排序数组自左向右进行遍历，同时在此区间内使用双指针L、R进行夹逼
3.夹逼过程中需要去重
```
    1). 首先大循环需要判断最左侧值是否大于0，因为已经对数组进行了排序，如果左侧大于0则后面的肯定都大于0
    2). 外层大循环是否与其上个位置的值相等，如果相等则跳过
    3). 内层循环，判断三个值是否等于0
    4). 如果三数之和大于0，因为左侧已经固定切已知了左侧最小值，所以需要减小右侧值大小来查找是否有符合条件的，R--
      ⭕️.如果三数之和小于0，因为右侧最大值已知，所以增加左侧值查找是否有符合条件的，L++
      ⭕️.如果三数之和等于0，保存三个值，同时判断左右两侧的下一个值是否与当前位置值相等以达到去重的目的。左侧去重条件(L<R && nums[L] == nums[L+1])，
         右侧去重条件(L<R && nums[R] == nums[R-1])
```
### 代码

```golang
func threeSum(nums []int) [][]int {
    result := make([][]int, 0)
    // 1.将数组排序
    Sort(nums)
    for i := 0 ; i<len(nums); i++ {
        // 如果最小数据大于0 则后面数据也都大于0
        if nums[i] > 0 {
            break
        }
        // 去除掉重复数据
        if i > 0 && (nums[i] == nums[i-1]) {
            continue
        }
        L := i + 1
        R := len(nums) - 1
        for L < R {
            
            count := nums[i] + nums[L] + nums[R]
            
            if count == 0 {
                temp := make([]int, 0)
                temp = append(temp, nums[i])
                temp = append(temp, nums[L])
                temp = append(temp, nums[R])
                result = append(result, temp)
                for ; L<R && nums[L] == nums[L+1]; {
                    L++
                }
                for ; L>R && nums[R] == nums[R-1]; {
                    R--
                }
                
                L++
                R--
            } else if count > 0 {
                // R向左
                R--
            } else {
                L++
            }
        }
    }
    return result
}

// 进行排序,递归排序
func Sort(nums []int) {
    len := len(nums)
    sort(nums, 0, len - 1)
}

func sort(nums []int, start int, end int) {
    // 递归退出条件
    if start >= end {
        return
    }
    i := partition(nums, start, end)
    sort(nums, start, i - 1)
    sort(nums, i + 1, end)
}

func partition(arr []int, start int, end int) int {
    pivot := arr[end]
    p := start
    q := start
    for ; q < end; q++ {
        // 如果当前值小于基准值，放在左侧p中
        if arr[q] < pivot {
            arr[p], arr[q] = arr[q], arr[p]
            p++
        }
    }
    // p与end交换
    arr[p], arr[end] = arr[end], arr[p]
    return p
}
```