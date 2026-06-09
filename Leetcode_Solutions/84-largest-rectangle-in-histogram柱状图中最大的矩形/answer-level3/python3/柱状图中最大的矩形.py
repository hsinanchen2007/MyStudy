```
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        #这个地方容易出错，为什么要加个0呢？因为我们希望所有的栈内元素都出栈
        heights.append(0)
        h = heights
        #递增栈
        stack = []
        #初始值
        res = 0
        
        for i, values in enumerate(h):
            while stack and values < h[stack[-1]]:
                remove_val = stack[-1]
                #stack要弹出最高值
                stack.pop(-1)
                if stack == []:
                    begin = 0
                else:
                    begin = stack[-1]+1
                res = max(res, h[remove_val]*(i-begin))
            stack.append(i)
        return res
```       
在这里我只写了代码，关于怎么样的思考过程，可以搜索其他的博客。