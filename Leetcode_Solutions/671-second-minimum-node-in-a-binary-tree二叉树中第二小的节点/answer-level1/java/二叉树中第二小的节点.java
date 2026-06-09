使用递归调用，已知节点非空，且每个节点的子节点都大于等于本身，所以无需遍历所有节点，只需找到每个子树中的第一个不等于根节点的值。
目标值可能在左子树和右子树中，递归查找出第一个不等于根节点的值即可。

```
public int findSecondMinimumValue(TreeNode root) {
        int result = find(root,root.val);
        return result==root.val? -1: result;
    }
    
    private int find(TreeNode root, int target){
        if(root==null){
            return target;
        }
        if(root.val==target){
            int left = find(root.left,target);
            int right = find(root.right,target);
            if(left!=target && right!=target){
                return Math.min(left,right);
            }else if (left!=target){
                return left;
            }else if (right!=target){
                return right;
            }else{
                return target;
            }
        }else{
            return root.val;
        }
        
    }
```
