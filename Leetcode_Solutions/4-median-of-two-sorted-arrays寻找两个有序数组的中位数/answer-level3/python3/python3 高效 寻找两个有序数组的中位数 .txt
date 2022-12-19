class Solution:
    def findKth(self, list1, list2, k):
        # print(list1, '\t', list2,'\t',k)
        if len(list1) > len(list2):  # trick 1 我们假定 list1一定小于list2 这样的话只可能是list1先空，所以终止条件只用判断一次
            return self.findKth(list2, list1, k)
        if len(list1) == 0:
            return list2[k-1]
        if k == 1:
            return min(list1[0], list2[0])
        pos_1 = min(len(list1)-1, k//2-1)   # trick 2 数字下标取到的最大长度，大不了多判断一次，就不用判断数组是否结束了
        pos_2 = min(len(list2)-1, k//2-1)  # 坑点，一直在这个地方卡住了，下标和数目要！转换
        if list1[pos_1] > list2[pos_2]:    
            return self.findKth(list1, list2[pos_2+1:], k-pos_2-1)
        else:
            return self.findKth(list1[pos_1+1:], list2, k-pos_1-1)

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        len_1 = len(nums1)
        len_2 = len(nums2)
        lower = (len_1+len_2+1)//2  # 14, 7,8  15,8,8
        upper = (len_1+len_2+2)//2 
        return (self.findKth(nums1,nums2,lower) + self.findKth(nums1,nums2,upper)) / 2
