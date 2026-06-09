### 解题思路
此处撰写解题思路
![7CD64A3F-FB18-427b-8F76-7591B8017821.png](https://pic.leetcode-cn.com/10fde74072634653123a0486e7805a803555555355d3dc8050f943023a4eb2ad-7CD64A3F-FB18-427b-8F76-7591B8017821.png)

算是动态规划吧，他的最优结构其实就是他的纵坐标-1的的坐标路径数+横坐标-1的坐标路径数 

应该是等于0的 比较特殊
切片d初始化之后 里面的所有值都是0
d[0][0] = 0
d[1][0] = 1
d[0][1] = 1
d[1][1] = d[1][0] + d[0][1] = 1+1 =2
d[0][2] = d[0][1] + d[0][2] = 1+0 =1

### 代码

```golang
func uniquePaths(m int, n int) int {
    if m == 1 && n== 1 {
		return 1
	}
    	//n 行 m列
	d := make([][]int,n)
	var  f  int
	var  s  int
	for i:=0;i<n;i++ {
		d[i] = make([]int,m)
	}

	d[0][0] = 0
	if (m-1>0) {
		d[0][1] = 1
	}
	if (n-1>0) {
		d[1][0] = 1
	}

	for j:=0;j<n;j++ {
		for k:=0;k<m;k++ {
			if j == 0 && k ==0 {
				continue
			}
			if k-1 < 0 {
				f=0
			} else {
				f = k-1
			}
			if j-1 < 0 {
				s=0
			} else {
				s = j-1
			}

			d[j][k] = d[j][f] + d[s][k]
		}
	}


	return d[n-1][m-1]
}
```