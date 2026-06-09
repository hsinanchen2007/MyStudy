先来代码,遍历算法和具体解题思路分离(访问者模式),改一个枚举值即可实现切换。

```
class Solution {
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> toDeleteSet = new HashSet<>();
        for(int i: to_delete){
            toDeleteSet.add(i);
        }
        Predicate<TreeNode> contain = n-> n != null && toDeleteSet.contains(n.val);
        List<TreeNode> list = new ArrayList<>();
        Consumer<TreeNode> addChildren2List = n->{
            if(n.left!=null && !contain.test(n.left)) {
                list.add(n.left);
            }
            if(n.right!=null && !contain.test(n.right)){
                list.add(n.right);
            }
        };
        if(contain.test(root)){
            addChildren2List.accept(root);
        }else{
            list.add(root);
        }
        BinaryTree.TraverseType.LEVEL.traverse0(root, n->{
            TreeNode left,right;
            if(n==null){
                return;
            }
            left = n.left;
            if(contain.test(left)){
                n.left = null;
                addChildren2List.accept(left);
            }
            right = n.right;
            if(contain.test(right)){
                n.right = null;
                addChildren2List.accept(right);
            }
        });
        return list;
    }
}

class BinaryTree {
    public TreeNode root;

    public BinaryTree(Integer... data){
        int i = 1,cnt = 1;
        int len = data.length;
        Function<Integer, TreeNode> getTreeNode = idx->{
            Integer datum = data[idx];
            TreeNode node = null;
            if(datum!=null){
                node = new TreeNode(data[idx]);
            }
            return node;
        };
        TreeNode[] nodes = new TreeNode[len];
        TreeNode n;
        do{
            if(i==1){
                this.root = new TreeNode(data[0]);
                nodes[0] = this.root;
            }
            for(int j=cnt-i;j<cnt;j++){
                n = nodes[j];
                int rightIdx = (j+1)<<1, leftIdx = rightIdx-1;
                if(leftIdx== len){
                    break;
                }
                TreeNode left = getTreeNode.apply(leftIdx);
                nodes[leftIdx] = left;
                if(rightIdx== len){
                    break;
                }
                TreeNode right = getTreeNode.apply(rightIdx);
                nodes[rightIdx] = right;
                n.left = left;
                n.right = right;
            }

            i=i<<1;
            cnt+=i;
        }while(cnt< len);
    }

    public enum TraverseType {
        BEFORE("前序"){
            @Override
            public void traverse(TreeNode node, Consumer<TreeNode> visitor) {
                if(node==null){
                    return;
                }
                visitor.accept(node);
                traverse(node.left, visitor);
                traverse(node.right, visitor);
            }

            @Override
            public void traverse0(TreeNode node, Consumer<TreeNode> visitor) {
                if(node==null){
                    return;
                }
                TreeNode n = node;
                Deque<TreeNode> buffer = new ArrayDeque<>();
                //访问自己并将右子节点(包括自己)依次入栈
                Consumer<TreeNode> visitSelfAndPushRightToStack = a->{
                    do{
                        if(a.right!=null) {
                            buffer.push(a.right);
                        }
                        visitor.accept(a);
                        a = a.left;
                    }while(a!=null);
                };
                visitSelfAndPushRightToStack.accept(n);
                do{
                    n = buffer.pop();
                    visitSelfAndPushRightToStack.accept(n);
                }while(buffer.size()>0);
            }
        },MIDDLE("中序"){
            @Override
            public void traverse(TreeNode node, Consumer<TreeNode> visitor) {
                if(node==null){
                    return;
                }
                traverse(node.left, visitor);
                visitor.accept(node);
                traverse(node.right, visitor);
            }

            @Override
            public void traverse0(TreeNode node, Consumer<TreeNode> visitor) {
                if(node==null){
                    return;
                }
                TreeNode n = node;
                Deque<TreeNode> buffer = new ArrayDeque<>();
                //左子节点(包括自己)依次入栈
                Consumer<TreeNode> pushLeftToStack = a->{
                    do{
                        buffer.push(a);
                        a = a.left;
                    }while(a!=null);
                };
                pushLeftToStack.accept(n);
                do{
                    n = buffer.pop();
                    visitor.accept(n);
                    if(n.right==null){
                        continue;
                    }
                    pushLeftToStack.accept(n.right);
                }while(buffer.size()>0);
            }
        },AFTER("后序"){
            @Override
            public void traverse(TreeNode node, Consumer<TreeNode> visitor) {
                if(node==null){
                    return;
                }
                traverse(node.left, visitor);
                traverse(node.right, visitor);
                visitor.accept(node);
            }

            @Override
            public void traverse0(TreeNode node, Consumer<TreeNode> visitor) {
                TreeNode n = node, pre=null;
                if(node==null){
                    return;
                }
                Deque<TreeNode> buffer = new ArrayDeque<>();
                //左子节点(包括自己)依次入栈
                Consumer<TreeNode> pushLeftToStack = a->{
                    do{
                        buffer.push(a);
                        a = a.left;
                    }while(a!=null);
                };
                pushLeftToStack.accept(n);
                do{
                    n = buffer.pop();
                    if(n.right==null || pre == n.right){
                        pre = n;
                        visitor.accept(n);
                    }else {
                        buffer.push(n);
                        pushLeftToStack.accept(n.right);
                    }

                }while(buffer.size()>0);
            }
        },LEVEL("层序"){
            @Override
            public void traverse(TreeNode node, Consumer<TreeNode> visitor) {
                this.traverse0(node, visitor);
            }

            @Override
            public void traverse0(TreeNode node, Consumer<TreeNode> visitor) {
                int i;
                TreeNode n,left,right;
                boolean flag=false;
                //array serve as queue here
                List<TreeNode> buffer = new ArrayList<>();
                for(buffer.add(node);!flag;){
                    n = buffer.remove(0);
                    if(n!=null){
                        left = n.left;
                        right = n.right;
                        buffer.add(left);
                        buffer.add(right);
                    }
                    visitor.accept(n);
                    flag = true;
                    for(i= buffer.size()-1;i>=0;i--){
                        if(buffer.get(i)!=null){
                            flag = false;
                            break;
                        }
                    }
                }
            }
        };
        private String desc;
        TraverseType(String desc){
            this.desc = desc;
        }
        //递归解法
        public abstract void traverse(TreeNode node, Consumer<TreeNode> visitor);
        //非递归解法
        public abstract void traverse0(TreeNode node, Consumer<TreeNode> visitor);
    }

    //层序输出
    public static List<TreeNode> toList(TreeNode root, TraverseType traverseType){
        List<TreeNode> list = new ArrayList<>();
        traverseType.traverse0(root, list::add);
        return list;
    }

    public String join(String seperator, TraverseType traverseType){
        List<TreeNode> list = toList(root, traverseType);
        if(list.size()==0){
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (TreeNode n : list) {
            sb.append(n==null?"null":n.val).append(seperator);
        }
        return sb.substring(0, sb.length() - seperator.length());
    }

    @Override
    public String toString(){
        return join("->", TraverseType.LEVEL);
    }
}

```

这里只有后序和层序遍历可以，其他会在删除时破坏树结构。
代码见[https://gitee.com/yqrepo/DailyLeetCode]()，欢迎大家来贡献哈:)
