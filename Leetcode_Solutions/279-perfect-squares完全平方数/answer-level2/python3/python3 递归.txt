### 解题思路
用尽了一切方法总算没超时了。。。。

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        #先找出n以内的完全平方数
        list_ = []
        i = 1
        while i ** 2 <= n:
            list_.append(i**2)
            i += 1
        used_dict = {}
        #接下来就是怎么填满这个n
        #可以重复使用，怎么办，看来只能每个值都试一遍递归了。把一个问题不断向下细分
        def find_min(n,i):
            #寻找剩余大小n，使用最大数为list_[i]时的最少个数
            if (n,i) in used_dict:
                return used_dict[(n,i)]
            if list_[i] > n:
                return find_min(n,i-1)
            a,b = divmod(n,list_[i])
            res  = float('inf')
            if b == 0:
                return a
            #如果还有剩
            for j in range(i-1,-1,-1):
                temp = a + find_min(b,j)
                res = min(temp,res)
            used_dict[(n,i)] = res
            return res
        
        res = float('inf')
        for i in range(len(list_)-1,-1,-1):
            res = min(res,find_min(n,i))
            if res == 1:
                return res
            if res == 2:
                return res
        return res
                
```