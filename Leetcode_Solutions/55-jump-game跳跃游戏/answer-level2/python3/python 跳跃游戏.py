方法一：逆向跳跃，申请一个数组，从尾部开始判断，超时。
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lenk=len(nums)
        if lenk==1:return True
        p=[False for _ in range(lenk-1)]
        for i in range(-1,-lenk,-1):
            if nums[:-1][i]>=-i:
                p[i]=True
                continue
            if p[i+1]==False and nums[:-1][i]-nums[:-1][i+1]<2:
                p[i]=False
            if p[i+1]==False:
                for j in range(1+nums[:-1][i+1],nums[:-1][i]+1):
                    if p[i+j]==True:
                        p[i]=True
                        break
            else:
                for j in range(1,nums[:-1][i]+1):
                    if p[i+j]==True:
                        p[i]=True
                        break
        # print(p)
        return p[0]
                
```
方法2：也是我经常使用的一种方法，第一个节点能调到哪，设为max，然后循环max之内的数，循环过程中能跳的最远的，替换max，然后原来的max变为premax，然后遍历premax到max中跳的最远的，然后还是这么交替的变premax和max，最后当重合或者max超过最后一个元素的时候判断为True，当重合并且小于元祖最后元素的时候返回False
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lenk=len(nums)
        if lenk==1:return True
        premax=0
        max=nums[0]
        while premax!=max:
            if max>=lenk-1:return True
            imax=max
            for i in range(1,imax-premax+1):
                if nums[premax+i]+i+premax>max:max=nums[premax+i]+i+premax
            premax=imax
        if max>=lenk-1:return True
        return False
                
```
![image.png](https://pic.leetcode-cn.com/222636f1eedfc79509f0aaff7d7f8340d4310be3132e35d2df7079f7c1569a4f-image.png)
