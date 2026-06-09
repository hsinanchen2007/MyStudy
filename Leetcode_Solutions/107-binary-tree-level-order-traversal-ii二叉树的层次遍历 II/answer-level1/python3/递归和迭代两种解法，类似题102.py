递归方法，java实现：
```
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root==null) return res;
        helper(root,0,res);
        return res;
    }
    
    public void helper(TreeNode root, int level,List<List<Integer>> res){
        if(res.size()==level){
            res.add(0,new ArrayList<Integer>());//相比题102，add的0使得数组添加到list的头部
        }
        res.get(res.size()-level-1).add(root.val);//相比题102，res.size()-level-1使得元素添加到尾部
        if(root.left!=null){
            helper(root.left,level+1,res);
        }
        if(root.right!=null){
            helper(root.right,level+1,res);
        }
    }
            
}
```
迭代方法，Python实现：
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res=[]
        level=0
        flag=0
        stack=[(root,flag,level)]
        while stack:
            node,flag,level=stack.pop()
            if node is None: continue
            if flag==0:
                stack.append((node.right,0,level+1))
                stack.append((node.left,0,level+1))
                stack.append((node,1,level))
            else:
                if(len(res)==level): res.insert(0,[]) # insert实现头部插入list
                res[-1-level].append(node.val) # -1-level 实现尾部添加元素
        return res
```

