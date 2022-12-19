### 解题思路
利用递归的方法：找到截止条件；当前层逻辑；到下一层

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
        def _generate(left, right, n,s):
            if(left==n and right==n):
                result.append(s)
                return
            if(left<n):
                _generate(left+1,right,n,s+'(')
            if(right<n and left>right):
                _generate(left,right+1,n,s+')')
        result=[]
        _generate(0,0,n,'')
        return result

```