![image.png](https://pic.leetcode-cn.com/51c72d757cf22005bb25c2a35fa2db3ca2f64a23c83b15ed429aed45e4aa05bf-image.png)

解法一： 
对于n有两种情况:
一种是n-1的每种情况外面括号。 比如 （（）（））是（）（）外面加括号
另一种是a,和n-a的情况的组合。比如（（））（（））就是（（））和（（））的组合。
因此可以用递归完成上述思路。
这种由于有重复，每次要判断重复，所以时间复杂度很高。
```
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n <=0:
            return [""]

        ans =[]

        for i in self.generateParenthesis(n-1):
            ans.append("(" + i + ")")
        
        for i in range(1,n):
            for a in self.generateParenthesis(i):
                for b in self.generateParenthesis(n-i):
                    if a+b not in ans:
                        ans.append(a+b) 
        return ans
```

解法二： 
f(n)比f(n-1)多一组括号。多出来的一组在哪里呢？
我们把f(n-1)拆成f(a)和f(n-1-a)的两类的组合。其中a可以是0到n-1的任何一个.
由于左面部分(f(a))由括号框起来的部分各不相同，所以最终结果不会有重复，不需要去重
为编程简便，直接用递归完成上述思路。


```
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans =[]
        if n <=0:
            return [""]
        for i in range(0,n):
            for a in self.generateParenthesis(i):
                for b in self.generateParenthesis(n-1-i):
                    ans.append("("+a+")"+b) 
        return ans
```
改成循环后
```
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans =[[""]]
        if n <=0:
            return [""]
        for j in range(1,n+1):
            ans.append([])
            for i in range(0,j):
                for a in ans[i]:
                    for b in ans[j-1-i]:
                        ans[j].append("("+a+")"+b) 
        return ans[n]
```
最后吐槽一下，同样的程序，提交两次的时间和内存都有变化。这样的排名有点名不符实。希望可以优化一下。