### 解题思路
	其实就是在nums1  nums2中各设置一个指针指向最后一个元素，但是nums1中要注意的是，指向的是有效元素的索引位置，非数组长度，然后设置一个cur指针指向nums1数组的len(nums1)-1位置
	后面比较两个指针位置的数字大小，大的放置到cur位置处，移动各自的指针，大家可以看下下面的代码。
	
### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    i1:=m-1  //第一个数组的长度减1
	i2:=n-1
	cur:=len(nums1)-1

	//第二个数组还没有拷贝完
	for i2>=0{
		if i1>=0 && (nums1[i1]>nums2[i2]){
			nums1[cur]=nums1[i1]
			i1--
			cur--
		}else{
			//i1<0  || nums[i2]>nums[i1]
			nums1[cur]=nums2[i2]
			cur--
			i2--
		}
	}
}
```