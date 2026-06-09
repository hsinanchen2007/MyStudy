### 解题思路
官方思路

### 代码

```golang
//O(n),O(T[i]可取值)
func dailyTemperatures(T []int) []int {     //单调递增stack
    stack := make([]int,0)
    result := make([]int,len(T))
    for i:=len(T)-1; i >= 0 ; i-- {
       for len(stack)>0 && T[i] >= T[stack[len(stack)-1]]{
           stack = stack[:len(stack)-1]
       }
       if len(stack) >0 {
           result[i] = stack[len(stack)-1] - i  //用slice模拟stack，FILO
       }
       stack = append(stack,i)
    }
    return result
}
```