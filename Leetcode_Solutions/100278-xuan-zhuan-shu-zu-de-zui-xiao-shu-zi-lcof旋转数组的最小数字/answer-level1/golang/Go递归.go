![image.png](https://pic.leetcode-cn.com/1ad6298402899f879193ea3b099e26e1631b91e6f63820c9baaf7d19e262f1ff-image.png)

### 解题思路
二分查找`mid:=(lo+hi)/2`,这样`lo<=mid<`，判断条件有一下三种情况：
* `numbers[mid]>numbers[hi]`
此时目标元素一定在mid右侧
* `numbers[mid]>numbers[lo]`
此时目标元素一定在mid左侧

其他情况不确定目标元素与mid的相对位置，但是可以确定的是hi一定不是目标，所以缩小范围。

### 代码

```golang
func minArray(numbers []int) int {
    var f func(lo,hi int)int
    f=func(lo,hi int)int{
        if lo==hi{
            return numbers[lo]
        }
        mid:=(lo+hi)/2
        if numbers[mid]>numbers[hi]{
            return f(mid+1,hi)
        }else if numbers[mid]>numbers[lo]{
            return f(lo,mid-1)
        }else{
            return f(lo,hi-1)
        }
    }
    return f(0,len(numbers)-1)
}
```