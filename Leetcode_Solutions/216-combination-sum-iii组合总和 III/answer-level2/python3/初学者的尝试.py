### 解题思路
与组合求和之前的几个类似，需要注意的是这次加上了个数的限定
### 代码

```python
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        answer=[]
        def trackback(path,summ,index):
            if summ == n and len(path)==k :#既满足值又满足个数
                answer.append(path)
                return 1
            if summ > n:
                return 1
            if len(path) == k:#个数已经到了，如果继续个数会超
                return 
            if summ < n:
                for i in range(index,10):
                    flag = trackback(path+[i],summ+i,i+1)
                    if flag: 
                        break
        trackback([],0,1)
        return answer
```