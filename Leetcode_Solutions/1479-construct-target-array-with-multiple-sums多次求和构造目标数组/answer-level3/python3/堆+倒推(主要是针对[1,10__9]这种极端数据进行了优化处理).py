**思路**:和题解的各位大佬都差不多 详情可见 => [MrYx大佬的题解](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/solution/zhao-gui-lu-dao-tui-zui-xiao-dui-you-hua-python3-c/)
**注意**:最近应该是数据集变了 所以有些题解的代码现在已经AC不了 我一开始基本上和上述链接第一种完全一样 但[1,10*9]一直超时 所以考虑了如何优化 本人菜鸡 优化部分和主要的语句都添加了注释 还请各位多多指教
```
"""
[9, 5, 3]
9 => [1, 5, 3]
5 => [1, 1, 3]
3 => [1, 1, 1]

[8, 5]
8 => [3, 5]
5 => [3, 2]
3 => [1, 2]
2 => [1, 1]

[1, 1000000000]
1000000000 => [1,1] ※ ∵2*sum(1,1000000000)-1000000000>=1 ∴new=1000000000%1 or 1
"""

import heapq
def isPossible(target):
	total=sum(target)
	target=[-i for i in target] #heapq默认的是小根堆 这边正数->负数就相当于变成了一个大根堆
	heapq.heapify(target) #将target堆化
	while True:
		max=-heapq.heappop(target) #这边最大值是一个正数
		if max==1: #边界条件 说明target里面全都是-1/1了
			return True
		if 2*max-total<1: #同样也是一个边界条件 出现了不应该出现的数值
			return False
		sub=total-max #就是为了应对类似[1,1e9]这种相当极端的情况的 sub表示除max以外所有数字的和
		new=max%sub or sub #能减就减所以用% 但同时能整除的情况下是不能直接new=0的 所以会有or sub
		total-=max-new #记得更新total
		heapq.heappush(target,-new)
```

