### 解题思路
通过m + n 计算总数组有效长度k
因为nums1,nums2是有序数组
先将元素从nums1末尾开始插入，nums1,nums2中较大的开始存放
这里分为两种情况：
1. nums2中元素较大直接[放入]对应位置
2. nums1中元素较大直接在nums1数组中进行[位置交换]

最终
j == -1 的情况下则表示 nums1 已经合并两个数组完毕
```
初始值
[1,2,3,0,0,0] [4,5,6]
循环后
[1,2,3,4,5,6] []
```
j >= 0则表示nums2中依然存在若干个有序元素，则直接将其copy移入nums1对应空间
```
初始值
[4,5,6,0,0,0] [1,2,3]
循环后
[0,0,0,4,5,6] [1,2,3]
copy后
[1,2,3,4,5,6] []
```

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int) {
	if m == 0 && n > 0 {
		copy(nums1, nums2)
		return
	}

	i := m - 1
	j := n - 1
	k := m + n - 1
	for i >= 0 && j >= 0 {
		if nums1[i] <= nums2[j] {
			nums1[k] = nums2[j]
			j--
		} else {
			nums1[k], nums1[i] = nums1[i], nums1[k]
			i--
		}
		k--
	}

	if j >= 0 {
		copy(nums1, nums2[:j+1])
	}
}

```