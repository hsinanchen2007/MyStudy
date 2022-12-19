### 解题思路 最大值在前面被划走，或者最大值是新划过来的那个，大于当前的最大值，需要变更
此处撰写解题思路

### 代码

```python

# -*- coding:utf-8 -*-
class Solution:
    def maxSlidingWindow(self, num: List[int], size: int) -> List[int]:
        # write code here
        if size <= 0 or len(num) == 0 or len(num)<size:
            return []
        
        else:
            ans = []
            Max = max(num[0:size])
            ans.append(Max)
            cur_last = size
            previous_first = 0
            if (len(num)==size):
                return ans
            for i in range(1, len(num) - size + 1):
                if Max == num[previous_first]: #aaaaaa num[]...
                    Max = max(num[previous_first+1:cur_last+1])
                if Max < num[cur_last]:
                    Max = num[cur_last]
                ans.append(Max)
                cur_last += 1
                previous_first+=1
            return ans

```

### 单调栈
```python
# -*- coding:utf-8 -*-
class Solution:
    def maxSlidingWindow(self, num: List[int], k: int) -> List[int]:
        window ,res = [],[]
        for i in range(len(num)):
            while window and num[window[-1]]<num[i]: #why =,面试题59-II队列最大值好像没有等号,有没有等号皆可以
                window.pop()
            window.append(i)
            if window[0] == i-k:#已超出窗口左端，过时数据丢弃
                window.pop(0)
            if i >=k-1:#要从第k个数据开始输出答案，前面冷启动准备阶段
                res.append(num[window[0]])
        return res
```