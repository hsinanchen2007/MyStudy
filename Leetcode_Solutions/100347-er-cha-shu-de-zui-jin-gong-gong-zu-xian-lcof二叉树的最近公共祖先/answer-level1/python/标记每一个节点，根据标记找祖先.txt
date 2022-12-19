1.将每个节点标记，记录在字典（哈希表）里，方式为：从根节点开始，向左为0，向右为1，如示例中节点7标记为“010”，节点4标记为“011”
2.由两个节点的标记从头开始的公共部分得到祖先的标记，如7和4的祖先标记为“01”
3.由祖先的标记得到祖先节点2
```
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        stack = [root]
        d = {root:""}
        while stack != []:
            temp = []
            for i in stack:
                if i.left:
                    d[i.left] = d[i] + "0"
                    temp.append(i.left)
                if i.right:
                    d[i.right] = d[i] + "1"
                    temp.append(i.right)
            stack = temp
        #标记完成，接下来根据标记找到pq的最近公共祖先的标记
        p_tag = d[p]
        q_tag = d[q]
        num = 0
        res_tag = ""
        while num < len(p_tag) and num < len(q_tag):
            if p_tag[num] != q_tag[num]:
                break
            else:
                res_tag += p_tag[num]
                num += 1
        for k,v in d.items():
            if v == res_tag:
                return k
```
