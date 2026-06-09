表达不好，多担待
思路：
    对数据nums进行排序，然后进行去重nums2并排序，对nums2中元素进行遍历
    获取nums2[i]元素和nums2[i+1]元素在nums中对应的下标index1,index2，进行相减index2-index2，
    则是元素nums2[i]在nums中出现的次数，与nums/2相比较
    注意对nums2中最后一个元素进行处理，index2为nums的长度
```
    nums = sorted(nums)
    length = len(nums)
    nums2 = sorted(list(set(nums)))
    for i in range(len(nums2)):
        index1 = nums.index(nums2[i])
        index2 = nums.index(nums2[min(i+1, len(nums2)-1)])
        if i == (len(nums2)-1):
            index2 = len(nums)
        if (index2 - index1) > length/2:
            return nums2[i]
```
![image.png](https://pic.leetcode-cn.com/b9fcbe689df9712d1dbe9502e7cf64ae57db00933772417e288306e091adabc1-image.png)

