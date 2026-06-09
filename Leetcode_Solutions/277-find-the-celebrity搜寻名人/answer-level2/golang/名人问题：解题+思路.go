### 解题思路
方法一：暴力法
    1，判断第i个节点是否只认识自己（不是则返回-1）
    2，再判断其他人是否都认识第i个节点（不是则返回-1）

### 代码

```golang
/**
 * The knows API is already defined for you.
 *     knows := func(a int, b int) bool
 */
func solution(knows func(a int, b int) bool) func(n int) int {
    return func(n int) int {
        for x :=0;x<n;x++ {
            //是否x只认识自己
            var konwSum int 
            //记录下y是谁
            var konwNum int
            for y:=0;y<n;y++ {
                if ok := knows(x,y);ok {
                    konwSum ++
                    konwNum = y
                }
                
            }
            if konwSum == 1 {
                isOk := check(n,konwNum,knows)
                if isOk{
                    return konwNum
                    break
                }
                return -1
            }
        }
        return -1
    }
}

//是否其他人都认识ta
func check(n,y int,knows func(a int, b int) bool) bool{
    for i:=0;i<n;i++ {
        if ok:=knows(i,y);!ok {
            return false
        }
    }
    return true
}

```