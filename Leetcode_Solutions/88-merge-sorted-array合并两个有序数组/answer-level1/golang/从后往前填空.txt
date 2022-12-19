### 解题思路
此处撰写解题思路

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    if n != 0 {
       i:=n-1
       j:=m-1
       for i>=0{
           for j>=0{
               if nums1[j]>=nums2[i] {
                   nums1[i+j+1] = nums1[j]
                   j--
               }else{
                   nums1[i+j+1] = nums2[i]
                   i--
                   if i == -1 {
                       break
                   }
               }
           }
           break
       }
       if i>=0 {
          for x:=0;x<=i;x++{
              nums1[x] = nums2[x]
          }
       }
    }
    
}
```