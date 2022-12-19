// 思路：
// 1.遍历第二层的节点的顺序是从左到右，而输出第二层节点的顺序是从右到左，这正好满足栈思想，所有用栈来第二层所有节点。
// 2.遍历栈输出第二层节点，同时还需要将第三层的节点按照从右到左的顺序存储。
//但是不能将第三层的节点存储到这个栈中，因为会打乱第二层节点的顺序，此时我们可以想到创建另一个栈来存储第三层的元素。
//这样层与层之间就不会产生干扰。
// 3.交替使用这两个栈遍历所有的层。
  
```Java
  public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if(root == null) return list;
        Stack<TreeNode> stack1 = new Stack<>();//奇数层，存储从右到左的结点顺序
        Stack<TreeNode> stack2 = new Stack<>();//偶数层，存储从左到右的结点顺序

        stack1.push(root);
        //Stack1 和stack2其中一个不为空就继续
        while(!stack1.isEmpty() || !stack2.isEmpty()){
            ArrayList<Integer> sublist = new ArrayList<>();
            if(!stack1.isEmpty()){
                while(!stack1.isEmpty()){
                    TreeNode node = stack1.pop();
                    sublist.add(node.val);
                    //插入下一层的数据，stack2，从左往右边遍历结点
                    if(node.left != null){stack2.push(node.left);}
                    if(node.right != null){stack2.push(node.right);}
                }
                list.add(sublist);

            }
            else{//栈2不为空，往栈1从右往左添加结点
                while(!stack2.isEmpty()){
                    TreeNode node = stack2.pop();
                    sublist.add(node.val);
                    //插入下一层的数据，stack1，从右往左边遍历结点
                    if(node.right != null){stack1.push(node.right);}
                    if(node.left != null){stack1.push(node.left);}
                }
                list.add(sublist);
            }
        }
        return list;
    }
```
