按照之型顺序打印二叉树需要两个辅助栈。我们在打印某一层的节点时，把下一层的子节点保存到相应的栈里，如果当前打印的是奇数层，则先保存右节点，再保存左节点；如果当前打印的是偶数层，则先保存左节点，再保存右节点。

```
public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res=new ArrayList<>();//存放结果
        if(root==null)
            return res;
        List<Stack<TreeNode>> helper=new ArrayList<>();//用于存放两个辅助栈
        helper.add(new Stack<TreeNode>());//初始化第一个栈
        helper.add(new Stack<TreeNode>());//初始化第二个栈
        int current=0;
        int next=1;
        List<Integer> temp=new ArrayList<>();
        helper.get(current).push(root);

        
        while(!helper.get(current).isEmpty()||!helper.get(next).isEmpty()){
            TreeNode node=helper.get(current).pop();
            temp.add(node.val);

            //当遇到偶数行时，每个节点的下层子节点先添加左儿子，后添加右儿子
            if(current==0){
                if(node.left!=null)
                    helper.get(next).push(node.left);
                if(node.right!=null)
                    helper.get(next).push(node.right);
            //当遇到奇数行时，每个节点的下层子节点先添加右儿子，后添加左儿子
            }else{
                if(node.right!=null)
                    helper.get(next).push(node.right);
                if(node.left!=null)
                    helper.get(next).push(node.left);
            }
            //当前层为空，将当前层的数组加入结果集，奇数偶数行交换
            if(helper.get(current).isEmpty()){
                res.add(new ArrayList<>(temp));
                temp.clear();
                current=1-current;
                next=1-next;
            }
        }


        return res;
    }
```
