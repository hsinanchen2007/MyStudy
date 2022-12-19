### 解题思路
和海岛问题类似，设置状态表，DFS开启疯狂遍历模式!

![image.png](https://pic.leetcode-cn.com/91ce8acd5ed9afdc1f3c46d3ad92f033d178032da2f3c29a5f2a4a3aa3bcfd4f-image.png)

### 代码

```golang
func movingCount(m int, n int, k int) int {
	var count int
	var find [][]bool
	// 初始化状态表
	for i:=0;i<m;i++{
		var list = make([]bool,0)
		for j:=0;j<n;j++{
			list = append(list,false)
		}
		find = append(find,list)
	}
	// 查询
	DFS(0,0,&count,k,m,n,find)
	return count
}

func Add(x int) int{
	var sum int
	for x != 0{
		if x < 10{
			sum += x
			return sum
		}else{
			sum += x % 10
			x /= 10
		}
	}
	return sum
}

func DFS(x int,y int,count *int,k int,m int,n int,find [][]bool){
	// 边界条件
	if x < 0 || y < 0 || x > m-1 || y > n-1 {
		return
	}
	//	只有满足两个条件才处理，减少重复递归
	if Add(x)+Add(y) <= k && find[x][y] == false{
		*count++
		find[x][y]=true
		DFS(x-1,y,count,k,m,n,find)
		DFS(x+1,y,count,k,m,n,find)
		DFS(x,y-1,count,k,m,n,find)
		DFS(x,y+1,count,k,m,n,find)
	}
}
```