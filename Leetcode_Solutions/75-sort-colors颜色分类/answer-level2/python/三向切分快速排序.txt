### 解题思路
主要思路就是：遇见元素是2就往后放，是0就往前放
有三个指针，分别指向待填放0的位置（初始化时指向数组的首段）、待填方2的位置（初始化时指向数组的末端），和当前待判断的位置（初始化时指向0位置）

依次遍历数组，如果当前位置是2，就把当前位置与待填放2的位置上的元素互换，然后待填放2的位置向左移动一步；
如果当前位置是0，则与待填放0的位置上的元素进行互换，当前位置和待填放0的位置，都向右移动一步，因为之前待填放0的位置上面的元素一定是1。
如果当前位置是1，则直接向右移动一步；
注意结束的时候，判断依据是当前位置已经超过待填放2的位置，因为待填放2的位置不一定已经填放了2



### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        RedPnt=0
        WitPnt=0
        BluPnt=len(nums)-1
        while RedPnt<=BluPnt:
            if nums[RedPnt]==2:
                nums[RedPnt],nums[BluPnt]=nums[BluPnt],nums[RedPnt]
                BluPnt-=1
            elif nums[RedPnt]==0:
                nums[RedPnt],nums[WitPnt]=nums[WitPnt],nums[RedPnt]
                WitPnt+=1
                RedPnt+=1
            else:
                RedPnt+=1

```