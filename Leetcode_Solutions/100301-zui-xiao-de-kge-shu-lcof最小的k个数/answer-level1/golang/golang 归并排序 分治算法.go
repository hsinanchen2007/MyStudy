### 解题思路

三种方法:

1. 使用库函数sort.Ints以后，取前k个数

2. 小顶堆，堆化后，Pop出k个数

3. 归并排序后，取前k个数

### 代码 （归并排序）

```golang
func getLeastNumbers(arr []int, k int) []int {
    if len(arr) == 0 {
        return arr
    }
    ret := mapNumbers(arr)
    return ret[:k]
}

func mapNumbers(arr []int) []int {
    l := len(arr)

    if l == 1 {
        return arr
    }

    //直到最后两个数字，比较后，按升序返回
    if l == 2 {
        if arr[0] > arr[1] {
            arr[0],arr[1] = arr[1],arr[0]
        }

        return arr
    }

    //切分数组
    mid := l/2
    left := mapNumbers(arr[:mid])
    right := mapNumbers(arr[mid:])

    ret := []int{}
    i,j := 0,0
    //合并left和right，
    for i < len(left) && j < len(right) {
        if left[i] < right[j] {
            ret = append(ret,left[i])
            i++
            continue
        }
        ret = append(ret,right[j])
        j++
    }

    //两者都是按升序排序好的，剩余的都是大于前面的数字，直接追加到尾部
    if i < len(left) {
        ret = append(ret,left[i:]...)
    }

    if j < len(right) {
        ret = append(ret,right[j:]...)
    }

    return ret
}
```