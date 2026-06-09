### 解题思路
此处撰写解题思路
等差数列求和：起始值为a，连续n个数，target==n*a+n*(n-1)/2
n, a为正整数,n越大，a越小，直到a小于等于0
注意：题目要求a从小到大排序，最后要反转下列表。

### 代码

```golang
func findContinuousSequence(target int) [][]int {
        res:=make([][]int,0)
        for n:=2;n<target-1;n++{
             a:=(target-n*(n-1)/2)/n
            if a<=0 {
                break
            }
            q:=make([]int,n)
            if target==n*a+n*(n-1)/2 {
                 for i:=0;i<n;i++ {
                 q[i]=a+i
            }
            res=append(res,q)
            }
        }
         for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
            res[i], res[j] = res[j], res[i]
        }
        return res

}
```