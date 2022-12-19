```
    def merge(self, nums1: list, m: int, nums2: list, n: int) -> None:

        if nums2 is None or nums1 is None: return 

        if len(nums1) == 0 is None or len(nums2) == 0: return 
        # 将nums1前m个元素备份
        left_array = nums1[:m]
        nums2 = nums2[:n]
        # li是标记left_array的当前索引, ri是记录nums2的当前索引, ai标记nums1的当前索引
        li, ri, ai = 0, 0, 0
        
        # 如果li, ri都小于他们数组的长度 进入while循环
        while li < len(left_array) and ri < len(nums2):
            if nums2[ri] < left_array[li]:
                # 如果nums2[ri] < left_array[li], 将nums2中的元素添加到nums1中,与此同时对应的索引加1
                nums1[ai] = nums2[ri]
                ai += 1
                ri += 1
            else:
                nums1[ai] = left_array[li]
                ai += 1
                li += 1
                
        # 再次检测, 那个数组的元素没有遍历完, 没有遍历完的顺序添加到nums1后面
        if li < len(left_array):
            nums1[ai:] = left_array[li:]
        if ri < len(nums2):
            nums1[ai:] = nums2[ri:]
```
#### 复杂度分析
时间复杂度: O(m+ n)
空间复杂度:  O(m), 因为需要备份nums1的前m个元素,所以空间复杂度为  O(m)