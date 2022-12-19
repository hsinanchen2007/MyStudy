先用findPath函数, 利用后续遍历的思想，找出根节点到目标节点的路线，用Stack表示 3->5

剩下的就是利用 findDistanceNode函数，找出:
1）在目标节点（5）下面，距离目标节点距离为K的点的集合
2）在目标节点的父节点（3）下面，距离目标节点距离为K-1的点集合

*: 当找完一个点，我们可以把他的val设为-1，这样在上层节点遍历的时候，就可以跳过该目标点的子树。



```
class Solution {
    List<Integer> result = new ArrayList<>();
    Stack<TreeNode> treeStack = new Stack<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {

        findPath(root,target);
        while(!treeStack.isEmpty()){
            TreeNode head=treeStack.pop();
            findDistanceNode(head,head,K);
            head.val=-1;
            K--;
        }
        return result;
    }

    //TODO:后续遍历的思想
    public boolean findPath(TreeNode root, TreeNode target){
        if(root==null) return false;
        
        treeStack.push(root);

        if(root==target)
            return true;

        if(findPath(root.left,target))
            return true;
        
        if(findPath(root.right,target))
            return true;
        
        treeStack.pop();
        
        return false;
    }
    
    public void findDistanceNode(TreeNode target, TreeNode currentNode, int K){
        
        if(currentNode==null || K<0 || currentNode.val==-1)
            return;
        
        if(K==0){
            result.add(currentNode.val);
            return;            
        }

        findDistanceNode(target,currentNode.left,K-1);
        findDistanceNode(target,currentNode.right,K-1);
    }
}

```