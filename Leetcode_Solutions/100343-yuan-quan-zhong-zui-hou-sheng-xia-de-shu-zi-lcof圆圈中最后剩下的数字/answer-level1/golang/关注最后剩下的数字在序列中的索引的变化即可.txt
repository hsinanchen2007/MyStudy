### 解题思路
m : 每次删除第m个数字
n : 一共有n个数字
假设最后剩下的数字 在序列长度为n的数组中 索引为x
找出每次删除的时候 n,m,x的关系即可解出方程

### 代码

```golang
func lastRemaining(n int, m int) int {    	
    x  := 0
	tn := 1
	for i := 0;i <= n-1; i++ {
		x = (x + m) % tn
		tn++
	}
    return x
}

```