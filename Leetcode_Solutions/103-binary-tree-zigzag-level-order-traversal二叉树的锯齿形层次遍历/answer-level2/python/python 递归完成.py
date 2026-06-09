
![QQ图片20200303083622.png](https://pic.leetcode-cn.com/0e10c9dda5fae6bf48ff817329cd1ce0f9b5740713bd355e078a5413ed203140-QQ%E5%9B%BE%E7%89%8720200303083622.png)

广度优先，先将这一层的所有结点以从左到右的顺序遍历，然后根据层数来判断，奇数层从右到左保存，偶数层从左到右保存。

```
class Solution(object):
    def zigzagLevelOrder(self, root):
        if root==None:
            return []

        def find(node_list,level):
            tem=[]
            answer=[]
            
            for i in node_list:
                if i!=None:
                    if i.left!=None:
                        tem.append(i.left)
                    if i.right!=None:
                        tem.append(i.right)
            
            if len(tem)!=0:
                for i in tem:
                    answer.append(i.val)
                if level%2 ==0:
                    result.append(answer)
                else:
                    answer.reverse()
                    result.append(answer)
                find(tem,level+1)

        result=[]
        result.append([root.val])
        find([root],1)
        return result
```
