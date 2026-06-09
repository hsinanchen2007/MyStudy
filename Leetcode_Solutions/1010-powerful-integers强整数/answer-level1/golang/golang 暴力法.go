### 参考文献

[golang中实现set](https://github.com/LZH139/leetcode_Go/blob/master/guide/golang%E5%B0%8F%E6%8A%80%E5%B7%A7.md)

### 解题思路

当 x和y都取得尽可能小的时候有 $$ 2^{19}<10^6<2^{20} $$ 所以在确保i，j都小于20且单个x的i次方或者单个y的j次方都小于 bound 的情况下，暴力遍历的同时用set去重即可


### 参考代码

```go
func powerfulIntegers(x int, y int, bound int) []int {
	type void struct{}
	mp := make(map[int]void)

	var v int
	for i:=0;i<20 && Pow(x,i) <=bound;i++ {
		for j:=0;j<20 && Pow(y,j)<=bound;j++ {
			v = Pow(x,i)+Pow(y,j)
			if v <=bound {
				mp[v] = void{}
			}
		}
	}

	var res []int
	for key,_ := range mp {
		res = append(res,key)
	}

	return res
}

func Pow(x int,y int) int {
	sum:=1
	for i:=0;i<y;i++ {
		sum*=x
	}
	return sum
}

```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**


