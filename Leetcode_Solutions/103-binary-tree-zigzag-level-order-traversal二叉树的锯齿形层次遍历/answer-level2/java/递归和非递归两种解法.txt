## 解析
本题和[第102题](http://51leetcode.top/article/1575102182 "第102题")的思路基本一致，也是两种方法。
方法一：用两个栈来模拟从右向左和从左向右的过程。
方法二：递归解法的时候，根据层数是奇数还是偶数，来判断添加到开头还是添加到末尾。
## 代码
```html
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> lists = new ArrayList<>();
        if(root == null){
            return lists;
        }
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root);
        List<Integer> list = new ArrayList<>();
        while ((!stack1.isEmpty() && stack2.isEmpty())){
            while (!stack1.empty()){
                TreeNode tmp = stack1.pop();
                list.add(tmp.val);
                if(tmp.left != null){
                    stack2.push(tmp.left);
                }
                if(tmp.right != null){
                    stack2.push(tmp.right);
                }
            }
            if(!list.isEmpty()){
                lists.add(new ArrayList<>(list));
                list.clear();
            }
            while (!stack2.empty()){
                TreeNode tmp = stack2.pop();
                list.add(tmp.val);
                if(tmp.right != null){
                    stack1.push(tmp.right);
                }
                if(tmp.left != null){
                    stack1.push(tmp.left);
                }

            }
            if(!list.isEmpty()){
                lists.add(new ArrayList<>(list));
                list.clear();
            }

        }
        
        return lists;


    }



    public List<List<Integer>> zigzagLevelOrderDFS(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        DFS(root, 0, ans);
        return ans;
    }

    private void DFS(TreeNode root, int level, List<List<Integer>> ans) {
        if (root == null) {
            return;
        }
        if (ans.size() <= level) {
            ans.add(new ArrayList<>());
        }
        if ((level % 2) == 0) {
            ans.get(level).add(root.val); //添加到末尾
        } else {
            ans.get(level).add(0, root.val); //添加到头部
        }

        DFS(root.left, level + 1, ans);
        DFS(root.right, level + 1, ans);
    }
```