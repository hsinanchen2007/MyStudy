### 解题思路
先排序，然后遍历整个二维数组，判断是否与之前的连续，若连续判断右边界并扩容，若不连续则进行下一个区间的统计。

这道题我学到最大的知识点是二维数组的切片排序！可太帅了！以下代码可以根据二维数组的第一位元素进行排序。

```golang
sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
```

//心得：这道题WA了四次，各种边界判断混淆，参数定义混淆，以后还是要给自己提个醒，少犯这种特别智障的错误QAQ



### 代码

```golang
func merge(intervals [][]int) [][]int {
    if len(intervals)==0 || len(intervals)==1{
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	ans := [][]int{}
	var max func(a int,b int)int
	max = func(a int,b int)int{
		if a>b{
			return a
		}
		return b
	}
	l:=intervals[0][0]
	r:=intervals[0][1]
	for i:=1;i<len(intervals);i++{
		if r>=intervals[i][0]{
			r = max(intervals[i][1],r)
		}else if intervals[i][0]>r{
			ans = append(ans,[]int{l,r})
			l = intervals[i][0]
			r = intervals[i][1]
		}
        // fmt.Printf("%d %d\n",l,r)
	}
	ans = append(ans,[]int{l,r})
	return ans
}
```