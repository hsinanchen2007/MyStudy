一 算法思想
二叉搜索树的中序遍历序列单调不减（或曰非严格单调递增），因此可考虑中序遍历二叉搜索树。
用max_times记录已访问节点的最大重复元素个数，time表示当前访问节点的元素值的出现次数,用res=[]记录结果。
若time == max_times，则将当前节点值添加到结果集。
若time > max_times，则以当前节点值构造新的列表作为结果，并用time更新max_times。
中序遍历结束后，返回结果res。
二 算法实现
```
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        p = root
        st = []
        res = []
        max_times = 1
        time = 1
        pre = float("inf")
        while p is not None or st:
            while p is not None:
                st.append(p)
                p = p.left
            p = st.pop()
            
            cur = p.val
            if cur == pre:
                time += 1
            else:
                time = 1
                pre = cur
            if time == max_times:
                res.append(cur)
            if time > max_times:
                res = [cur]
                max_times = time
    
            p = p.right
                
        return res
```
三 复杂度分析
时间复杂度：O(N)，N为树中节点个数。
空间复杂度：最坏情况下为O(N)， 例如树畸形（树的高度为线性）或每个元素出现一次的情形。

二叉搜索树的中序遍历序列为递增序列，灵活利用这一性质可解决一系列二叉搜索树问题。有兴趣了解利用该性质解决相关问题的朋友，请参阅[中序遍历团灭系列二叉搜索树问题](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/zhong-xu-bian-li-tuan-mie-xi-lie-er-cha-sou-suo-sh/)