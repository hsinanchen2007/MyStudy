### 解题思路
<1.两数之和> 的升级版，与<18.四数之和>、<16.最接近的三数之和>、<259最小的三数之和>相近。
#### 左右指针所指向元素与当前元素之和
#####1.special case：
`len(nums)<3:return []`
##### 2.数组排序：
`nums.sort()`
##### 3.遍历sorted数组:
当前元素:`i`
L指针初始化：`i+1`
R指针初始化：`len(nums)-1`
当`L<R`时移动L/R指针：
1）若`nums[i]+nums[L]+nums[R]>0`时，值偏大，通过左移R使加和减小；
2）若`nums[i]+nums[L]+nums[R]<0`时，值偏大，通过右移L使得和增大；
3）若加和正好为0，记录当前取值，并向中间移动指针（若要移动方向的值和当前元素的值相等，则要继续移动）。
遍历中的special case:
`if nums[i]+nums[-1]+nums[-2]<0: continue #若与最大的元素相加后仍小于0，需遍历下一元素`
`if nums[i]+nums[i+1]+nums[i+2]>0:break#当前元素与相邻的两个元素相加仍大于0。则说明后面的加和都大于0，直接返回`


当前元素向前移动时也要注意相邻元素相等，则跳过下个元素，搜索下下个元素。


### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        #1.两数之和的升级版->18.四数之和
        #特殊情况：数组长度不足3，返回[]
        if len(nums)<3:return []
        res=[]
        #对数组排序
        nums.sort()
        #初始左指针为当前元素的右元素，右指针为最后一个元素
        for i in range(n-2):#3数之和，最后两个元素不用遍历
            if nums[i]+nums[-1]+nums[-2]<0: continue #若与最大的元素相加后仍小于0，需遍历下一元素
            if nums[i]+nums[i+1]+nums[i+2]>0:break#当前元素与相邻的两个元素相加仍大于0。则说明后面的加和都大于0，直接返回
            if i>0 and nums[i]==nums[i-1]:continue #排除重复元素
            L,R=i+1,n-1#初始左/右指针
            while L<R:#移动左右指针，值大R向左移，值小L向右移
                if nums[i]+nums[L]+nums[R]>0:
                    R-=1
                elif nums[i]+nums[L]+nums[R]<0:
                    L+=1
                else:#正好三元素值和为0
                    res.append([nums[i],nums[L],nums[R]])#添加结果
                    while L<R and nums[L]==nums[L+1]:#左指针右移时排除重复元素
                        L+=1
                    while L<R and nums[R]==nums[R-1]:#右指针左移时排除重复元素
                        R-=1
                    L+=1#向中间（结束条件）靠拢
                    R-=1
        return res
            
```