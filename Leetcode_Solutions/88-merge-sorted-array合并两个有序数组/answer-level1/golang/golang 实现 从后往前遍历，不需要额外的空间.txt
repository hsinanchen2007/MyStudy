//从后往前遍历 不需要额外的空间
![image.png](https://pic.leetcode-cn.com/e2b6505722d6676a28b89c026bdd9cfc30a460d476f2168ef0bd2cbcac41eb48-image.png)

```
func merge(nums1 []int, m int, nums2 []int, n int)  {
	end1,end2:=m-1,n-1
	sum:=m+n-1
	for end1>=0&&end2>=0 {
		if nums2[end2]>=nums1[end1] {
			nums1[sum]=nums2[end2]
			end2--
			sum--
		}else {
			nums1[sum]=nums1[end1]
			end1--
			sum--
		}
	}
	if end2>=0 {
		for ;end2>=0;end2--{
			nums1[sum]=nums2[end2]
			sum--
		}
	}
	return
}

```
