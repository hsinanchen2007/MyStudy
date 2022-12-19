### 解题思路
此处撰写解题思路
超时了好几次，先想到，到达第k个的时候后面不继续下去了第一个剪枝，后来想到就是去除前面的没必要的回溯剪枝
例如

"123"
"132"
"213"
"231"
"312"
"321"

n=3,k=3

先选择1，之后有 (n-1)! 个选择，如果k大于(n-1)! ,那么这里的都不进行回溯了，跳过，同时  k-=(n-1)!
最后判断那个ans的个数等于剩下的k的个数，输出最后一个就是答案了。
时间不怎么快，48ms，不知道哪里还可以优化，可以交流一下。

### 代码

```python3
import functools
import operator
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []        
        a = [str(i) for i in list(range(1,n+1))]
        def factorial(n):
            return functools.reduce(operator.mul,range(1,n+1))
        self.f = k
        def helper(a,res):
            if not a:
                ans.append(''.join(res))
            
            for i in range(len(a)):
                d = factorial(len(a)-1) if len(a)>1 else 1
                if self.f>d:                    
                    self.f-=d
                    # print(d,len(a),self.f)
                    continue
                helper(a[:i]+a[i+1:],res+[a[i]])
                if len(ans)==self.f:
                    break
        
        # print()
        res = []
        helper(a,res)
        print(k,ans)
        return ans[-1]
```