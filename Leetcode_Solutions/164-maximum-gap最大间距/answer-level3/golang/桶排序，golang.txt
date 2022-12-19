### 解题思路

桶排序的思路，首先依据如下的原理（鸽巢原理）

- 当前排序后的相邻元素的最大与最小值取值于`当前桶内的最小元素与前一个非空桶的最大值`

因此，算法有如下步骤：
- 计算当前数组中最大值`max`与最小值`min`
- 求出每个桶的大小 `sz :=  (max - min) / len(nums) + 1`
- 然后遍历数组`nums`，然后将每个元素进行分桶操作，并记录和更新当前桶中的最大值与最小值，这里记录桶中最大值与最小值采用了字典，key为桶的编号，value为当前桶中的最大值或者最小值
- 最后，遍历桶，求解当前桶的最小值与上一个非空桶的最大值的差值，然后更新结果。	


### 代码

```golang
import "math"

func maximumGap(nums []int) int {
	if 0 == len(nums) {
		return 0
	}
	// 找到最大与最小值
	max, min := math.MinInt64, math.MaxInt64
	for _, v := range nums {
		if v > max {
			max = v
		}

		if v < min {
			min = v
		}
	}
	// 每个桶的大小
	sz := (max - min) / len(nums) + 1
	mMin, mMax := map[int]int{}, map[int]int{}
	for _, n := range nums {
		k := (n - min) / sz  // 落在第几个桶中

		// 记录和更新每个桶中的最大值和最小值
		if v, ok := mMin[k]; !ok || n < v {
			mMin[k] = n
		}
		if v, ok := mMax[k]; !ok || n > v {
			mMax[k] = n
		}
	}

	o, pi := 0, 0
	// 这一步就是索引每个桶中元素，当前桶中最小值，与前一个费空桶的最大值
	for i := 1; i < len(nums); i++ {
		if min, ok := mMin[i]; ok {
			t := min - mMax[pi]
			if t > o {
				o = t
			}
			pi = i
		}
	}
	return o
}
```