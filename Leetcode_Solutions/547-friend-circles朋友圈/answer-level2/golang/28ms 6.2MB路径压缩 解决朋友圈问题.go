### 解题思路
此处撰写解题思路

参考最小生成树里面的链接方法

### 代码

```golang

func findFatherZip(father []int, i int) int {

	j := i
	for father[i] != i {
		i = father[i]
	}

	//通过压缩，树最高三层，所以把最开始的指向树顶就可以
	father[j] = i
	return i

}
func uniZip(father []int, i, j int) {
	i = findFatherZip(father, i)
	j = findFatherZip(father, j)
	father[i] = j

}
func findCircleNum(M [][]int) int {

	mLen := len(M)
	if mLen <= 1 {
		return mLen
	}

	father := make([]int, mLen)
	for i := 0; i < mLen; i++ {
		father[i] = i
	}

	for i := 0; i < mLen; i++ {
		for j := i + 1; j < mLen; j++ {
			if M[i][j] == 1 {
				uniZip(father, i, j)
			}
		}
	}

	count := 0
	for i := 0; i < mLen; i++ {
		if father[i] == i {
			count++
		}
	}

	return count

}

```