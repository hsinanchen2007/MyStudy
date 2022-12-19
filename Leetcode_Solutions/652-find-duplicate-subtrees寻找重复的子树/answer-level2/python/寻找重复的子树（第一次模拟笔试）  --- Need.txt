### 解题思路
1. 此题上来一脸的蒙蔽 （第一次模拟在线笔试，遇到的第三道题目） 
    - 第一题目：石头碰撞，每次取**最大的两个**，且令y = y-x(假设y较大)；求最后剩余石头的重量 （简单）
        - **思路：**list.sort(reverse=True) 原list上排序 --> i+1 = i - i+1; i+1 插入排序的过程
        - **需要对题目理解完全，方可做题**
        - **同时处理好 边界问题**，i不可以取nsize-1； list_size 为0或1 如何处理
        - [最后一块石头的重量 II --- Need](https://leetcode-cn.com/problems/last-stone-weight-ii/solution/zui-hou-yi-kuai-shi-tou-de-zhong-liang-ii-need-by-/)
            - 改为任意两块石头，最后得到最小的
    
    - 第二题目：排序链表，删除重复元素 （简单）
        - **题意非常明确，处理好指针即可，需要一个前向指针**
        - 此处可以采用假前向指针"cur",但是每次判断时，比较cur.next 的情况
    - **第三道题目：就是本题目，二叉树 中等难度**
        - **第一感觉没有头绪**
        - **题目有点含蓄的地方**：必须从叶节点算起，不能是总监某一部分结构，因为要求是子树；
        - **个人的心理路程**
            - **通过序列判断是否ok**，但是考虑到无论中序序列还是前序、后续貌似都解决不了，**因此一闪而过（知识储备不够啊）**
                - **如果能够想到 任意一种遍历序列（带有空节点）能够唯一确定一棵树** -- 题眼
                - 不过也仅仅是万里长城的第一步
            - 就想着遍历叶子节点，逆向找父节点，但是没有指向父节点的指针，作罢！
            - 心想着递归试试看，无功而返
2. [前序序列化确定二叉树 + hash](https://leetcode-cn.com/problems/find-duplicate-subtrees/solution/qian-xu-xu-lie-hua-que-ding-er-cha-shu-hash-by-he-/)
    - **唯一确定一棵树:下面条件之一即可**
        - **中序遍历序列 + **前序遍历序列、后续遍历序列、层次遍历序列 （**要求树中没有重复元素**）
        - 对于一颗**二叉搜索树BST**/二叉查找树(要求**树中没有重复元素** ):
            - 只需要前序、中序、后续、层序中的一种即可
            - 如果将已知遍历从小到大排序即为中序遍历
        - **前序/后序/层序序列化** （ 要求**包含空指针** ）
            - **二叉树的序列化是指**：把一棵二叉树按照某种遍历方式的结果保存为字符串，其中的空结点也要保存为一个字符
            - **注意：带空指针的中序序列化不能重建二叉树 **（该序列是一个空结点字符和结点字符交叉排列的字符串）
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        res = []
        di = dict()
        self.postOrder(root, res, di)
    
        return res 
    
    def postOrder(self, root, res, di):
        if root is None:
            return "#"
        
        le = self.postOrder(root.left, res, di)
        ri = self.postOrder(root.right, res, di)
        k = str(root.val) + le + ri 
        di[k] = di.get(k, 0) + 1
        if di[k] == 2:
            res.append(root)
        return k
        


```