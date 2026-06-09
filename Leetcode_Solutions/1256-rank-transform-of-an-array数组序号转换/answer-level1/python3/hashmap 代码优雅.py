非常优雅有木有！！
先用集合去重，再转为list，然后调用排序函数
最后用hashmap映射出转化后的序号
```
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        hashmap={}
        L=sorted(list(set(arr)))
        for i,element in enumerate(L):
            hashmap[element]=i+1
        return [hashmap[i] for i in arr]
```
![TIM截图20200126002426.png](https://pic.leetcode-cn.com/ba6ee0a659a04e1d1c9015063db1f3da4e47e85f8a8024b955debde493040fc4-TIM%E6%88%AA%E5%9B%BE20200126002426.png)
