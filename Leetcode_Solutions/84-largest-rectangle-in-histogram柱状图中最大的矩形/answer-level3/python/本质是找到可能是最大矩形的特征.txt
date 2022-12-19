这道题的难点在于高度较小的矩形是可以左右延伸的，所以只要不到最后一个，你就永远无法确定你现在找到的最大的area有没有前面联通的“地道”面积大 
例如本题示例的图我完全可以把1再延伸十个一百个，同理  我可以同时构造多个地道，但地道所共有特征是结尾必须是最后一个end
![1.JPG](https://pic.leetcode-cn.com/0b6d27e74d906393f29ee5b2526490d746086c59573fa375e4f8c1bd9fedbbd7-1.JPG)

所以问题就转化为求出矩阵集合中那些可以延伸到end的面积（不止一个）集合以及没有延伸到end的area，后面这部分很显然在遍历矩阵集的时候可以不断更新。
那么我们如何找到能延伸到end的height呢，观察一下就会发现只要高度递增或不变就可以延伸下去。
所以只要h增加便入栈,为了方便计算面积我把这个高度的起始位置index构成【i，h】一起入栈,否则当（heights[i]>stack[-1]）开始循环出栈，一直到栈顶小于等于heights[i],并且把最后出栈的高度的起始位置赋给【index，heights[i]】,以上图中的2为例，2的index应该是5的位置而不是2的位置
每次出栈都意味着这个高度的结尾不是end，所以第一个问题也解决了，只要max（）比较更新一下就好了
顺便说一下  用python写的就不要想着暴力啦，我好多是优化的暴力思想但是都过不了。。
以下是代码
```
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []#每次出现更大的h 入栈  减小则与maxeara比较并出栈
        L = len (heights)
        if L==0:return 0
        stack.append([0,heights[0]]);maxeara = heights[0]
        for i in range(1,L):
            index = i#一般index=i  出现需要向左延伸的情况 更新index
            if stack and stack[-1][1] > heights[i]:#栈不为空且开始递减了
                while stack!=[] and stack[-1][1] > heights[i]:
                    maxeara = max( maxeara, stack[-1][1]*(i-stack[-1][0]) )#更新maxeara
                    index = stack.pop()[0]#左滑的过程
                #走出循环  新高度新index入栈
            stack.append([index,heights[i]])
        
        for item in stack:#结尾时end的矩阵比大小
            maxeara = max(maxeara,item[1]*(L-item[0]))
        return maxeara
```
