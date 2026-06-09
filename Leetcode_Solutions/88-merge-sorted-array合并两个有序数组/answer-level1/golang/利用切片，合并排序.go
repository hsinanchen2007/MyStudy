func merge(nums1 []int, m int, nums2 []int, n int)  {
    s := nums1[:m]

    for i:=0;i<n;i++{
        s = append(s,nums2[i])
    }

    sort.Ints(s)
}