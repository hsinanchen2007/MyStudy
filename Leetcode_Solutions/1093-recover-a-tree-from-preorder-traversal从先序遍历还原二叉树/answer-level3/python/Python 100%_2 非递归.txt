前提: 
- 原始树节点个数介于1~1000之间 => 非空,所以不需要做空串判断
- 如果节点只有一个子节点，那么保证该子节点为左子节点。


思路:
1. 短'-'的数量代表树节点所处于的层次
2. 如果'-'呈现递增趋势(不会增加大于2),那么一定是 树->左子树->左子树->左子树...
3. 如果'-'呈现水平趋势,即与前一个相同,那也前面一定是左子树,当前一定是右子树
4. 如果'-'呈现下降趋势,表示当前分支已经达到最大深度

需求:
- "趋势"的记录:通过对比"当前层","需求层"
- 树支的连接: 借助栈(使用deque模拟)来找父节点

算法:
- 如果"需求层" 大于  "当前层"
    - 将该节点作为栈顶节点的左子树
    - 将其压入栈
    - "当前层" ++


- 如果"当前层" 不大于"当前层"
    - 栈出("需求层"-"当前层"+1)元素
    - 将该节点与栈顶节点的右子树
    - 将其压栈
    - "当前层"更新为"需求层"


实现
```python
class Solution(object):
    def recoverFromPreorder(self, S):
        """
        :type S: str
        :rtype: TreeNode
        """
        from collections import deque
        stack = deque()
        length = len(S)
        
        num_root = ''
        cur_pos = 0
        while cur_pos < length and S[cur_pos]!='-':
            num_root += S[cur_pos]
            cur_pos += 1
        root = TreeNode(num_root)
        stack.append(root)
        # 记录“当前层”
        cur_level = 0
        while cur_pos < length:
            # 计算“需求层”
            req_level = 0
            while S[cur_pos] == '-':
                cur_pos += 1
                req_level += 1
            # 计算值
            tmp_value = ''
            while cur_pos < length and S[cur_pos] != '-':
                tmp_value += S[cur_pos]
                cur_pos += 1

            if req_level > cur_level:
                leftNode = TreeNode(tmp_value)
                stack[-1].left = leftNode #栈顶元素为其父节点
                stack.append(leftNode)
                cur_level +=1 
            else:
                # 退回到需求层
                for i in range(0,cur_level-req_level+1):
                    stack.pop()
                rightNode = TreeNode(tmp_value)
                stack[-1].right = rightNode
                stack.append(rightNode)
                cur_level = req_level
                
        return root
```
