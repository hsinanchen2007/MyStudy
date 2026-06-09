### 方法1：二分查找解题思路
400ms+
该方法比较常规。简单介绍几本思路如下：
1、确定K上下限为`mink，maxk=1,max(piles)`
2、每一堆piles[i]除k向上取整就是每堆用时，向上取整一个简单的实现是`(piles[i]-1)//K+1`。求和得到特定k的用时总和`eatcost(piles, m)`
3、使用二分查找，判断 `midk=(mink+maxk)//2`的用时总和就能得到`eatcost(piles, midk)`，判断和H的大小关系调整上下限。
### 方法2：数学推导最小上下限
316 ms	14.9 MB
上下限为mink，maxk都没有必要用这么大的值。分析如下 
1、假设每次最大吃K，可知
    `K∈[1，max(piles)]`
2、每一堆至少有一次吃Ki，所以
    `Ki∈[1，k]`
3、剩下的`H-len（piles）`次吃的都是K ，所有堆得Ki的和为∑Ki所以
    `K*(H-len(piles))+∑Ki=sum  `
4、因为`Ki∈[1，k]`，所以 
    `∑Ki∈[len(piles)，k*len(piles)] `
5、所以 
    `sum-K*(H-len(piles))∈[len(piles)，k*len(piles)] `
所以 
    `mink,maxk=(sum(piles)-1)//H+1,min(max(piles),(sum(piles)-len(piles)-1)//(H-len(piles))+1)`
### 方法3：数学库优化
经过实测导入数学库实现向上取整能有效提升效率到180 ms	14.7 MB。实现
`import math`
`math.ceil(piles[i]/K)`

### 代码

```python3
class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        import math
        def eatcost(piles, m):
            rst=0
            for i in piles:
                rst=math.ceil(i/m)+rst
                #方法2#rst=(i-1)//m+1+rst
            return rst
        if len(piles)==H:return max(piles)
        #方法2#else :mink,maxk=(sum(piles)-1)//H+1,min(max(piles),(sum(piles)-len(piles)-1)//(H-len(piles))+1)
        else :mink,maxk=math.ceil(sum(piles)/H),min(max(piles),math.ceil((sum(piles)-len(piles))/(H-len(piles))))
        while mink<maxk:
            midk=(mink+maxk)//2
            if eatcost(piles,midk)<=H:
                maxk=midk
            else:
                mink=midk+1
        return mink
```