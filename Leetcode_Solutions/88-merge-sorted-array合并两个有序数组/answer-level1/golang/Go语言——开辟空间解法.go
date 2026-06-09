### 解题思路
本题思路很简单，由于需要用nums1存储数组，所以需要先将nums1的数据备份到tmp，然后依次从tmp和nums2中取小的数放到nums1中

我写这道题时的思维误区是：误以为要原地覆盖掉nums1，造成很大的困难。这种合并问题开辟一个空间来解决很有必要

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    a,b:=0,0
    cur:=0
    
    tmp:=make([]int,len(nums1))
    copy(tmp,nums1)

    for a<m && b<n{
        if tmp[a]<nums2[b]{
            nums1[cur]=tmp[a]
            a++
        }else if tmp[a]>nums2[b]{
            nums1[cur]=nums2[b]           
            b++
        }else{
            nums1[cur]=tmp[a]
            cur++
            a++
            nums1[cur]=nums2[b]
            b++
        }

        cur++
    }

    if a==m{
        for b<n{
            nums1[cur]=nums2[b]
            cur++
            b++
        }
    }
    if b==n{
        for a<m{
            nums1[cur]=tmp[a]
            cur++
            a++
        }
    }

}
```