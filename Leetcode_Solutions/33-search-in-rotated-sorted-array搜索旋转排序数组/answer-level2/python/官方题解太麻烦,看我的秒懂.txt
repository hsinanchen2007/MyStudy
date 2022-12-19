官方方法是找旋转分界点，不过其实不需要
如下图所示，红色标记指代数据点，则旋转后的有序数组必然由两段上升序列构成，并且大于nums[0]的点都在左边的那段序列上，小于nums[0]的点都在右边那段序列上。
![IMG_FB8CBF67C59E-1.jpeg](https://pic.leetcode-cn.com/01d3b2cb97db22c7e1b91b4a8dad834af6b9776866d98a03e898680745f656f0-IMG_FB8CBF67C59E-1.jpeg)
图中蓝色方形是target所在数据点，可以看出，当nums[mid]小于target的时候，如果mid在第一条序列，则target应该在mid的右边，如果mid在第二条序列，则target应该在mid的左边。于是，我们可以根据nums[0]、nums[mid]、target三者的大小关系来判断应该改变二分区间的left还是改变right，一共八种关系，如下表
![截屏2020-03-29下午1.14.50.png](https://pic.leetcode-cn.com/3ecbd90dcc7e062db7ac8b74157e82be3f13ce8aff8d2184d5f02fc6de254f77-%E6%88%AA%E5%B1%8F2020-03-29%E4%B8%8B%E5%8D%881.14.50.png)
建议自己动手画出这八种关系以加深理解。
```
class Solution(object):
    def search(self, nums, target):
        l=0
        r=len(nums)-1
        while l<=r:
            mid=(l+r)//2
            if nums[mid]==target:return mid
            p1=target>=nums[0]              #用几个变量保存关系的布尔值，看着多舒服，何必写一堆if else
            p2=nums[mid]>target
            p3=nums[mid]>=nums[0]
            if (p1 and not p2 and p3)or(not p1 and not p2)or(not p1 and p2 and p3):
                l=mid+1
            else:
                r=mid-1
        return -1
```
