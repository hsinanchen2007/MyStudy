### 解题思路
![444.png](https://pic.leetcode-cn.com/6414915c0a9e929aa8dfa6e36a7420199edb9db97cc4ca17425ffcd5a6087743-444.png)


### 代码

```golang
func find132pattern(a []int) bool {

    if len(a)==0{return false}
	ok := []int{}
	l := a[0]
	r := a[0]
	
	for i := 1; i < len(a); i++ {
	
		if a[i] < l {
            if l<r{
			ok = append(ok, l, r)
            }
			l = a[i]
			r = a[i]
			continue
		}

        for j := 0; j < len(ok); j += 2 {
			if ok[j] < a[i] && a[i]<  ok[j+1]  {
				return true
			}
		}
		if l < a[i] && a[i] < r {
			return true
		}

      
         r = max(r, a[i])
         
      
    

	}
	return false
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```