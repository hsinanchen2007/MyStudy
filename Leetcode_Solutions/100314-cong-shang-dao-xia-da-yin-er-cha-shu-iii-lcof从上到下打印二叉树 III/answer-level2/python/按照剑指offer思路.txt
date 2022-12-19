# 按照剑指offer，利用双栈实现
具体思路可以参照书上的来

# 弱鸡第一次发帖，主要请各位大哥帮我分析一下复杂度，弱鸡太菜了
```
def levelOrder(self, root: TreeNode) -> List[List[int]]:
    # 1. 特例：根节点为空
    if root is None:
        return []
    
    # 2. 初始化变量，res:用于返回结果，stack1用于存储奇数层，Stack2：用于存储偶数层, level便是当前层，0是偶数，1是奇数
    res, s1, s2 = [], [], []
    level = 1

    # 3. 算法流程：根节点陷入栈，两个栈其中一个不为空执行
    s1.append(root)
    while s1 or s2:
        tmp = []            # 建立临时列表，用于打包当前层节点
        if level:       #  奇数层的子节点是正常顺序入栈，左右子树依次入栈s2
            # print("aaa")
            for _ in range(len(s1)):    # 判断当前层节点个数
                node = s1.pop()         # 栈顶出栈
                tmp.append(node.val)    # 当前层依次打包
                if node.left:
                    s2.append(node.left)
                if node.right:
                    s2.append(node.right)
            level -= 1                  # 奇数层变偶数层
        else:   # 偶数层节点是逆序入栈，右左子树逆序入栈s1
            # print("bb")
            for _ in range(len(s2)):    # 判断当前层节点数
                node = s2.pop()
                tmp.append(node.val)    # 当前层元素依次打包
                if node.right:
                    s1.append(node.right)
                if node.left:
                    s1.append(node.left)
            level += 1                  # 偶数层变奇数层
        res.append(tmp)
        print(res)

    return res
```
# 复杂度分析：
时间复杂度：是o(nlogn)吗？
空间复杂度：o(n)