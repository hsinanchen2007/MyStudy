比赛时的解法一，遍历每个节点，找以该节点为起点交错路径，防止重复计算，利用hashmap记录才不会超时，但是这个代码量多，比赛据吃亏，菜啊
后面解法二，利用dfs时回溯阶段来得到最后答案，遍历一次就好，代码量少可做模板方法
类似的题，只要找到需要返回的关键数据，封装好后就可一次递归实现，这里需要同时记录往左和往右两种可能，这么看其实有点像dp


```
解法一：
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
    HashMap<TreeNode,Integer> map=new HashMap<>();
    public int longestZigZag(TreeNode root) {
        if(root==null) return 0;
        int left=0;
        int right=0;
        if(root.left!=null){
            left=lengthof(root.left,0)+1;
        }
        if(root.right!=null){
            right=lengthof(root.right,1)+1;
        }
        int len=left>right?left:right;
        int a=longestZigZag(root.left);
        int b=longestZigZag(root.right);
        return Math.max(len,Math.max(a,b));
        
    }
    //函数递归计算及交错树的长度 ,dir:0 left
    public int lengthof(TreeNode root,int dir){
        if(map.containsKey(root)) return map.get(root);
        if(root.left==null&&root.right==null){
            return 0;
        }
        int left=0;
        int right=0;
        if(root.left!=null&&dir==1){
            left=1+lengthof(root.left,0);
        }
        if(root.right!=null&&dir==0){
            right=1+lengthof(root.right,1);
        }
        map.put(root,left>right?left:right);
        return left>right?left:right;
    }
}
```
解法二：
```
class Solution {
    int longest=0;
    public int longestZigZag(TreeNode root) {
        //dfs，但是在回溯的过程就解决了问题，不用重复找节点开始递归
        if(root==null) return 0;
        dfs(root);
        return longest;
    }
    public Result dfs(TreeNode root){
        int l=0;
        int r=0;
        if(root.left!=null){
            Result next=dfs(root.left);
            l=next.lenr+1;            
        }
        if(root.right!=null){
            Result next=dfs(root.right);
            r=next.lenl+1;
        }
        longest=Math.max(longest,Math.max(l,r));
        return new Result(l,r);
    }    
}
class Result{
    int lenl;
    int lenr;
    public Result(int lenl,int lenr){
        this.lenl=lenl;
        this.lenr=lenr;
    }
}
```

