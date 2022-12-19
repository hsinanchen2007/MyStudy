### 解题思路

用切片记录每回合得分，相加即可。

### 代码

```golang
func calPoints(ops []string) int {
	tmp := make([]int,len(ops))
	p := 0	//指向存放成绩的数组的指针
	res := 0	//总成绩
	for i := 0;i < len(ops);i++ {
		if ops[i] == "+" {
			tmp[p] = tmp[p - 1] + tmp[p - 2]
		}else if ops[i] == "D" {
			tmp[p] = tmp[p - 1] * 2
		}else if ops[i] == "C" {	//如果是C的话，就要减去上一个回合得分，指针要-1同时上一回合分数清0
			p--
			res -= tmp[p]
			tmp[p] = 0
            continue
		}else {
			tmp[p],_ = strconv.Atoi(ops[i])
		}
		res += tmp[p]
		p++
	}
    fmt.Println(tmp)
	return res
}
```