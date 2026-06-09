**实现思路**
```
1. 排序
2. 遍历：合并
```
**代码实现**

```
func  helper(a []int,b []int) bool {
	if a[1] < b[0]{
		return false
	}else if a[1] <b[1]{
		b[0] = a[0]
		return true
	}else{
		b[0],b[1] = a[0],a[1]
		return true
	}
}

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0]<intervals[j][0]{
			return true
		}else if intervals[i][0]>intervals[j][0]{
			return false
		}else{
			if intervals[i][1]<intervals[j][1]{
				return true
			}else{
				return false
			}
		}
	})
	var index = 0
	for index < len(intervals)-1{
		var flag = helper(intervals[index],intervals[index+1])
		if flag{
			if index != 0{
				intervals = append(intervals[:index],intervals[index+1:]... )
			}else{
				intervals = intervals[index+1:]
			}
		}else{
			index++
		}
	}
	return intervals
}

```
