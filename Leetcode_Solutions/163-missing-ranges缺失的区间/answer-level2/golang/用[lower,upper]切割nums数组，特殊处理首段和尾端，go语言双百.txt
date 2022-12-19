### 解题思路
方法一：遍历[lower,upper]暴力判定是否在nums区间会导致超时，因为lower可能是负最小整数，upper可能是正最大整数；
方法二：通过[lower,upper]切割nums数组，将不在[lower,upper]区间的nums去掉，得到新的数组[lower,nums[i],nums[i+1]...nums[i+m],upper]
然后对于新数组分段得到区间即可。
特殊处理：
1、nums为空
2、[lower,nums[i]]、[nums[i+m],upper]需要注意特殊处理，比如lower==nums[i]或者upper==nums[i+m]
3、nums[i+1]和nums[i]相等或者连续时
4、区间只有一个元素时，区间字符串只有一个数字，没有“->”
![leetcode.png](https://pic.leetcode-cn.com/9f3b0f77b10cb79ea4466808c08e58fddafd2286fa0fc75b3f4f040075995e71-leetcode.png)

### 代码

```golang
func CreateResult(start, end int) (str string) {
	if start == end {
		str = fmt.Sprintf("%d", start)
	} else {
		str = fmt.Sprintf("%d->%d", start, end)
	}

	return str
}

func CreateParts(newNums []int, lower int, upper int) []string {
	if len(newNums) == 0 {
		return []string{CreateResult(lower, upper)}
	}

	result := make([]string, 0)
	if lower < newNums[0] {
		result = append(result, CreateResult(lower, newNums[0]-1))
	}
	for i := 0; i < len(newNums)-1; i++ {
		if newNums[i+1]-1 <= newNums[i] {
			continue
		}
		result = append(result, CreateResult(newNums[i]+1, newNums[i+1]-1))
	}

	if upper > newNums[len(newNums)-1] {
		result = append(result, CreateResult(newNums[len(newNums)-1]+1, upper))
	}

	return result
}

func findMissingRanges(nums []int, lower int, upper int) []string {
	if len(nums) == 0 {
		return []string{CreateResult(lower, upper)}
	}

	newNums := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		if nums[i] < lower || nums[i] > upper {
			continue
		}
		newNums = append(newNums, nums[i])
	}

	return CreateParts(newNums, lower, upper)
}
```