### 解题思路
从底向上好困难...
注意坑: 不能用set,必须用字典, 记录每次的出现情况


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum1: int) -> int:
        ans = []
        #res = {}
        def post_traverse(root):
            #后序遍历:
            
            
            if root == None:
                return {}

            
            
            #res[root.val] = res.get(root.val, 0) + 1
            #base 叶节点:
            #if root.left == None and root.right == None:
                #res[root.val] = 1
                # if sum in res:
                #     ans.append(res[root.val])
            #     print(res)
            #     # if sum in res:
            #     #     ans.append(1)
            #     return res

            res1 = post_traverse(root.left)
            res2 = post_traverse(root.right)
            #res = {root.val:1}
            tmp = {}
            for key in res1.keys() | res2.keys():
                tmp[key] = sum([d.get(key,0) for d in (res1,res2)])
            tmp = {key+root.val:val for key,val in tmp.items()}
            tmp[root.val] = tmp.get(root.val, 0) + 1 #根节点本身出现1次
            if sum1 in tmp:
                ans.append(tmp[sum1])
            #print(tmp)
            return tmp

        post_traverse(root)
        # if sum in res:
        #         ans.append(1)
        #print(ans)
        # sum_ans = 0
        # for i in ans:
        #     sum_ans += i
        return sum(ans)
        




            
```