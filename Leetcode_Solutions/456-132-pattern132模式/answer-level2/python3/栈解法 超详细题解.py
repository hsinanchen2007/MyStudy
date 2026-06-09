# 456. 132模式

***

## M1: 栈

问题是在一个整数序列中，有没有一个子序列符合 ai < ak < aj, 其中 i<j<k

所以可以把问题转化成，找到一个元素 aj, 在区间[1, j-1]里有比他小的元素M1，在区间[j+1, n]里也有比他小的元素M2, 并且M2>M1

![132.png](https://pic.leetcode-cn.com/feb1ddb4b70c7144da7d56db10d36ec822ab374ef27f99a16f970ce34ba085f2-132.png)


所以这里需要让M1尽可能小，所以第一步就是维护一个最小前缀值的数组，即aj对应的最小M1

```
mi = [nums[0]]
for i in range(1, le):
    mi.append(min(nums[i], mi[-1]))
```

因为有了前缀最小值，所以我们可以很快判断aj和M1的关系，接下来的任务就是找M2。
首先可以想到暴力解，遍历[j+1]到n的每一个数，时间复杂度是O(n^2)，那么有什么办法可以优化这部分，我们可以从数组尾部开始向前维护一个单调递减栈，对于每一个aj，如果aj>M1，然后在当前栈中找比M1大的最小值，即以M1为最小标准值来维护这个递减栈之后的栈顶元素，如果栈顶元素小于aj，即找到我们所需要的情况

```
stack = []
for i in range(le-1, -1, -1):
    if nums[i]>mi[i]:
        while stack and mi[i]>=stack[-1]:
            stack.pop()
        
        if stack and stack[-1]<nums[i]:
            return True
        stack.append(nums[i])

```
#### 为什么以M1为最小值维护栈不会对后续造成影响

```
while stack and mi[i]>=stack[-1]:
    stack.pop()

```

我们先看看最小前缀值数组有什么特征，很容易得出它是一个非递增数组，
后面的元素都小于或等于当前元素，所以如果当前栈里的元素小于 aj 对应的M1，那么肯定也小于a[j-1] 到a[1]对应的M1，所以直接出栈即可。

#### 为什么最后可以直接入栈

```
    stack.append(nums[i])
    
```
在上一步以M1维护栈之后，栈里的元素都是大于M1，此时如果栈顶的最小值小于nums[i],就已经找到我们要的情况，否则的话栈内元素都是大于nums[i]的，直接把nums[i]推进栈，不影响递减。


### 完整代码

```
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        le = len(nums)
        if le<2: return False

        mi = [nums[0]]
        for i in range(1, le):
            mi.append(min(nums[i], mi[-1]))
        
        stack = []
        for i in range(le-1, -1, -1):
            print(stack)
            if nums[i]>mi[i]:
                while stack and mi[i]>=stack[-1]:
                    stack.pop()
                
                if stack and stack[-1]<nums[i]:
                    return True
                stack.append(nums[i])
        return False

```