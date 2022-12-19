### 解题思路
此处撰写解题思路
建立临时数组，利用go的slice特性，返回slice节省内存

### 代码

```golang
func findContinuousSequence(target int) [][]int {
    var ans [][]int
    l := target/2 + 1
    list := make([]int, l)
    slist := make([]int, l+1)

    list[0], slist[0] = 1, 1
    for i := 0; i < l; i++ {
        list[i] = i + 1
        slist[i+1] = slist[i] + list[i]
    }

    for i, j := 0, 1; i < j && j < l; {
        diff := slist[j+1] - slist[i]
        if diff == target {
            ans = append(ans, list[i:j+1])
            i++
        } else if diff < target {
            j++
        } else if diff > target {
            i++
        }
    }

    return ans
}


```