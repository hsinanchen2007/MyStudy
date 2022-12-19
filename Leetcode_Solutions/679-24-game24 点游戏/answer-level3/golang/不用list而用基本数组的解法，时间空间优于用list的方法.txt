1. 参考官方题解，使用list的解法：
```
func judgePoint24_0(nums []int) bool {
	floats := list.New()
	for _, v := range nums {
		floats.PushBack(float64(v))
	}
	return solve(floats)
}

func solve(nums *list.List) bool {
	if nums.Len() == 0 {
		return false
	}
	if nums.Len() == 1 {
		return math.Abs(nums.Front().Value.(float64)-24.0) < 1e-6
	}
	elementI := nums.Front()
	for i := 0; i < nums.Len(); i++ {
		elementJ := nums.Front()
		for j := 0; j < nums.Len(); j++ {
			if i == j {
				elementJ = elementJ.Next()
				continue
			}
			tmp := list.New()
			e := nums.Front()
			for k := 0; k < nums.Len(); k++ {
				if k != i && k != j {
					tmp.PushBack(e.Value)
				}
				e = e.Next()
			}
			for k := 0; k < 4; k++ {
				iVal, jVal := elementI.Value.(float64), elementJ.Value.(float64)
				if k < 2 && j > i || k == 3 && jVal == 0 {
					continue
				}
				if k == 0 {
					tmp.PushBack(iVal + jVal)
				} else if k == 1 {
					tmp.PushBack(iVal * jVal)
				} else if k == 2 {
					tmp.PushBack(iVal - jVal)
				} else if k == 3 {
					tmp.PushBack(iVal / jVal)
				}
				if solve(tmp) {
					return true
				}
				tmp.Remove(tmp.Back())
			}
			elementJ = elementJ.Next()
		}
		elementI = elementI.Next()
	}
	return false
}
```
注意到Go的list没有直接获取某个索引的元素的api，所以上面的代码有一些小改动；
另外如果list元素非常多的话，这样改动的效率也比较高，这可能也是标准库没有提供这个api的原因

有一个问题，为什么不直接用数组而是用了list呢？其实只是为了好解决上次添加过一个和/差/积/商后这一次需要去掉再添加新的运算结果的问题
比如上次已经在tmp里添加了两张牌的和，这次想要添加差，就先要把和删了
其实直接用数组也行，用一个bool变量来判断这次是直接append运算结果还是把最后一个元素替换为运算结果

2. 直接用数组的解法
```
func judgePoint24(nums []int) bool {
	floats := make([]float64, len(nums))
	for i, v := range nums {
		floats[i] = float64(v)
	}
	return judge(floats)
}

func judge(nums []float64) bool {
	if len(nums) == 0 {
		return false
	}
	if len(nums) == 1 {
		return math.Abs(float64(nums[0])-24.0) < 1e-6
	}
	for i := 0; i < len(nums); i++ {
		for j := 0; j < len(nums); j++ {
			if i == j {
				continue
			}
			var tmp []float64
			for k := 0; k < len(nums); k++ {
				if k != i && k != j {
					tmp = append(tmp, nums[k])
				}
			}
			added := false
			for k := 0; k < 4; k++ {
				iVal, jVal := float64(nums[i]), float64(nums[j])
				if k < 2 && j > i || k == 3 && jVal == 0 {
					continue
				}
				var r float64
				if k == 0 {
					r = iVal + jVal
				} else if k == 1 {
					r = iVal * jVal
				} else if k == 2 {
					r = iVal - jVal
				} else if k == 3 {
					r = iVal / jVal
				}
				if added && len(tmp) > 0 {
					tmp[len(tmp)-1] = r
				} else {
					tmp = append(tmp, r)
				}
				added = true
				if judge(tmp) {
					return true
				}
			}
		}
	}
	return false
}
```
执行后用时0ms，内存2.3M，都优于list不少