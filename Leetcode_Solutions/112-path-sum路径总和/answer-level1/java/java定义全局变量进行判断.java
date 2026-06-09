```
class Solution {
    private boolean flag = true;//定义一个flag,当查到有路径和等值于sum时,flag将反转
    private int sum1;//定义一个int值,用来接收传入的sum,免去每次都重复传递
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root!=null) {//先进行判空,非空才执行递归方法
            sum1=sum;//给全局的sum1进行赋值
            judge(root,0);//调用递归方法,初始的和为0
        }
        return !flag;//返回取反的flag,结合递归方法理解
    }
    public void judge(TreeNode root,int sum){//递归方法需要传递节点来判断是否到末节点,每次向下进行递归时,还需要将之前的所有节点的值求和
        if(flag){//对flag进行判断,如果还未找到目标的话,flag将是true,可以继续寻找
            //对节点的左右节点进行判断,如果左右为空,表示为末节点,
                
            if(root.left==null && root.right==null) {
                //既然是末位节点,就可以对此条路径进行判断了,//如果等于目标值,则将flag变为false
                if((root.val+sum)==sum1) flag=false;
            } else{//如果不是末节点,则进行递归调用.
                //此时仍需要对左右节点进行判空,非空则传递该左右节点,并传递本节点的值于之前节点和的和
                if(root.left!=null) judge(root.left,root.val+sum);
                if(root.right!=null) judge(root.right,root.val+sum);
                //如果在递归的某一步中,找到了目标路径,flag变为false,那么之后的递归在判断flag后,都不会再继续执行
            }
        }
    }
}
```
