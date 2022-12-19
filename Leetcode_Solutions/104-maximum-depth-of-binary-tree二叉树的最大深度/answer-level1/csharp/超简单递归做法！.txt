```
public class Solution {
    int answer;
    public int MaxDepth(TreeNode root) {
        go(1,root);
        return answer;
    }
    public void go(int now,TreeNode t){
        if(t==null){return ;}
        answer=Math.Max(answer,now);
        go(now+1,t.left);
        go(now+1,t.right);
    }
}
```
now是当前层数哦）
