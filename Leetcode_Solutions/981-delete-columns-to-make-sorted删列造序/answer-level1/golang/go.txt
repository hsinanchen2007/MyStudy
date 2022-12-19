### 解题思路
此处撰写解题思路

### 代码

```golang
func minDeletionSize(A []string) int {
	count:=0

	for j:=0;j< len(A[0]);j++{
		for i:=0;i< len(A)-1;i++{
			if A[i][j]>A[i+1][j]{
				count++
                break
			}
		}
	}
	return count
}
```