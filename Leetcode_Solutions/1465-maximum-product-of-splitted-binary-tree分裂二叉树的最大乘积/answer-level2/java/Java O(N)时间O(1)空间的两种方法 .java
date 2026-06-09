## 求最大积，最后取模
假设从某个点的左子和该点的边作为删除边，则左子的和是sum，另一棵树的和是totalSum-sum，目标是求`sum*(totalSum-sum)`的最大值。右子类似。所以可以先遍历一遍树，得到totalSum，然后对每个点求和，并计算该点的这个公式的值。
实现上返回当前节点得到的历史最大值，需要收集的数据是当前点的和，作为信息向上返回。
**注意不能对答案取模之后再取最大值，而是要先取最大值，然后再取模**。考虑到最多有50000个点，每个点最大10000，所以两棵树的和最大是`2.5*10^8 * 2.5*10^8`,范围是在long之内的，所以可以用long得到最大的结果，最后再取模。

这个时间复杂度O(N)，空间复杂度O(1)。用时13ms。

```java
   int mod=1000000007;
    public int maxProduct(TreeNode root) {
        long totalSum=getSum(root);
        return (int)(helper(root,new int[1],totalSum)%mod);
    }

    private long helper(TreeNode root, int[] ints, long totalSum) {
        if(root==null){
            return Integer.MIN_VALUE;
        }
        int[] leftTmp=new int[1];
        int[] rightTmp=new int[1];
        long res1=helper(root.left,leftTmp,totalSum);
        long res2=helper(root.right,rightTmp,totalSum);
        long res=Math.max(res1,res2);
        long tmp0=leftTmp[0]*(totalSum-leftTmp[0]);
        res=Math.max(res,tmp0);
        long tmp1=rightTmp[0]*(totalSum-rightTmp[0]);
        res=Math.max(res,tmp1);
        ints[0]=leftTmp[0]+rightTmp[0]+root.val;
        return res;
    }

    private int getSum(TreeNode root) {
        if(root==null){
            return 0;
        }
        return root.val+getSum(root.left)+getSum(root.right);
    }

```

## 求最接近1/2 totalSum的和

换个更加数学的角度来思考，我们要找的这个sum，一定是最靠近1/2 totalSum的。所以求sum 的过程中，我们找到这样一个目标即可。

这个时间复杂度和空间复杂度和上面相同，但是可以避免多次的乘积计算。用时12ms。

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
   int mod=1000000007;
    public int maxProduct(TreeNode root) {
        long totalSum=getSum(root);
        double target=totalSum/2.0;
        int sum=getClosest(root,target,new int[1]);
        return (int)(sum*(totalSum-sum)%mod);
    }

//返回最接近target的和
    private int getClosest(TreeNode root,double target,int[] curSum){//参数为和
        if(root==null){
            return 0;
        }
        int[] leftSum=new int[1];
        int res1=getClosest(root.left,target,leftSum);
        int[] rightSum=new int[1];
        int res2=getClosest(root.right,target,rightSum);
        double distLeft=Math.abs(res1-target);
        double distRight=Math.abs(res2-target);
        curSum[0]=leftSum[0]+rightSum[0]+root.val;
        double distCur=Math.abs(curSum[0]-target);
        if(distLeft<=distRight&&distLeft<=distCur){
            return res1;
        }
        if(distRight<=distLeft&&distRight<=distCur){
            return res2;
        }
        return curSum[0];
    }

    private long helper(TreeNode root, int[] ints, long totalSum) {
        if(root==null){
            return Integer.MIN_VALUE;
        }
        int[] leftTmp=new int[1];
        int[] rightTmp=new int[1];
        long res1=helper(root.left,leftTmp,totalSum);
        long res2=helper(root.right,rightTmp,totalSum);
        long res=Math.max(res1,res2);
        long tmp0=leftTmp[0]*(totalSum-leftTmp[0]);
        res=Math.max(res,tmp0);
        long tmp1=rightTmp[0]*(totalSum-rightTmp[0]);
        res=Math.max(res,tmp1);
        ints[0]=leftTmp[0]+rightTmp[0]+root.val;
        return res;
    }

    private int getSum(TreeNode root) {
        if(root==null){
            return 0;
        }
        return root.val+getSum(root.left)+getSum(root.right);
    }
}
```