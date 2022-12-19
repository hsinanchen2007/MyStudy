# 1. 思路

- 利用双端队列
- 要点：
  - 确保队列的队首为当前窗口的max；
  - 如果队首在窗口之外，则弹出窗口；
  - 每遍历到新元素时，都需要和队尾元素比较；
    - 队尾 < 新元素：去队尾，直到队尾不小于新元素
    - 否则，直接将新元素添加到队尾



| nums | 1    | 3                                     | -1   | -3      | 5                                                           | 3    | 6    | 7    |
| ---- | ---- | ------------------------------------- | ---- | ------- | ----------------------------------------------------------- | ---- | ---- | ---- |
| res  |      |                                       | 3    | 3       | 5                                                           | 5    | 6    | 7    |
| tmp  | 1    | 3                                     | 3,-1 | 3,-1,-3 | 5                                                           | 5,3  | 6    | 7    |


- index = 1时：新元素3 > 队尾1，则去队尾，加入新元素
- index = 4时：队首在窗口之外，先弹出队首。新元素5再和[-1,-3]的队尾比较... 





```
#!/usr/bin/python
# -*- coding: utf-8 -*-

import collections

def maxSlidingWindow(nums, k):
	tmp = collections.deque()
	res = []
	for i, t in enumerate(nums):
		if tmp and (i - tmp[0]) >= k:
			tmp.popleft()
		while tmp and nums[tmp[-1]] < t: 	
			tmp.pop()

		tmp.append(i) 
		if i >= (k-1):
			res.append(nums[tmp[0]])
		print(i, tmp, res)
	return res

nums = [1,3,-1,-3,5,3,6,7]
k = 3

nums = [1,-1]
k = 1

res = maxSlidingWindow(nums, k)
print(res)
```

