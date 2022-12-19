### 错误小结
记录每层元素时，new一个新的列表li（之前用list.clear();将列表清空）；list中存放的时对象的引用，整个树的结果列表l中存放了若干个每层列表li的引用，指向li的内存空间（如下图）
![有.bmp](https://pic.leetcode-cn.com/b87f808db7d65acae5618e9e125c7e8998eb1e5889b03ad47f51441c0340cea8-%E6%9C%89.bmp)

当用li.clear()清空数据，仅删除li内存空间中的数据，l中li的引用并没有删除，当下次l添加li时，都指向同一块内存空间，数据也是一样的。就可能出现结果如[[],[],[]]这样，即使判断li为空也没用，因为li的引用并没有删除。
![无.bmp](https://pic.leetcode-cn.com/5e638e3dc4111520ca50c188c92b5887ea9fa10e2a8badb5d2f4090cd6c0d5d0-%E6%97%A0.bmp)


### 代码
每次在堆中新建一个li对象时，原来的内存空间没有引用被GC回收/无法引用，所以保证只有一个li的内存空间，不会出现重复等情况
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> l = new ArrayList<List<Integer>>();
        Queue<TreeNode> q=new LinkedList<>();
        List<Integer> li = new ArrayList<>();
        
        if (root==null){return l;}
        q.offer(root);
        while(!q.isEmpty()){
            li = new ArrayList<>();
            for(int i =q.size();i>0;i--){
                TreeNode node = q.poll();
                li.add(node.val);
                if(node.left!=null){
                    q.offer(node.left);
                }
                if(node.right!=null){
                    q.offer(node.right);
                }
            }
            if(!li.isEmpty()) {l.add(li);}
        }
        
        return l;
    }
  
}
```