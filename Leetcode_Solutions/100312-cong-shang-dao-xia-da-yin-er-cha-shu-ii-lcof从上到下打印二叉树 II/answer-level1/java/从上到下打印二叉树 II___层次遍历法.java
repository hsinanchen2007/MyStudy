### 解题思路
此处撰写解题思路
针对这一题使用层次遍历法解决，定义一个要返回的目标数。
第一步：在主函数中要判断root是否为空值，然后定义一个遍历函数且从0开始。
第二步：在遍历函数中首先判断root是否为空，接着判断传进来的层数是否与目标大小相等，等则创建ArrayList，同时将值存进去。
第三步：判断左右节点是否为空，否则使用遍历函数且对应的层数要加1。
以上是我的个人见解，如有不对还望大佬指点，这也是我第一次做的题和第一次写题解不是很懂。如果有优化的还望指点一下。谢谢
### 代码

```java
class Solution {
    List<List<Integer>> target = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null){
            return new ArrayList<>();
        }
        arrangement(root , 0);
        return target;
    }
    private void arrangement(TreeNode root , int sign){
        if(root == null){
            return ;
        }
        if(target.size()==sign){
            target.add(new ArrayList<>());
        }
        target.get(sign).add(root.val);
        if(root.left!=null){
            arrangement(root.left,sign+1);
        }
        if(root.right!=null){
            arrangement(root.right,sign+1);
        }
    }
}

```