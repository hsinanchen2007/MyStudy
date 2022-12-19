### 解题思路
先用dfs做了一遍，发现性能很差，但是看着可以倒着来找性能就好很多了

### 代码

```golang

func getNum(idx,level int) int  {
	tmp := math.Pow(2.0,float64(level))
	begin := int(tmp)
	end := 2*begin-1
	if level%2==0{
		return idx
	}else{
		return begin+(end-idx)
	}
}


// 利用公式算出目标值在第几层 哪个位子  反推他的上一级

func getLevelAndInde(label int)(level,idx int)  {
	b,e := 2,3
	level = 1
	for{
		if label>=b && label<=e{
			break
		}
		level++
		b = b*2
		e = b*2-1
	}
	if level%2==0{
		idx = label
	}else{
		// 算出他的位子  就是idx
		idx = e-label+b
	}
	return
}


func pathInZigZagTree(label int) []int {
	switch label {
	case 0:
		return nil
	case 1:
		return []int{1}
	default:
		l,idx := getLevelAndInde(label)
		res := make([]int,l+1)
		res[l] = label
		for l>0{
			idx = idx/2
			l--
			res[l] = getNum(idx,l)
		}
		res[0] = 1
		return res
	}
}


```