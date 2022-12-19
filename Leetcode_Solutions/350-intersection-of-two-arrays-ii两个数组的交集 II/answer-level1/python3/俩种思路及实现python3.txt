```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #方法1，双指针法，进行俩个数组的遍历，当然，首先先对原数组进行sort排序
        index1=0
        index2=0
        nums1.sort()
        nums2.sort()
        newlist=[]
        while index2<len(nums2) and index1<len(nums1):
            if nums1[index1]<nums2[index2]:
                #不能删除某个数组元素
                index1+=1
            elif nums1[index1]>nums2[index2]:
                index2+=1
            else:
                newlist.append(nums2[index2])
                index1+=1
                index2+=1

        return newlist


        ##方法2也可行，不过在运行速度上逊色于上面方法，特别是in 判断（这个是借鉴别人的方法啦）
        # n=len(nums1)
        # nums=[]
        # for i in range(n):
        #     if nums1[i] in nums2:
        #         nums.append(nums1[i])
        #         nums2.remove(nums1[i])
        # return nums
```


 方法1:
![783BC947E711F7443463087EC3E7D37A.png](https://pic.leetcode-cn.com/68f91df03c5b97a56d5b2c2fd27594ca8565a9258487e4efcac3f863c9f36f27-783BC947E711F7443463087EC3E7D37A.png)

方法2:
![E86EAAF8FE0898D3B4E0D8869358DC2D.png](https://pic.leetcode-cn.com/9d7fb42dadd8ac55407a41224a6e38559f30ece35da847712339254e2981e1d5-E86EAAF8FE0898D3B4E0D8869358DC2D.png)


