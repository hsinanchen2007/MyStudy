  因为是右视图，所以我们可以先不断遍历**右子树的右子树**，加入栈中，直到到了最右的节点，再弹出节点，继续遍历**该节点的左子树下的右子树**，如果到了叶子节点，那么从栈弹出一个节点，即回退到上一个节点，遍历**上一个节点左子树的右子树**。如此反复，便可以得到我们想要的结果。同时我们在遍历每一个节点时都要记录下该节点的深度，这样在回退时才能正确取到回退的节点的深度。
简单画个图表示这个过程：
![image.png](https://pic.leetcode-cn.com/6a6356fe32a928b4e29219b51f94baeafe5257d39429b83d7223094801c17d75-image.png)

```
public List<Integer> rightSideView(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> depthStack = new Stack<>();
        List<Integer> list = new ArrayList<Integer>();
        go(root,-1,-1,stack,depthStack,list);
        return list;
    }
    
    void go(TreeNode treeNode,int depth,int maxDepth,Stack<TreeNode> stack,Stack<Integer> depthStack,List<Integer> list ){
        if(treeNode==null){
            if(stack.size()==0)return;
            //遍历上一个节点的左子树
            go(stack.pop().left,depthStack.pop(),maxDepth,stack,depthStack,list);
        }else{
            //把当前节点入栈
            stack.add(treeNode);
            if(++depth>maxDepth){
                maxDepth = depth;
                list.add(treeNode.val);
            }
            //记录下该节点的深度
            depthStack.add(depth);
            go(treeNode.right,depth,maxDepth,stack,depthStack,list);
        }
    }
```
