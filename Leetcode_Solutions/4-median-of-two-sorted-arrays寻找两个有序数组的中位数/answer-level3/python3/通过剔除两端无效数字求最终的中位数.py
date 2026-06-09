
原本第一想法是把第二个列表按顺序插进第一个列表中，然后取中位数，如下。
```
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        i=0
        j=0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]>nums2[j]:
                nums1.insert(i,nums2[j])
                i+=1
                j+=1
            else:
                i+=1
        if i==len(nums1):
            for item in nums2[j:len(nums2)]:
                nums1.append(item)
            #此时nums1为有序列表，求nums1的中位数
        if len(nums1)%2:
            return nums1[int((1+len(nums1))/2-1)]
        else:
            return (nums1[int(len(nums1)/2)]+nums1[int(len(nums1)/2-1)])/2
```

虽然也能通过测试，但需要遍历两个列表，不满足复杂度的要求。
看了社区里的多个解法后，有了以下思路。
每次分别找两个列表中的中位数，删除小的中位数之前的元素与大的中位数之后的元素，但要保证两个列表中删除的元素相同，此时合并后的列表中位数不会发生变化。
接下去就考虑极限情况即可。代码如下：

```
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        #把元素少的数组放在nums1
        if len(nums1)>len(nums2):
            nums1,nums2=nums2,nums1
        #极限情况，若只有这么一点点数的话不需要剔除，直接求中位数
        if len(nums1)<=2 and len(nums2)<=4 or nums1==[] or nums2==[]:
            list01=[]
            for i in nums1:
                list01.append(i)
            for i in nums2:
                list01.append(i)

        #数字太多的话用类似二分法剔除两端无效的数
        else:
            self.devide(nums1, nums2)
            if len(nums1) > len(nums2):
                nums1, nums2 = nums2, nums1
            if len(nums2)<=4:
                list01 = []
                for i in nums1:
                    list01.append(i)
                for i in nums2:
                    list01.append(i)
            else:
                list01=[]
                if len(nums1)==1 and not len(nums2)%2:
                    list01 = [nums1[self.get_mid(nums1)[0]], nums2[self.get_mid(nums2)[0]], nums2[self.get_mid(nums2)[1]],nums2[self.get_mid(nums2)[0] - 1], nums2[self.get_mid(nums2)[1] + 1]]
                elif len(nums1)==1 and len(nums2)%2:
                    list01 = [nums1[self.get_mid(nums1)[0]], nums2[self.get_mid(nums2)[0]],nums2[self.get_mid(nums2)[0] - 1], nums2[self.get_mid(nums2)[1] + 1]]
                elif len(nums1)!= 1 and len(nums2) % 2:
                    list01 = [nums1[self.get_mid(nums1)[0]], nums1[self.get_mid(nums1)[1]],nums2[self.get_mid(nums2)[0]],nums2[self.get_mid(nums2)[0] - 1], nums2[self.get_mid(nums2)[1] + 1]]
                elif len(nums1)!=1 and not len(nums2)%2:
                    list01=[nums1[self.get_mid(nums1)[0]],nums1[self.get_mid(nums1)[1]],nums2[self.get_mid(nums2)[0]],nums2[self.get_mid(nums2)[1]],nums2[self.get_mid(nums2)[0]-1],nums2[self.get_mid(nums2)[1]+1]]
        list01.sort()#此时最多6个数字排序
        return self.get_res(list01)

    def get_mid(self,nums1):#求中位数的索引值，以元祖形式（x,y)返回,奇数则x=y
        if len(nums1) % 2:
            return int((1+len(nums1))/2-1),int((1+len(nums1))/2-1)
        else:
            return int(len(nums1)/2-1),int((len(nums1)/2))


    def devide(self,nums1,nums2):#用递归的方法剔除无效数字
        if nums1[self.get_mid(nums1)[0]]<=nums2[self.get_mid(nums2)[1]]:
            if self.get_mid(nums1)[0]<=len(nums2)-self.get_mid(nums2)[1]-1:
                for i in range(self.get_mid(nums1)[0]):
                    nums1.pop(0)
                    nums2.pop()
            else:
                for i in range(len(nums2)-self.get_mid(nums2)[1]-1):
                    nums1.pop(0)
                    nums2.pop()
            if len(nums1)<=2 or len(nums2)<=2:
                return
            else:
                self.devide(nums1,nums2)
        else:
            self.devide(nums2, nums1)

    def get_res(self,list01):#定义一个求中位数的函数
        return (list01[self.get_mid(list01)[0]] + list01[self.get_mid(list01)[1]]) / 2
```
