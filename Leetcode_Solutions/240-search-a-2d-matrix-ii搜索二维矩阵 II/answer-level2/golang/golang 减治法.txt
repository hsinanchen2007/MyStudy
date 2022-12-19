### 代码

```golang
/**
1. 减治思想
        1. 行与列分别有序 从左下角开始  
        2. 如果目标数大于当前值 说明目标数一定都大于当前列
        3. 如果目标数小于当前值 说明当前行一定都大于目标数
        4. 因此每次我们都以排除一行或一列 最终确定目标值
2. 分治思想
        1. 行列有序 所以 对角线也是有序的
        2. 利用对角线的有序性我们可以进行二分查找
        3. 将矩阵划分为四个区域,大于时可能有三个区域 小于时也可能三个区域
        4. 每次都将对角线上的四个对角指针调整到对角位置即可
*/
func searchMatrix(matrix [][]int, target int) bool {
   if len(matrix) == 0{
       return false
   }
   col, row := 0, len(matrix)-1
   for row >= 0 && col < len(matrix[row]){
        if matrix[row][col] == target{
            return true
        }else if  matrix[row][col] < target{
            col ++ 
        }else{
            row --
        }
   }
   return false
}
```