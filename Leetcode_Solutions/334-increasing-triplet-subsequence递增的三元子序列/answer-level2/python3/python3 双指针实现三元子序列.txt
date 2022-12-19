# 思路
首先，我们先排除边界情况，也就是说数组长度不足3时的情况
```
if len(nums)<3:return False
```
第二步，我们初始化两个指针，low和mid
```
low, mid = float('inf'),float('inf')
```
注意，这里的low不一定是最终输出对应序列的low值
第三步是算法的核心，先上代码，然后分析思路
for i in nums:
        if i <= low:low = i
        elif i <= mid: mid = i
        else: return True
return False
```
我们每一次维护最小值low若是出现更小的low将其替换，但是如果遇到[2,3,1,4]这种情况怎么办，没关系，我们可以靠mid来获取，mid不光保存了中间值，还说明数组前面有一个值比它更小，所以我们找到high就可以返回true了
