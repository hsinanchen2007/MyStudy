### 官方实现2
此处撰写解题思路

### 代码

```golang
func sortArrayByParityII(A []int) []int {
    j := 1
    for i:=0;i< len(A);i+=2{
        if A[i]%2 == 1 {//j
            for A[j]%2 == 1{
                j+=2
            }
            //j 是o
            t := A[i]
            A[i] = A[j]
            A[j] = t
        }
 
    }
    return A

}
```