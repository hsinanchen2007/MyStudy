```
 import java.util.*;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> arrs=new ArrayList<>();
        //如果是空树直接返回
        if(root==null) return arrs;
        Queue<TreeNode> q=new ArrayDeque<>();
        q.add(root);
        //index进行计数，确定层数
        int index=1;
        while (!q.isEmpty()){
            List<Integer> arr=new ArrayList<>();
            int cnt=q.size();
            while (cnt-->0){
                TreeNode t=q.poll();
                arr.add(t.val);
                if(t.left!=null) q.add(t.left);
               if(t.right!=null) q.add(t.right);
            }
        //x&1=0代表该数为偶数，等于1为奇数
            if((index&1)==0) {
        //利用collections工具的reverse
                Collections.reverse(arr);
                arrs.add(new ArrayList<>(arr));
            }
            else arrs.add(new ArrayList<>(arr));
            index++;
        }
        return arrs;
    }
}
```
不知道是不是错觉，同样的做法上题速度47.5%，这题75%
？？？手动黑人问号？？？