## 思路

题目与组合总和类似，首先将数组升序排序，然后从左开始找。回溯算法的每一步需要填入candidates中未使用的数，同时比较填数总和情况
- 如果填数后总和小于target，则进入下一步继续填入下一位，下一位填入的数字可能与当前数字相同
- 进入填数下一步返回之后，因为有可能下一步搜索选择的数会重复，所以加入跳过搜索重复数字的步骤，防止出现重复答案
- 如果填数后总和与target相等，则判定找到一组答案，算法返回
- 如果填数后总和大于target，因为数组是升序，往后肯定找不到答案，所以算法返回

## 

```
func combinationSum2(candidates []int, target int) (result [][]int) {
    sort.Ints(candidates)
    fill(candidates, target, 0, 0, []int{}, &result)
    return
}

func fill(candidates []int, target, i, sum int, buf []int, result *[][]int) {
    n := len(candidates)
    for j:=i; j<n;j++ {
        v := candidates[j]
        if sum + v < target {
            nb := len(buf)
            buf := append(buf, v)
            fill(candidates, target, j+1, sum+v, buf, result)
            buf = append(buf[:nb], buf[nb+1:]...)
            // 如果之后的数字和当前的一样就会产生重复答案，应该跳过
            for j+1 < n && candidates[j+1] == v {
                j++
            }
        } else if sum + v == target {
            cp := make([]int, len(buf))
            copy(cp, buf)
            *result = append(*result, append(cp, v))
            return
        }else {
            return
        }
    }
}
```
