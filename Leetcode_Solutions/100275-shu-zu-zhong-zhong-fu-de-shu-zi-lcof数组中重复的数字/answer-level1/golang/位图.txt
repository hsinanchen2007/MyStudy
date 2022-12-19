本题特点: 
数组中的元素都小于数组长度n，所以我们可以定义一个大小为n的数组，通过位图的方式来标记元素是否已经存在。
多定义一个数组会浪费空间，那我们能不能不单独定义一个数组，而是使用原来的数组呢？
由于数组中的元素都大于等于0，我以我们可以利用这一点，我们把对应位置的数值变为负数。


### 代码1

```golang
func findRepeatNumber(nums []int) int {
    n := len(nums)
    bitmap := make([]int,n)
    for _, v :=range nums{
        if bitmap[v] ==1{
            return v
        }else{
            bitmap[v] = 1
        }
    }
    panic("illegal parameters")
}
```

### 代码2
```
func findRepeatNumber(nums []int) int {
    for _, v :=range nums{
        if v < 0{
            v = -1 * v
        }
        if nums[v] < 0 {
            return v
        }else{
            nums[v] = -1 * v //设置为负数
        }
    }
    return 0 //由于0没有办法变为负数，所以一旦走到这里，一定是0
}
```