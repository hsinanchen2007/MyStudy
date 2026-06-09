抽象问题：父节点层数 = 最大子节点层数 + 1;

f(n) = max(f(n.left),f(n.right)) + 1;

```
public int maxDepth(TreeNode root) {
       if (root == null){
           return 0;
       }
       return max(maxDepth(root.left),maxDepth(root.right)) + 1;
    }

     public int max(int a,int b){
        if(a>b){
            return a;
        }
        return b;
    }
```
