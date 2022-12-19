### 解题思路
此处撰写解题思路

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    for i,j:=0,0;j<n;i++{
		if i>=m+j{
			nums1[i]=nums2[j]
			j++
			continue
		}
		if nums2[j]<=nums1[i]{
			for p:=m+j;p>i;p--{
				nums1[p]=nums1[p-1]
			}
			nums1[i]=nums2[j]
			j++
		}
	}
}
```