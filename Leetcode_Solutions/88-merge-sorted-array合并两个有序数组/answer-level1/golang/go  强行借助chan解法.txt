### 解题思路
此处撰写解题思路
go  强行借助chan解法
### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    ch := make(chan int, m+n)
    i, j := 0, 0
    for (i < m && j < n) {
        if nums1[i] < nums2[j] {
            ch <- nums1[i]
            i++
        }else{
            ch <- nums2[j]
            j++
        }
    }
    if i < m {
        for ; i < m; i++ {
            ch <- nums1[i]
        }
    }else {
        for ; j < n; j++ {
            ch <- nums2[j]
        }
    }
    for i = 0; i < m+n; i++ {
        nums1[i] =<- ch
    }
}
```