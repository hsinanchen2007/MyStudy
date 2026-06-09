golang 动态规划：

执行用时 :0 ms, 在所有 golang 提交中击败了100.00%的用户

内存消耗 :2.6 MB 

![QQ20191015-133440@2x.png](https://pic.leetcode-cn.com/9c9c5e4f1fa57ec996e3bdf3fbecc00965e9c5f83925741be180e5c28afbfb1c-QQ20191015-133440@2x.png)


```
func IsMatch(s string, p string) bool {
	return newCoder().match(0 , 0 , s ,p)
}

type Coder struct {
	cache map[uint64]bool
}

func newCoder() *Coder {
	return &Coder{
		cache:make(map[uint64]bool),
	}
}

func (c *Coder) match(sIndex , pIndex int , s , p string) bool {
	var success bool
	cIndex := compress(sIndex , pIndex)
	if s , ok  := c.cache[cIndex]  ; ok {
		return s
	}
	if pIndex == len(p){
		return sIndex == len(s)
	}
	cur :=  sIndex < len(s) && (s[sIndex] == p[pIndex] || p[pIndex] == '.')
	if pIndex + 1 < len(p) && p[pIndex + 1] == '*' {
		success = c.match(sIndex , pIndex + 2 , s , p) || (cur && c.match(sIndex+ 1 , pIndex, s, p))
	} else {
		success = cur && c.match(sIndex + 1 , pIndex + 1 , s ,p)
	}
	c.cache[cIndex] = success
	return success
}

func compress(sIndex , pIndex int) uint64 {
	var value uint64
	value = value | uint64(sIndex)
	value <<= 32
	value = value | uint64(pIndex)
	return value
}
```
