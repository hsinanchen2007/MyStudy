### 解题思路
暴力求解思路
1、首先，题目的条件是：如果数组中多一半的数都是同一个，则称之为主要元素，则可以转化为求每个元素出现的次数
2、将第一步得出每个元素的出现的次数和数组的总个数先比较，如果大于1/2则返回该元素
3、使用到map存储元素出现次数

### 代码

```golang
func majorityElement(nums []int) int {
    numLens := len(nums)
    res := make(map[int]int, numLens)
    for _, v := range nums {
        res[v]++
    }

    for k, v := range res {
        if v > numLens /2 {
            return k
        }
    }

    return -1
}
```