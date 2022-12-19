### 解题思路
前一个窗口的最大值和现在窗口的最大值其实是有关系的，关系如下：
其实前一个窗口和现在窗口只相差了 左指针指向的数字 和 右指针指向的数字 其他数字都是相等的
所以只需要根据左指针指向的数字 和 新的右指针指向的数字来判断一下是否需要更新最大值即可
分为以下两种情况：
1、首先让右指针+1，如果这时候新右指针指向的值大于了原来的最大值，直接更新，跳到下次循环即可
2、否则，判断左指针是否等于原来的最大值。如果否，很明显最大值位于新窗口和老窗口重叠部分前一次的最大值也是当前的最大值，不需要更新。否则跳至第三步
3、这时候不知道新窗口的最大值是什么，所以需要遍历一次，保存后继续循环即可

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        i,j = 0,0
        if len(nums)==0:
            return []
        max_num = nums[0] # 用一个max_num不断维护当前的滑动窗口的最大值
        results = []
        while j<k:  # 让右指针往前走 顺便找到第一个窗口里最大的
            if nums[j]>max_num:
                max_num = nums[j]
            j+=1
        j-=1    # while最后被多加了1 减回去
        results.append(max_num)
        while j<len(nums)-1:    # 开始滑动窗口
            j+=1
            if nums[j]>max_num: # 如果新的j 大于原来的最大值 直接更新即可
                max_num = nums[j]
            else:   # 否则 只有当左指针刚好等于最大值的时候才要判断 并再找一次最大值
                if nums[i]==max_num:
                    max_num = nums[i+1]
                    for k in range(i+1,j+1):
                        if nums[k]>=max_num:
                            max_num = nums[k]
            i += 1
            results.append(max_num)
        return results
```