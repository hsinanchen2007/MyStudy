### 动态规划
执行用时 :
44 ms
, 在所有Python3提交中击败了
95.28%
的用户
内存消耗 :
13.1 MB
, 在所有Python3提交中击败了
79.31%
的用户

```
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        a = min(m,n)
        b = max(m,n)
        count = b+a-1
        target = [0 for i in range(a)]
        target[0] = 1
        for i in range(count-1):
            for j in range(a-1,0,-1):
                target[j] += target[j-1]
        return target[-1]
        
```

### 排列组合
执行用时 :
48 ms
, 在所有Python3提交中击败了
90.43%
的用户
内存消耗 :
12.8 MB
, 在所有Python3提交中击败了
98.71%
的用户

```
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        a = min(m,n)
        b = max(m,n)
        count = b+a-2
        x,y =1,1
        for i in range(a-1):
            x *=(i+1)   
        for j in range(a-1):
            y *= (count-j)
        return y//x
```

