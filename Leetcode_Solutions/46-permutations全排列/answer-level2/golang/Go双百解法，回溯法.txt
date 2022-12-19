### 解题思路
Go双百解法，回溯法

执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.6 MB, 在所有 Go 提交中击败了100.00%的用户

需要使用到如下几个变量
1.int数组 used 代表当前对应位置的数值用过么，0未用，1已用
2.int数组 curNums 代表当前解法已经存在几个数字，比如，可选为1，2，3，当前已存[1，3]
3.int二维数组 result 代表当前所有解法

总体思想回溯法，调用前先判断当前数值是否已用，若还没用，就先将对应数值放入curNums进行递归，返回后将已用设置为否，以便i++后再次使用。

### 代码

```golang
func permute(nums []int) [][]int {
    used:=make([]int,0)
    result:=make([][]int,0)
    curNums:=make([]int,0)
    count:=len(nums)
    i:=0
    for i=0;i<count;i++{
        used=append(used,0)
    }
    
    result=DFS(count,used,result,curNums,nums)
    return result
}

func DFS(count int,used []int, result [][]int, curNums []int,nums []int) [][]int{
    if(len(curNums)==count){
        result=append(result,curNums)
    }else{
        i:=0
        for i=0;i<count;i++{
            if(used[i]==0){
                used[i]=1
                result=DFS(count,used,result,append(curNums,nums[i]),nums)
                used[i]=0
            }
            
        }
    }
    return result
}
```