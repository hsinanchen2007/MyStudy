### 解题思路


拿来一个数组，进行一轮交换


	// head 指向下一个可以交换的数组下标
	// tail 指向下一个可以交换的数组下标
    

选定一个参考元素 arr[0],然后依次比较剩余元素arr[i]，大的放后面(放到 tail 指向的位置)，小的放前面（放到 head 指向的位置）。

小的放前面，也就是和 arr[head] 进行交换。
交换之后，head 所指向的位置，已经是小于参考元素，所以不必再交换，所以 head++，并且 i++。

大的放后面，也就是和 arr[tail] 进行交换。
交换之后，tail 所指向的位置，已经大于参考元素，所以不必再交换，所以 tail--，此时，i 不必变化，继续比较 i 的位置（从 tail 位置交换过来的元素）与参考元素进行比较。

一轮交换完毕：

一轮交换后，head 已经和 tail 相等，而且

arr[head] == 参考元素 。

然后将数组分割成两个数组，再次分别进行一波交换

arr[:head]
arr[head+1:]

分割的子数组特点：

由于 arr[head] == 参考元素 == arr[tail]

所以，不必包含 arr[head]



## golang 数组越界问题：

1, 2, 3 数组有 3 个元素

arr := []int{1, 3, 2}

n := len(arr)

使用 arr[n:], 返回的不是数组越界，而是一个空数组。

如果 n > len(arr), 则会报错。 


### 代码

```golang
func sortArray(nums []int) []int {

   sort(nums)
   return nums
}

func sort(nums []int) {
    if len(nums) < 2 {
        return
    }
    reference := nums[0]
    head, tail := 0, len(nums)-1
    i := 1
    for head < tail {
        if nums[i] <= reference {
            nums[i], nums[head] = nums[head], nums[i]
            head++
            i++
        }else {
            nums[i], nums[tail] = nums[tail], nums[i]
            tail--
        }
    }

    sort(nums[:head])
    sort(nums[head+1:])
}



```