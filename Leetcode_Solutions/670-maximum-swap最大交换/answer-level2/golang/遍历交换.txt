### 解题思路
将 num 转换为 int 的数组 arr，如 2374 转换为 []int{2,3,7,4};从最高位开始循环，设当前最高位为 i，从 arr[i+1:] 中找到最末尾的最大的数字的下标 j,如果 arr[i] < arr[j],则交换；否则 i++,继续。

### 代码

```golang
func maximumSwap(num int) int {
    arr := int2arr(num)
    n := len(arr)
    for i:=n-1;i>=0;i--{
        tIndex := 0
        for j:=0;j<i;j++{
            if arr[j] > arr[tIndex]{
                tIndex = j
            }
        }
        if arr[i] < arr[tIndex]{
            tmp := arr[i]
            arr[i] = arr[tIndex]
            arr[tIndex] = tmp
            break
        }
    }
    return arr2num(arr)
}

func arr2num(arr []int)int{
    cur := 1
    ret := 0
    for i:=0;i<len(arr);i++{
        ret += arr[i] * cur
        cur *= 10
    }
    return ret
}

func int2arr(num int)[]int{
    cur := 10
    ret := []int{}
    for num > 0 {
        t := num % cur
        num = num / 10
        ret = append(ret,t)
    }
    return ret
}


```