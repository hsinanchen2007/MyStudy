扫了下前几个题解，没有我用的这种思路，所以将之贴出来。

我的核心思路是根据m（序列的长度）的奇偶性来确定序列的中位数是否是整数还是x.5，再利用了m的上限来优化遍历次数。

### 解题思路

思考：由于是连续正数序列
```go
// 例如 target = 9,   有序列 2,3,4  4,5
// 可以从2个到target个去试探：
// 长度为2的连续序列，则检查target % 2 != 0 ? 也就是要求target 为奇数，
// 而且在所有可能的解中，这个序列的首位数字是最大的
// 长度为3的话则要求 target % 3 == 0 能被3整除
// 长度为4则要求 target > 4 且 target % 4 = 1
// ....
```

- 考虑起点为a，长度为m的连续序列，其和为$(a+a+m-1) \times m/2$ , 这个值要 = target，且a最小为1，m要取尽量大，那么a必须取最小值，那么就是 $(m+1) \times m/2 <= target$ ===> $m \times m < m \times (m+1) <= 2 \times target$ ==> $m < sqrt(2 \times target)$

```go
// 也就是试探只需要从长度为m到2试探
// 先检查 m 的奇偶性和target的奇偶性
// m奇target奇， 要求target % m == 0  (这样的话序列中位数才为整数)，序列为 [target/m - m/2, ...,  target/m ,  ... ,  target/m + m/2]
// m偶target偶（偶数个连续序列中位数必然为 x.5）， 要求target % m == 1 (所以target必须为奇数) ，序列为 [target/m - m/2+1, ...,  target/m , target/m+1 ... ,  target/m + m/2]
// m奇target偶， 要求target%m==0
// m偶target奇， 要求target%m==1
//
// 其实可以合并成m奇数还是偶数两类情况
//
// 纠正，前面的 target%m==1其实想要的是商是x.5形式，但是target%m==1可能会错过，例如10%4=2，但是10/4=2.5符合
// 所以target%m==1改成 (target%m != 0) && (target * 2) % m == 0
```

### 代码

```golang
func findContinuousSequence(target int) [][]int {
	// 特殊情况：target = 1, 2
	if target < 3 {return nil}
	
	mmax := int(math.Sqrt(float64(2*target)))
	res := make([][]int, 0)
	for m:=mmax; m>=2 ; m-- {
        //fmt.Println("m=",m)
		//若序列从1开始，和还是超了target，直接跳过
		if (m+1)*m > 2*target {continue}
		// 分两种情况
		if m%2==1 && target%m==0  {		// m奇数 且 target被m整除
			start := target / m - m / 2
			tmp := make([]int, m)
			for i:=0; i<m; i++ {
				tmp[i] = start + i
			}
			res = append(res, tmp)
		}
		if m%2==0 && (target%m != 0) && (target * 2) % m == 0 {		// m偶数 且 target/m == x.5
			start := target / m - m / 2 + 1
			tmp := make([]int, m)
			for i:=0; i<m; i++ {
				tmp[i] = start + i
			}
			res = append(res, tmp)
		}
	}
	return res
}

```

来分析下我的做法，实际只遍历了mmax-2次，近似看作sqrt(target)次
至于内部填充数组，这不是数学能优化的，不管怎么得生成这些数组
因此可以说是优化程度很高的解法了
