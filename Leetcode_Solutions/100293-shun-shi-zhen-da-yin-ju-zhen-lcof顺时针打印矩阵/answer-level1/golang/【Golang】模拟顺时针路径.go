# 解题思路

## 模拟顺时针路径


 - 假定矩阵的形状是 m * n，那么一共要遍历 m * n 次。
   
 - 时间复杂度为 O(M * N)，空间复杂度为 O(M * N)。
   
 - 准备一个长度为 m*n 的数组nums，来保存遍历过的数值。数字的排列顺序是顺时针。
   
 - 定义四个变量记录各个方向的界限值，step作为nums数值位置的索引
   
 - 当平行方向/垂直方向遇到超出界限的情况时，结束对应方向的行走，且对应方向的界限会 -1 或 +1


---

# 代码


--执行时间：12 ms 	--消耗内存：6 MB


```go
func spiralOrder(matrix [][]int) []int {
    if len(matrix)==0{
        return nil
    }
    step:=0
    size:=len(matrix)*len(matrix[0])
    //定义四个方向的端点
    top,bottom,right,left:=0,len(matrix)-1,len(matrix[0])-1,0
    nums:=make([]int,size)
    for step<size{
        //从左到右
        for i:=left;i<=right && step<size;i++{
            nums[step]=matrix[top][i]
            step++
        }
        top++
        //从上到下
        for i:=top;i<=bottom && step<size;i++{
            nums[step]=matrix[i][right]
            step++
        }
        right--
        //从右到左
        for i:=right;i>=left && step<size;i--{
            nums[step]=matrix[bottom][i]
            step++
        }
        bottom--
        //从下到上
        for i:=bottom;i>=top && step<size;i--{
            nums[step]=matrix[i][left]
            step++
        }
        left++
    }
    return nums
}
```
---
