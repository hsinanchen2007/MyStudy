### 解题思路
本题思路比较特别，类似于二分查找。可以规定的起始点为左下或右上两点，此两点向不同方向走既可以增大又可以减少
算法过程：
1. 规定左下为起始点
2. 若点(i,j)等于target，直接返回true
3. 若点(i,j)小于target，向右走，及j++
4. 若点(i,j)大于target，向上走，及i--
5. 若已经到达了边界，跳出循环，说明未找到

### 代码

```golang
func searchMatrix(matrix [][]int, target int) bool {
    if len(matrix)==0{
        return false
    }
    row:=len(matrix)
    col:=len(matrix[0])
    //1. 规定起始点
    i,j:=row-1,0
    for i>=0 && j<col{
        if matrix[i][j]==target{ //2.找到则返回
            return true
        }else if matrix[i][j]<target{ //3.小于target，向右查找
            j++
        }else{                      //4.大于target，向上查找
            i--
        }
    }

    return false
}
```