### 解题思路
因为括号的特殊性质，直觉来看，为了确保分割后的AB最大深度最小，那么最好的方案是"平分"原深度，基于此朴素想法：
1. 先遍历求出原括号最大深度，用一个栈来实现
2. 先假设所有括号都被B选择，标记为1
3. 选择那些能保证嵌套深度不大于原嵌套深度一半的括号，标记为0，表示可以加入A。这里，限定`len(stack) < depth//2`意味着要么`depthA = depthB`（原深度为偶数），要么`depthA = depthB-1`（原深度为奇数）；
4. 为了实现仅选择能保证嵌套深度不大于原深度一半的这个过程，仍用栈来标记当前已选择深度：
    - 如果是左括号：若未到达最大深度，则可以选并改标记为0；否则不选
    - 如果是右括号：若当前A还有左括号在等着匹配（栈不空），则选择这个右括号；否则也不选

### 结果
![image.png](https://pic.leetcode-cn.com/32981073a7b61efcdfa2017b1fd994fe92a0dea7253b76fdd433f1903b786b82-image.png)

想法简单，效率不高，仅供参考！

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        depth, stack = 0, []
        for c in seq:#出原括号的嵌套深度
            if c=='(':
                stack.append(c)
                depth = max(depth, len(stack))
            else:
                stack.pop()
        ans = [1]*len(seq) #初始化全为1，表示初始都被B选中
        for i, c in enumerate(seq):
            if c == '(' and len(stack) < depth//2:#仅选能使A括号深度不大于原深度一半的左括号
                stack.append(c)
                ans[i] = 0 #标记被A选中
            elif c == ')' and stack: #A中有待匹配的左括号时，则选中该右括号
                stack.pop()
                ans[i] = 0 #标记被A选中
        return ans
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)