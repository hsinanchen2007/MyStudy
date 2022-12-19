### 解题思路
![Selection_007.png](https://pic.leetcode-cn.com/d60cc4af77eb5ae708b4eadcdc48fe41e70b1ad3f5b92b80827caa190a055aef-Selection_007.png)
中位数的定义大家自己去google，这里就不解释啦～

该题目的一般形式是找出两个有序数组中的第k小。
一般想法是，我从两个数组中各取一个，比较大小，把小的丢掉。然后从较小的数所在的数组中再取一个，直到取出k个。此时手中还有两个数，较大的那个就是第k小。

但考虑到数组已经有序，这样做效率显然不高，不如一次多取几个。

那么取多少呢？反正最终是要取出k个的，不如就一次性从两个数组各取m、n个，其中m+n=k。

但是我们随手一取，总没有那么好运恰好取出了最小的k个。

我们令最小的k个数的集合为 ***K***，m个数和n个数的集合分别为 ***M*** 和 ***N***， 那么 ***M*** 包含于 ***K*** 和 ***N*** 包含于 ***K*** 必有一个成立，我们只需要比较***M*** 和 ***N*** 两个集合的最大值即可，较小的集合直接全部丢掉，然后再从数组中取一组。

一组是多少个呢？事实上都可以！但比较好的做法是取二分，比如从剩下的取一半，那么由于要满足m+n=k，因此另一个数组中就要将同样数量的数字放回。
或者我们先把另一个数组中取出数字的一半放回，然后从丢掉的集合所属的数组中取同样数量。我在代码中采用的后一种方案。这种改进方案的临界条件跟一个一个取是一样的。

对于该题目取中位数来说，假设两个数组数字总个数是m，如果m是奇数，那么该题目等价于求第m/2+1小，如果m是偶数，就是第m/2小和第m/2+1小的均值


### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	totalLength := len(nums1)+len(nums2)
	if totalLength&1 == 1 {
		return float64(findKthElem(nums1, nums2, totalLength/2+1))
	}
	return 0.5 * float64(findKthElem(nums1, nums2, totalLength/2) + findKthElem(nums1, nums2, totalLength/2+1))

}

//1<=k<=len(nums1)+len(nums2)
func findKthElem(nums1, nums2 []int, k int) int {
	var i, j, l1 int
	for {
		if len(nums1) > len(nums2) {
			nums1, nums2 = nums2, nums1
		}
		l1 = len(nums1)
		if l1 == 0 {
			return nums2[k-1]
		}
		if k == 1 {
			return min(nums1[0], nums2[0])
		}
		if k/2 > l1 {
			i = l1
		} else {
			i = k / 2
		}
		j = k - i
		// 1 <= i,j <= k/2 <= l1 <= l2, 可以推出来的哦
		if nums1[i-1] > nums2[j-1] {
			nums2 = nums2[j:]
			k -= j
		} else if nums2[j-1] > nums1[i-1] {
			nums1 = nums1[i:]
			k -= i
		} else {
			return nums1[i-1]
		}
	}
}

func min(num1, num2 int) int {
	if num1 < num2 {
		return num1
	}
	return num2
}
```