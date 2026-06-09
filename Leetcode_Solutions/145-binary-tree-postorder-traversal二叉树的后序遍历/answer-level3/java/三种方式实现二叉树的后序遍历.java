### 1.递归（通过）
后序遍历的顺序是左子树右子树根节点，所以在递归中也是先访问根节点的左子树，然后访问根节点的右子树，最后访问根节点
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list=new ArrayList<>();
          postorder(list,root);
          return list;
    }
    private void postorder(List<Integer> list,TreeNode root){
        if(root!=null){
            postorder(list,root.left);
            postorder(list,root.right);
            list.add(root.val);
        }
    }
}
```
### 2.迭代（通过）
递归的题一般转化为非递归就是使用自己定义的栈来模拟系统栈的调用，这个思路我是借鉴别人的，觉得很好，就是对于当前的这个节点，使用两个布尔类型的值记录它的左右子树是否被访问，初始时两个都置为true，也就是假定都已经访问过了，如果在下面的验证中，左子树或者右子树并没有被访问过，则修改对应的布尔值，如果左右子树都被访问过了，这时才访问这个节点，并将它弹出，这里要注意的是，要添加一个set集合，用于将已经访问过的节点（也就是pop出来的节点）放进去，避免对节点的重复的访问，导致死循环
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        
        if(root==null) return res;
        
        Stack<TreeNode> stack=new Stack<TreeNode>();
    	
    	//设置一个isVisit来看当前节点的左子树是否被访问过了
    	Set<TreeNode> isVisit=new HashSet<TreeNode>();
    	//首先将根节点放入栈中
    	stack.add(root);
    	
    	while(!stack.isEmpty()) {
    		TreeNode cur=stack.peek();
    		
            //设置两个变量，来记录当前节点的左子树或者右子树有没有被访问完
        	boolean left=true; boolean right=true;
    		
    	    //如果这个节点的右子树不为空且没有被访问过，对右子树进行访问
            /*这里注意要先压右子树，因为栈是后进先出，所以先压右
            子树，再押左子树才能保证先访问左子树
            */
    		if(cur.right!=null&&!isVisit.contains(cur.right)) {
    			stack.push(cur.right);
    			right=false;
    		}
    		
    		if(cur.left!=null&&!isVisit.contains(cur.left)) {
    			stack.push(cur.left);
    			left=false;
    		}
    		
    		if(left&&right) {
    			res.add(cur.val);
    			isVisit.add(stack.pop());
    		}
    	}
        
        return res;
    }
}
```
### 3.Morris算法（通过）
主要优化在空间复杂度，过程中会改变一下树的结构，最后树的结构不会改变，思路大体分为以下几步
> 1. 声明一个虚拟节点，它的左子树设置为根节点
> 2. 声明一个节点cur指向虚拟节点，此时进行判断，如果cur的左子树为空，则访问它的右子树，如果左子树不为空，跳到第3步
> 3. 找到当前节点在中序遍历的前驱节点，其实也就是当前节点的左子树中最右边的节点，然后判断前驱节点的right是否为空，如果为空，证明当前节点的左子树没有访问完，让前驱节点的right指向当前节点，继续访问当前节点的左子树，如果不为空，跳到第4步
> 4. 如果前驱节点的右子树不为空，证明当前节点的左子树访问完了，此时将当前节点的左节点到前驱节点的这一段倒序输出，再倒回来，将前驱节点的right置为空，继续访问当前节点的右子树
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    void reverse(TreeNode from,TreeNode to){
        if(from==to) return;
        TreeNode x=from; TreeNode y=from.right; TreeNode z=null;
        
        while(true){
            z=y.right;
            y.right=x;
            x=y;
            y=z;
            if(x==to) break;
        }
    }
    
    void add(List<Integer> res,TreeNode from,TreeNode to){
        TreeNode st=from;
        
        while(st!=to){
            res.add(st.val);
            st=st.right;
        }
        
        res.add(to.val);
    }
    
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        
        if(root==null) return res;
        
        TreeNode dump=new TreeNode(-1);
        dump.left=root;
        
        TreeNode cur=dump;
        
        while(cur!=null){
            if(cur.left==null){
                cur=cur.right;
            }else{
                TreeNode pre=cur.left;
                while(pre.right!=null&&pre.right!=cur) pre=pre.right;
                
                if(pre.right==null){
                    pre.right=cur;
                    cur=cur.left;
                }else{
                    reverse(cur.left,pre);
                    add(res,pre,cur.left);
                    reverse(pre,cur.left);
                    pre.right=null;
                    cur=cur.right;
                }
            }
        }
        
        return res;
    }
}
```
