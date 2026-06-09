### 解题思路
思路就是按照官方讲解里的，这里仅分享一下golang版本的代码。

### 代码

```golang
func massage(nums []int) int {
    sumOne := 0
    sumTwo := 0
    for _,val := range nums{
        sumTwo,sumOne = sumOne,Max(sumTwo + val,sumOne)
    }
    return Max(sumOne,sumTwo)
}
func Max(x,y int)int{
    if x > y{
        return x
    }
    return y
}
```