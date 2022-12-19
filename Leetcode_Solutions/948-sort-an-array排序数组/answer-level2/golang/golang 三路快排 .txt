### 解题思路

二路快排参考：[二路快排](https://leetcode-cn.com/problems/sort-an-array/solution/golang-er-lu-kuai-pai-by-rqb-2/)

## 二路快排与三路快排

先掌握二路快排，三路快排稍微改下即可

区别：

二路快排，分两部分：小于等于、大于二部分。
三路快排分为，小于、等于、大于三部分。

## 三路快排：

相比二路快排增加一个变量记录相等的起始元素。
假设选择数组第一个元素作为参考元素。则起始下边为 0，即为 equalHead

## 具体实现

1. 考察元素，与参考元素比较，

* 如果相等，不处理，head，和 i 继续增加。
* 如果待考察元素，大于参考元素，则放到数组 后面 tail 指向的位置。（此步骤和二路快排相同）
* 如果待考察元素，小于参考元素，则与 equalHead 对应的元素进行交换即可。

最后，一次排列完成后，将数组分成了三部分。

2. 递归

递归调用，传入的子数组，可以只考虑小于参考元素的部分，和大于参考元素的部分。


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
    equalHead := 0
    for head < tail {
        if nums[i] < reference {
            nums[i], nums[equalHead] = nums[equalHead], nums[i]
            head++
            i++
            equalHead++
        }else if nums[i] == reference {
            i++
            head++
        }else{
            nums[i], nums[tail] = nums[tail], nums[i]
            tail--
        }
    }

    sort(nums[:equalHead])
    sort(nums[tail+1:])
}



```