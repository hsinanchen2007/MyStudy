直觉上的逻辑:
1. 既然要去时间复杂度为log(m+n), 且两个序列是排好序的, 二分法不断缩小区间应该是正常的想法.
2. 对序列nums1以mid1为分界线平分两个区间`L1:mid1:R1`, 对nums2以mid2为分界线平分两个区间`L2:mid2:L2`
    如果`mid2 > mid1`, 我们是否可以舍弃mid1左边的数据和mid2右边的数据? 如果可以的话, 为了保证中位数不变, 
    两边舍弃的数据数量应该是相等的, 那么这个`removeNum`应该是多少?
3. 为了题目避免为两个数列长度做讨论, 强制设定`len(nums1) < len(nums2)` (如果事实上不是如此, 调换过来)
4. 显然这个题目写成递归形式会非常方便, 为了简单先考虑几种简单的情况
    - a. nums1为空
    - b. nums1长度为1, 此时nums1左右两边为空, 不能够进行第2条操作; 同时考虑到nums1长度只为1的局限性, 
        中位数肯定在nums2的中位数位置移动0.5个位置产生, 因而能缩短nums2
    - c. nums1长度为2, 此时nums1的剩下两个数可能最终的中位数, 也不能进行第2条操作; 同上, 中位数肯定在nums2的中位数
        位置最多移动1个位置产生, 因而能缩短nums2
    - d. nums1为1或2的时候且nums2长度也不足以操作上面的b或c时, 两个数列都已经足够小, 可以简单合并排序后取到中位数


golang 没有三元表达式所以有点啰嗦
```go
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// 保证nums1长度小于nums2
	if len(nums1) > len(nums2) {
		nums1, nums2 = nums2, nums1
	}
	// 特例1: 包含了不能再减少区间的特殊情况(并不都是特殊的, 但数量少无所谓)
	if len(nums1) == 0 || len(nums2) <= 4 {
		if len(nums1) > 0 {
			for _, num := range nums1 {
				nums2 = append(nums2, num)
			}
			sort.Ints(nums2)
		}
		if len(nums2) % 2 == 1 {
			return float64(nums2[len(nums2)/2])
		} else {
			return float64(nums2[len(nums2)/2] + nums2[len(nums2)/2-1])/2
		}
	}
	// 特例2: 有一个区间长度为1, 另一个长度大于3的情况
	if len(nums1) == 1 && len(nums2) > 3 {
		if len(nums2) % 2 == 1 {
			nums2 = nums2[len(nums2)/2-1:len(nums2)/2+2] //保留3位
		} else {
			nums2 = nums2[len(nums2)/2-1:len(nums2)/2+1] //保留2位
		}
		return findMedianSortedArrays(nums1, nums2)
	}
	// 特例3: 有一个区间长度为2, 另一个区间大于4
	if len(nums1) == 2 && len(nums2) > 4 {
		if len(nums2) % 2 == 1 {
			nums2 = nums2[len(nums2)/2-1:len(nums2)/2+2] // 保留3位
		} else {
			nums2 = nums2[len(nums2)/2-2:len(nums2)/2+2] // 保留4位
		}
		return findMedianSortedArrays(nums1, nums2)
	}
	// 能减少区间的情况
	mid1 := 0.0
	mid2 := 0.0
	if len(nums1) % 2 == 1 {
		mid1 = float64(nums1[len(nums1)/2])
	} else {
		mid1 = float64(nums1[len(nums1)/2] + nums1[len(nums1)/2-1])/2
	}
	if len(nums2) % 2 == 1 {
		mid2 = float64(nums2[len(nums2)/2])
	} else {
		mid2 = float64(nums2[len(nums2)/2] + nums2[len(nums2)/2-1])/2
	}

	// 如果恰好相等, 直接返回
	if mid1==mid2 {
		return mid1
	}

	// 两边能减少的最大的数量
	//removeNum := 0
	//if odd1 == 1 {
	//	removeNum = len(nums1)/2
	//} else {
	//	removeNum = len(nums1)/2-1
	//}
	removeNum := (len(nums1)-1)/2

	if mid2 > mid1 {
		nums1 = nums1[removeNum:]
		nums2 = nums2[0:len(nums2)-removeNum]
	} else {
		nums1 = nums1[0:len(nums1)-removeNum]
		nums2 = nums2[removeNum:]

	}
	return findMedianSortedArrays(nums1, nums2)
}
```

有一些小技巧记录一下:
1. 优化计算
```
if odd1 == 1 {
      removeNum = len(nums1)/2
} else {
      removeNum = len(nums1)/2-1
}
```
可以优化为
```go
removeNum = (len(nums1)-1)/2
```
这纯粹是计算结果一样而已, 前面的if表达式好理解为什么要那么计算, 而后者只是恰好是能观察出来的等价形式而已, 意义上没有更多好说的

>
执行用时 :
12 ms
, 在所有Go提交中击败了
99.43%
的用户
内存消耗 :
5.7 MB
, 在所有Go提交中击败了
56.44%
的用户

