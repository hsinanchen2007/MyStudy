# 观题

旋转数组再返回最小的数字

从题目来看，就是通过循环比较数组左边的数字和右边的数字，将较大数值的数字，交换到数组的尾部
返回结果的头部，即是最小的数字
**但如果按照题目思路来进行先交换后输出，可能会提示“超出时间限制”。**

其实题目的目的，就是返回一个数组中的最小数字

所以有以下两种解法

---

# 解法一:二分查找

**定义变量：Left为数组最左端下标，Right为数组最右端下标**

--执行用时：4 ms     --内存消耗：3.1 MB

```go
func minArray(numbers []int) int {
    //Left为数组最左端下标，Right为数组最右端下标
    Left:=0
    Right:=len(numbers)-1
    for Left<Right{
        mid:=(Left+Right)/2
        //有序数组
        if numbers[Left]<numbers[Right]{
            return numbers[Left]
        }
        //如果numbers[mid]大于numbers[Left],说明mid左边是递增有序数组
        //而又因numbers[Left]大于numbers[Right]，说明最小值不在左边
        //所以舍弃包括mid左边的子数组
        if numbers[mid]>numbers[Left]{
            Left=mid+1
        }else if numbers[mid]<numbers[Left]{
            Right=mid
        //如果numbers[mid]==numbers[Left]，则移动左边的下标即可
        }else{
            Left++
        }
    }
    return numbers[Left]
}
```

---

# 解法二:递增排序后查找

**这里利用sort包下的Ints(a []int)方法，将数组转化为一个递增排序的数组**
**直接返回数组第一个位置的值即是最小值**

--执行用时：4ms     --内存消耗：3.1MB

【为何用时比二分法还短？这里应该是由于sort包下的方法已有很大方面的优化】
【如果是自己写的暴力方法，排序后再进行查找，应该会慢很多，甚至超出时间限制】

```go
func minArray(numbers []int) int {
    sort.Ints(numbers)
    return numbers[0]
}
```
