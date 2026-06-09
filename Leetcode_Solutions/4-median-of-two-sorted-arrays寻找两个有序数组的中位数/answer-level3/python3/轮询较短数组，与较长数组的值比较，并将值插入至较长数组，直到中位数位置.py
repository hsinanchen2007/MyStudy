如标题，轮询较短的数组的元素A，与较长数组maxnums的元素进行比较，若A小则在maxnums元素位置上插入A，若A较大则找到那个元素比A大，在那个位置插入A，直到中位数位置就停止。
nums1: [-1,2,3]
nums2: [-2,0]
nums1较长,所以maxnums=nums1,minnums=nums2
轮询nums2的内容：
1.如果nums2的元素B比nums1的元素A小，如-2比-1小，就将-2插入到nums1中，此时nums1:[-2,-1,2,3]  
2.如果B比A大，如0比-1大，则轮询-1以后的元素,找比0大的元素,找到比0大的2,就在这个位置上插入0，此时nums1:[-2,-1,0,2,3]

轮询完毕后，计算nums1的中位数，结果是0
此外还要考虑其中一个是空数组的情况，所以在轮询前有一个判断，minnums长度是否为0
以下是python3的上述结果的答案。

```python []
    def findMedianSortedArrays(self, nums1: [int], nums2: [int]) -> float:
        len1 = len(nums1)
        len2 = len(nums2)
        oddEven = divmod(len1 + len2, 2)
        midlen = oddEven[0]  # divmod返回商和余数，偶数的话中位数为商与商+1的均值，奇数则是商+1,不管怎么样，最长都是商+1。但实际操作不用+1,因为数字从0开始
        # 两个数组较长数组maxnums，较短minnums，哪个短轮询哪个，一样长的话哪个第一个元素小就轮询哪个
        if len1 > len2 or len2 == 0:
            maxnums = nums1
            minnums = nums2
        elif len1 < len2 or len1 == 0:
            maxnums = nums2
            minnums = nums1
        else:
            if nums1[0] > nums2[0]:
                maxnums = nums1
                minnums = nums2
            else:
                maxnums = nums2
                minnums = nums1

        j = 0   #maxnums的数组的下标
        if len(minnums) == 0:           #有一个数组是空的话,则直接算另一个数组的中位数
            medienNum = oddEven[1] == 1 and maxnums[midlen] or (maxnums[midlen] + maxnums[midlen - 1]) / 2                       #奇数则取maxnums[midlen],偶数则取两数的均值
        else:
            for i in range(len(minnums)):   #轮询最短的数组
               if minnums[i] <= maxnums[i]:     #A比某位置的值小，则放在该值的左边
                   maxnums.insert(i,minnums[i])
                   j = i + 1
               else:                            #A比某位置的值大，则需要轮询看看哪个位置的值比A大，找到该位置后插入A，同时下一次从这个位置开始
                   j = i
                   while j  < midlen:           #只需看到中位数的位置即可
                       j += 1                   #轮询maxnums里的元素
                       if minnums[i] <= maxnums[j]:
                            maxnums.insert(j,minnums[i])  #在找到比A大的位置插入minnums的元素，插入就退出这里的while进行下一个元素的比较
                            break

            medienNum = oddEven[1] == 1 and maxnums[midlen] or (maxnums[midlen] + maxnums[midlen - 1]) / 2

        return medienNum
```