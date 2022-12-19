### 解题思路
与<15.三数之和>类似，采用双指针+遍历方法。只不过在<15三数之和>那采用一遍遍历+双指针，在这采用双指针加两遍遍历。
#### 1.special case:
`if len(nums)<4: return []`
#### 2.对数组排序：
`nums.sort()`
#### 3.进行两次遍历：
外层遍历看作是指向当前元素(0<=i<n-3);
内层遍历看作是指向下一元素(i+1<j<n-2);
L指针初始指向下一元素j的右边元素`L=j+1`;
R指针初始指向最后一个元素`R=n-1`.

在遍历时有special cases:
1）在外层扫描（当前元素nums[i]）时:
*若nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target,说明nums[i]之后的加和必定比target大，直接返回；
*若nums[i]+nums[-1]+nums[-2]+nums[-3]<target,说明num[i]与最大的三个数相加仍不满足要求，需尝试nums[i+1]；
2）在内层扫描时（下一元素num[j]）时，固定当前元素nums[i]：
*若nums[i]+nums[j]+nums[j+1]+nums[j+2]>target,说明在nums[j]之后的加和必定比target大，直接返回；
*若nums[i]+nums[j]+nums[-1]+nums[-2]<target,说明num[j]与最大的数相加仍不满足要求，需尝试nums[j+1]；

当加和小于target时，L指针右移；加和大于target时，R指针左移。
在移动过程中注意排除重复元素。



### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        #和15.三数之和相似，使用双指针
        #1.special case:
        if len(nums)<4:return [] 
        #2.数组排序
        nums.sort()
        #3.遍历数组，L/R/i
        res=[]
        for i in range(len(nums)-3):#4数之和：对于当前元素->最后3个数不需要遍历
            #若与i相邻的4数之和大于target，则所有的i与之后的和都比target大,返回
            if nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target: break
            #若i与最后3个数之和小于target，则当前的i与之的和都比target小，直接向下搜寻
            if nums[i]+nums[-1]+nums[-2]+nums[-3]<target:continue#排除相同元素
            if i>0 and nums[i]==nums[i-1]:continue
            for j in range(i+1,len(nums)-2):#4数之和：对于下一元素->最后两个元素不需要遍历
                #若与i相邻的4数之和大于target，则所有的i与之后的和都比target大,返回
                if nums[i]+nums[j]+nums[j+1]+nums[j+2]>target: break
                #若i与最后3个数之和小于target，则当前的i与之的和都比target小，直接向下搜寻
                if nums[i]+nums[j]+nums[-1]+nums[-2]<target:continue
                if j>i+1 and nums[j]==nums[j-1]:continue#排除相同元素
                L=j+1
                R=len(nums)-1
                while L<R:
                    if nums[i]+nums[j]+nums[L]+nums[R]>target:R-=1
                    elif nums[i]+nums[j]+nums[L]+nums[R]<target:L+=1
                    else:
                        res.append([nums[i],nums[j],nums[L],nums[R]])
                        while L<R and nums[L]==nums[L+1]:L+=1
                        while L<R and nums[R]==nums[R-1]:R-=1
                        L+=1
                        R-=1
        return res
```