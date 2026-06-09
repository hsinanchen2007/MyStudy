### 解题思路
本题思路不难，只是记录一下我做错的地方： 开始写成了preSli:=make([]int,33)，最大为33行，所以申请的内存要大于33，此处写成： preSli:=make([]int,34)

### 代码

```golang
func getRow(rowIndex int) []int {
    if rowIndex==0{
        return []int{1}
    }

    preSli:=make([]int,34)
    preSli[0]=1
    for i:=1;i<=rowIndex;i++{
        tmp:=make([]int,i+1)
        tmp[0],tmp[i]=1,1

        for j:=1;j<i;j++{
            tmp[j]=preSli[j-1]+preSli[j]
        }
        copy(preSli,tmp)
    }  

    return preSli[:rowIndex+1] 
}
```