感觉我的想法更容易理解一点，存储每条到叶子节点的路径，和链表路径进行比较即可，路径都用字符串保存，方便使用字符串函数进行快速比较

```
class Solution {
    List<List<Integer>> list=new ArrayList<>();
    public boolean isSubPath(ListNode head, TreeNode root) {
        List<Integer> path=new ArrayList<>();
        dfs(root,path);
        List<String> slist=new ArrayList<>();
        for (List<Integer> l:list) {
            String s="";
            for (Integer n:l) {
                s+=n;
            }
            slist.add(s);
        }
        String t="";
        while (head!=null) {
            t+=head.val;
            head=head.next;
        }
        for (String temp:slist) {
            if (temp.indexOf(t)>=0){
                return true;
            }
        }
        return false;
    }
    
    void dfs(TreeNode root,List<Integer> path) {
        if (root!=null) {
            path.add(root.val);
            if (root.left==null&&root.right==null) {
                list.add(new ArrayList<>(path));
            }
            dfs(root.left,path);
            dfs(root.right,path);
            path.remove(path.size()-1);
        }
    }
}
```
