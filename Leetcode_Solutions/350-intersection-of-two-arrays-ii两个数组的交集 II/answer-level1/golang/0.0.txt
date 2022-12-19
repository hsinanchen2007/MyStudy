### 解题思路
此处撰写解题思路
我也不晓得是怎么做的

### 代码

```golang
func intersect(nums1 []int, nums2 []int) []int {


	res := []int{}

	for i:=0;i< len(nums1);i++{
		for j:=0;j< len(nums2);j++{
			
			if nums1[i]==nums2[j]{
				res = append(res, nums1[i])
				if j== len(nums2)-1{
					nums2 = nums2[:j]
					break
				}
				nums2 = append(nums2[:j],nums2[j+1:]...)
				//fmt.Println(nums2,i)
				break
			}
		}
	}

	return res
}
```