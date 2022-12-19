
# 一、栈的使用思路：

看到题目中相互匹配的括号时，首先可以想到的是力扣原题 [**20.有效的括号**](https://leetcode-cn.com/problems/valid-parentheses/)。

对于这种括号匹配的题目，我们可以利用**栈先进后出的特点**进行解答。

分析题目可以得知，对于任何一段字符，A(B)(C)可知，**B、C分别为A的左子树和右子树**，'('代表着子树的开始，而')'代表着子树的结束。

考虑到栈的应用，我们可以每次都将**新生成的节点压入栈中**，**因此栈顶端永远是相当于当前节点的上一个最新节点**。

对于A(B)(C)而言，如果 TreeNode(A) 已经在栈中，即stack=[TreeNode(A)]，B是A的左节点，也就是栈顶端元素stack[-1] 的左节点，因此有 stack[-1].left = TreeNode(B).

此时将TreeNode(B)压入栈中，stack=[TreeNode(A), TreeNode(B)]，但对于C而言，C的父节点是A而非B，**因此，为了保证栈的顶端永远为当前节点的父节点，我们需要弹出TreeNode(B)**。

也就是说，**当')'出现，也就是子树结束时，我们应当弹出stack最顶端的元素。**

现在需要考虑的另外一个问题是：**什么时候整数读取结束？**

# 二、整数读取结束的标志：

从题目中所给的实例我们不难看出，**当整数的下一位为括号时，即可认为整数读取结束**。反过来说，我们是否能认为，当我们读取到括号时，之前所读取的一定是一个整数呢？

**答案当然是否定的**，示例输入中存在 ')('和'))(' 等情况，当我们读取到括号时，**可以判断当前是否有整数读入**。

1. 如果有整数读入，**创造树节点**，并**建立当前树节点与栈顶节点的关系**，并将该节点**压入栈顶**。

2. 如果读到的括号为')'，则**将栈顶节点弹出。**

# 三、算法细节：

**1. 返回值：**

考虑到括号总是成对出现的，每一个')'对应一次弹出操作，而对于根节点root而言，输入值的字符串可以写成root(root.left)(root.right)，可见当字符串遍历结束后，root所对应的节点仍保持在栈顶，因此返回栈顶元素即可，即stack[-1]。

**2. 对负数的处理：**

由于输入字符串中还有可能包含'-'，即可能含有负数，因此要格外设立一个flag保存负号标志。对于多位数而言，不难得知，对于每一个输入的数字c，**num = num*10 + flag*int(c)**。

**3. 对特殊情况的处理：**

当输入字符串为空时，我们可以直接返回一个空节点。
而当输入字符串只有root节点的值，即root.val，而没有括号时，root节点还没来得及被创建，也没来得及被压入栈中。此时栈为空，我们可以直接返回TreeNode(root.val)。

# 四、具体算法：

```
class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if s=="":                              # 当输入字符串为空时，返回None
            return None

        def insert_node(num,stack):            # 插入节点函数，在每次整数输入完成后调用
            node = TreeNode(num)               # 创建以num为值的节点node
            if stack:                          # 如果stack非空，则node节点为栈顶节点的子节点
                if not stack[-1].left:         # 如果栈顶节点没有左子树，node为其左子树
                    stack[-1].left = node
                else:
                    stack[-1].right = node     # 反之，node为其右子树
            stack.append(node)                 # 将node压入栈中
            return [None,1]                    # 返回None和1，分别作为整数num和标志flag的初始值

        num, flag, stack = None, 1, []         # 对num, flag和栈进行初始化

        for c in s:                            # 遍历s中的每一个字符c
            if c == '(':                       # 如果c=='('，且num为数字，插入节点
                if num!=None:
                    num,flag = insert_node(num,stack)
                              
            elif c == ')':
                if num!=None:                  # 如果c==')'，且num为数字，插入节点
                    num,flag = insert_node(num,stack)
                stack.pop()                    # ')'标志着该子树输入完成，因此将其弹出栈

            elif c == '-':                     # 如果有-出现，flag置为-1
                flag = -1
            
            else:                              # 如果c为数字，读入整数
                num = (num*10 + flag*int(c)) if num else flag*int(c)
        
        return stack[-1] if stack else TreeNode(num)    # 如果stack非空，返回最顶端的节点，即root
                                                        # 否则返回以num为值的节点
```
# 五、对算法的优化：

**1. 对于输入字符串为空的判断：**

可以将这部分判断移到算法的最后，在stack为空，且num值为None的情况下直接返回None，而不必每次都对s是否为空字符串进行判断，**该优化可以显著减少运行时间，达到双100%的效果。**

```
if stack:
    return stack[-1]
elif num != None:
    TreeNode(num)
else:
    return None
```
完整代码为：

```
class Solution:
    def str2tree(self, s: str) -> TreeNode:
        def insert_node(num,stack):            # 插入节点函数，在每次整数输入完成后调用
            node = TreeNode(num)               # 创建以num为值的节点node
            if stack:                          # 如果stack非空，则node节点为栈顶节点的子节点
                if not stack[-1].left:         # 如果栈顶节点没有左子树，node为其左子树
                    stack[-1].left = node
                else:
                    stack[-1].right = node     # 反之，node为其右子树
            stack.append(node)                 # 将node压入栈中
            return [None,1]                    # 返回None和1，分别作为整数num和标志flag的初始值

        num, flag, stack = None, 1, []         # 对num, flag和栈进行初始化

        for c in s:                            # 遍历s中的每一个字符c
            if c == '(':                       # 如果c=='('，且num为数字，插入节点
                if num!=None:
                    num,flag = insert_node(num,stack)
                              
            elif c == ')':
                if num!=None:                  # 如果c==')'，且num为数字，插入节点
                    num,flag = insert_node(num,stack)
                stack.pop()                    # ')'标志着该子树输入完成，因此将其弹出栈

            elif c == '-':                     # 如果有-出现，flag置为-1
                flag = -1
            
            else:                              # 如果c为数字，读入整数
                num = (num*10 + flag*int(c)) if num else flag*int(c)
        
        return stack[-1] if stack else (TreeNode(num) if num != None else None)    
                                                # 如果stack非空，返回最顶端的节点，即root
                                                # 否则，
                                                # 如果num为整数，返回以num为值的节点
                                                # 否则返回None
```
![微信截图_20191230073824.png](https://pic.leetcode-cn.com/4bebbc391f501771532db43e6ce4843749ce0e2b96a26d615bb5882ec2bf3621-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191230073824.png)




**2. 减少栈的压入弹出操作：**

考虑到碰到')'后，如果num为整数，原来的算法会先将node，也就是num所对应的节点压入栈中，再立刻弹出，增加了不必要的开销，因此我们将函数insert_node中压入栈的部分去除，只在碰到'('时将node压入栈。

而')'作为子树输入结束的标志，如果此时num为整数，我们依旧调用insert_node函数，但不必额外弹出。否则，则应弹出栈顶的节点，因为此时栈顶节点的子树输入已经完成。

**遗憾的是，该算法与原算法的运行效率相似，并没有显著提升。**

```
class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if s=="":                              # 当输入字符串为空时，返回None
            return None

        def insert_node(num,stack):            # 插入节点函数，在每次整数输入完成后调用
            node = TreeNode(num)               # 创建以num为值的节点node
            if stack:                          # 如果stack非空，则node节点为栈顶节点的子节点
                if not stack[-1].left:         # 如果栈顶节点没有左子树，node为其左子树
                    stack[-1].left = node
                else:
                    stack[-1].right = node     # 反之，node为其右子树
            
            return [None,1,node]               # 返回None,1分别作为整数num和标志flag的初始值
                                               # 返回node，以便压入栈中

        num, flag, stack = None, 1, []         # 对num, flag和栈进行初始化

        for c in s:                            # 遍历s中的每一个字符c
            if c == '(':                       # 如果c=='('，且num为数字，插入节点
                if num!=None:
                    num,flag,node = insert_node(num,stack)
                    stack.append(node)         # 将node压入栈中
                              
            elif c == ')':
                if num!=None:                  # 如果c==')'，且num为数字，插入节点
                    num,flag,node = insert_node(num,stack)                           
                                               # 对于该情况，为了减少压入栈和弹出栈的额外开销
                                               # 不必将node压入栈中
                    
                else:
                    stack.pop()                # num非整数，说明')'为前面节点的子树输入完成的标志
                                               # 此时弹出的为前面的节点

            elif c == '-':                     # 如果有-出现，flag置为-1
                flag = -1
            
            else:                              # 如果c为数字，读入整数
                num = (num*10 + flag*int(c)) if num else flag*int(c)
        
        return stack[-1] if stack else TreeNode(num)    # 如果stack非空，返回最顶端的节点，即root
                                                        # 否则返回以num为值的节点
```
![微信截图_20191230073824.png](https://pic.leetcode-cn.com/f0f551ffcf41d14c7a7cda238e1b57fb38d22be33d13029bc08573f10801bdd9-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191230073824.png)

