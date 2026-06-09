### 解题思路
困难的地方在于时间复杂度限制在log(m+n),应往二分法方向考虑
一开始我想m和n数组分别二分来缩小区间锁定中位数，但这样最后时间复杂度就是logm+logn = log(m·n)大于log(m+n)
意识到必须将两个数组看成一个数组来二分
想了一下午也没有想到好的方法
看了高赞题解后豁然开朗，意识到只要找第first:=(m+n-1)/2和second:=(m+n)/2个最小数就好了
高赞的二分方式让我受益匪浅，我一直想如何剔除偏小的数的区间
原来比较每个数组第first/2-1位的数，然后剔除小区间就好了，同时first-len(剔除区间)
这样思路就很明确了
剩下的难点：first在等于0、1时，secong等于0、1、2时，这些边界情况要考虑清楚

代码写的很垃圾，肯定还有能改进的地方，到时候学习下别人的写法再改进吧，目前只看了别人的思路
这题真的有点头大
### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)
	first, second := (m + n -1) / 2, (m + n) / 2
	return dichotomy(nums1, nums2, first, second)
}

func dichotomy(nums1 []int, nums2 []int, first int, second int) float64 {
	if len(nums1) == 0{
		return (float64(nums2[first]) + float64(nums2[second])) / 2
	} else if len(nums2) == 0{
		return (float64(nums1[first]) + float64(nums1[second])) / 2
	} else {
		if first > 1 {
			if len(nums1) < first/2 + 1 {
				return dichotomy(nums1, nums2[first/2:], first-first/2, second-first/2)
			} else if len(nums2) < first/2 + 1 {
				return dichotomy(nums1[first/2:], nums2, first-first/2, second-first/2)
			} else {
				if nums1[first/2-1] < nums2[first/2-1] {
					return dichotomy(nums1[first/2:], nums2, first-first/2, second-first/2)
				} else if nums1[first/2-1] > nums2[first/2-1] {
					return dichotomy(nums1, nums2[first/2:], first-first/2, second-first/2)
				} else {
					return dichotomy(nums1[first/2:],nums2[first/2:], first-first/2-first/2, second-first/2-first/2)
				}
			}
		} else {
			if first == 0 {
				if second == 0 {
					if nums1[0] <= nums2[0] {
						return float64(nums1[0])
					} else {
						return float64(nums2[0])
					}
				} else {
					if nums1[0] <= nums2[0] {
						return (float64(nums1[0]) + secondDichotomy(nums1[1:], nums2)) / 2
					} else {
						return (float64(nums2[0]) + secondDichotomy(nums1, nums2[1:])) / 2
					}
				}
			} else {
				if second == 1 {
					if nums1[0] <= nums2[0] {
						return secondDichotomy(nums1[1:], nums2)
					} else {
						return secondDichotomy(nums1, nums2[1:])
					}
				} else {
					if nums1[0] <= nums2[0] {
						return (secondDichotomy(nums1[1:], nums2) + dichotomy(nums1, nums2, second ,second)) / 2
					} else {
						return (secondDichotomy(nums1, nums2[1:]) + dichotomy(nums1, nums2, second, second)) / 2
					}
				}
			}
		}
	}
}

func secondDichotomy(nums1 []int, nums2 []int) float64 {
	if len(nums1) == 0 {
		return float64(nums2[0])
	} else if len (nums2) == 0 {
		return float64(nums1[0])
	} else {
		if nums1[0] <= nums2[0] {
			return float64(nums1[0])
		} else {
			return float64(nums2[0])
		}
	}
}
```