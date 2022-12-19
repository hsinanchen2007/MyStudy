## 结果

![image.png](https://pic.leetcode-cn.com/1fc93a2a8ccc15fb1e70579c122c3bbfb657591b4b6434d063553990708a719c-image.png)

## 思路

整体思路为使用回溯算法，先将原数组按升序排序，定义一个游标i从最小位置开始填数。使用游标和排序好的数组可以确保每个答案唯一且不重复。

- 回溯的每一步从数组第i位置的数开始填，如果填上以后总和小于target，则先填上，下一步继续从i位置填
- 如果填上后总和刚好等于target，则找到了一个答案，因为数组是升序排列且不重复，所以记录答案后直接返回上一步，没必要继续填
- 如果填上后总和大于target，同样没必要继续填了，返回上一步

##

```
func combinationSum(candidates []int, target int) (result [][]int) {
    sort.Ints(candidates)
    buf := []int{}
    fill(candidates, target, 0, 0, buf, &result)
    return
}

func fill(candidates []int, target, i, sum int, buf []int, result *[][]int) {
    n := len(candidates)
    // 从第i位置开始填，升序数组可以保证答案不重复
    for j:=i;j<n;j++ {
        v := candidates[j]
        if sum + v < target {
            buf = append(buf, v)
            nb := len(buf)
            fill(candidates, target, j, sum+v, buf, result)
            buf = append(buf[:nb-1], buf[nb:]...)
            continue
        }else if sum + v == target {
            // 找到答案，返回
            cp := make([]int, len(buf))
            copy(cp, buf)
            cp = append(cp, v)
            *result = append(*result, cp)
            return
        } else {
            // 升序数组，没必要继续找了
            return
        }
    }
    
}
```
