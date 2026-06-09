![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/479e43991fab5aa4afdc8e7c4c60500b053da748af0f6033aa06c2f2828405d8-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)
### 代码

```java
class Solution {

    public int pathSum(TreeNode root, int sum) {
        if(root == null) return 0;
        // 就分成两种情况，包括根节点，不包括根节点。
        if(root.left != null && root.right!= null){
            return method(root,sum) + pathSum(root.left,sum) + pathSum(root.right,sum);
        }else if(root.left == null && root.right != null){
            return method(root,sum) + pathSum(root.right,sum);
        }else if(root.right == null && root.left != null){
            return method(root,sum) + pathSum(root.left,sum);
        }else{//没有左右儿子
            return root.val == sum?1:0;
        }
    }

    // 定一个方法，能够返回，包括根节点，和为sum的路径总数
    public int method(TreeNode root, int sum){
        if(root==null) return 0;
        if(root.val==sum){
            if(root.left != null && root.right!= null){
                return method(root.left,0) + method(root.right,0) +1;
            }else if(root.left == null && root.right != null){
                return method(root.right,0) +1;
            }else if(root.right == null && root.left != null){
                return method(root.left,0) +1;
            }else{//没有左右儿子
                return 1;
            }
        }else{// 不等于sum
            if(root.left != null && root.right!= null){
                return method(root.left,sum-root.val) + method(root.right,sum-root.val);
            }else if(root.left == null && root.right != null){
                return method(root.right,sum-root.val);
            }else if(root.right == null && root.left != null){
                return method(root.left,sum-root.val);
            }else{//没有左右儿子
                return 0;
            }
        }
    }
}
```