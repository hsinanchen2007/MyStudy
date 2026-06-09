### 解题思路
方法：堆
*  collections库中的Counter函数用于统计字符出现个数，如：'a':2,表示a出现两次。讲解：https://www.liaoxuefeng.com/wiki/897692888725344/973805065315456
* lambda x:Jihe(x) 冒号前x表示键也就是上面的a，Jihe[x]表示输出的值，也就是上面的次数2。Jihe这个是随便取得名字
* 用heapq.nlargest（k,Jihe）输出集合中的第k个最大值
### 代码

```python
class Solution(object):
    def topKFrequent(self, nums, k):
        from collections import Counter
        from heapq import nlargest
        Jihe = Counter(nums)
        return heapq.nlargest(k,Jihe,key=lambda x:Jihe[x])
        

```