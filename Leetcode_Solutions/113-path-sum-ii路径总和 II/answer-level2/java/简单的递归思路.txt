在所有的二叉树题目中，其实都可以看成遍历。这样做起来就非常好做了。
也就是抽象出来三步骤

前序遍历
  去左子树
中序遍历
  去右子树
后序遍历

剩下的无非就是在这几个步骤里面添加相关条件即可实现。
需要注意的是清除元素的两个步骤了。
1、所有的都走完了 清除自己。
2、添加到返回结果后，清除自己。

```
private List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if( root == null){
            return ret;
        }
        List<Integer> select = new ArrayList<>();
        back(root, sum, select);
        return ret;
    }
    private void back(TreeNode root, int sum, List<Integer> select){
        select.add(root.val);
        //考虑到负数到情况所以用减法
        sum =  sum - root.val;
        if( sum == 0 && root.left == null && root.right == null){
            ret.add(new ArrayList(select));
            //这里要清除一个元素，也就是返回上一个元素
            select.remove(select.size() -1 );
            return;
        }
        if(root.left != null ){
            back(root.left, sum, select);
        }
        if(root.right != null){
            back(root.right, sum, select);
        }
        //左右子树都递归结束，则清除自己
        if(select.size() > 1){
            select.remove(select.size() -1 );
        }
        
    }
```
