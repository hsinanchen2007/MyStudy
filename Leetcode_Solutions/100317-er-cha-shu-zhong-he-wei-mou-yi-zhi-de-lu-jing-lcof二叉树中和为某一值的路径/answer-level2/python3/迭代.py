```
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def list_val(arr):
            tmp = []
            for item in arr:
                tmp.append(item.val)
            return tmp 
        if root == None: return []
        ans = []
        stk = [root]
        cur = root 
        cur_sum = root.val 
        while stk:
            while cur.left:
                cur = cur.left 
                cur_sum += cur.val 
                stk.append(cur)
            while cur.right==None or cur.right ==-999:
                if cur.right !=-999 and cur.left == None and cur_sum == sum:
                    ans.append(list_val(stk))
                tmp = stk.pop()
                cur_sum -= tmp.val 
                if stk == [] : return ans 
                cur = stk[-1]
            tmp = cur.right 
            cur.right = -999 
            cur_sum += tmp.val 
            cur = tmp 
            stk.append(cur)
```
