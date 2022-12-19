## 解析
本题和[第102题](http://47.102.37.2:8080/article/1575102182 "第102题")和[第103题](http://47.102.37.2:8080/article/1575797419 "第103题")都属于同一类题目。可以用递归和非递归两种方法求解
## 代码
```java
public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        DFS(root, 0, ans);
        return ans;
    }

    private void DFS(TreeNode root, int level, List<List<Integer>> ans) {
        if (root == null) {
            return;
        }
        // 当前层数还没有元素，先 new 一个空的列表
        if (ans.size() <= level) {
            ans.add(0, new ArrayList<>());
        }
        // 当前值加入
        ans.get(ans.size() - 1 - level).add(root.val);

        DFS(root.left, level + 1, ans);
        DFS(root.right, level + 1, ans);
    }


    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> levelOrderBottom1(TreeNode root) {
        if(root == null){
            return lists;
        }
        LinkedList<TreeNode>list = new LinkedList<>();
        list.add(root);
        List<Integer> res = new ArrayList<>();
        while(!list.isEmpty()){
            int cnt = list.size();
            while(cnt > 0){
                TreeNode first = list.removeFirst();
                res.add(first.val);
                if(first.left != null){
                    list.add(first.left);
                }
                if(first.right != null){
                    list.add(first.right);
                }
                cnt--;
            }
            lists.add(0,new ArrayList<>(res));
            res.clear();
        }
        return lists;


    }
```
