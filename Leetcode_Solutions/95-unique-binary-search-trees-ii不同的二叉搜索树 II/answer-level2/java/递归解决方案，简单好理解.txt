### 解题思路
递归方式，通过使用两个数组保存根节点的左右子树，最后将根节点的所有左右子树情况汇总到list中即可

### 代码

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
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> res = new ArrayList<>();
        // n=3时  1[2,3]    [1]2[3]    [1,2]3
        for(int i=1;i<=n;i++){
            int[] left = new int[i-1];
            for(int j=0;j<i-1;j++){
                left[j] = j+1;
            }
            int[] right = new int[n-i];
            for(int j=0;j<n-i;j++){
                right[j] = i+j+1;
            }
            //将所有的以i为根节点的树都加到res中
            res.addAll(findNodeByArray(left,right,i));
        }
        return res;
    }
    private List<TreeNode> findNodeByArray(int[] left,int[] right,int rootVal){
        List<TreeNode> res = new ArrayList<>();
        if(left.length==0&&right.length==0){
            res.add(new TreeNode(rootVal));
            return res;
        }
        //通过left获取左树的所有情况
        List<TreeNode> lres = new ArrayList<>();
        for(int i=0;i<left.length;i++){
            int[] lleft = new int[i];
            lleft = Arrays.copyOfRange(left,0,i);
            int[] lright = new int[left.length-i];
            lright = Arrays.copyOfRange(left,i+1,left.length);
            lres.addAll(findNodeByArray(lleft,lright,left[i]));
        }
        //通过right获取右树的所有情况
        List<TreeNode> rres = new ArrayList<>();
        for(int i=0;i<right.length;i++){
            int[] rleft = new int[i];
            rleft = Arrays.copyOfRange(right,0,i);
            int[] rright = new int[right.length-i];
            rright = Arrays.copyOfRange(right,i+1,right.length);
            rres.addAll(findNodeByArray(rleft,rright,right[i]));
        }
        //当此节点的左右都存在子树时
        if(lres.size()!=0&&rres.size()!=0){
            for(int i=0;i<lres.size();i++){
                for(int j=0;j<rres.size();j++){
                    TreeNode root = new TreeNode(rootVal);
                    root.left = lres.get(i);
                    root.right = rres.get(j);
                    res.add(root);
                }
            }
        }else if(lres.size()!=0){//当根节点只有左子树时
            for(int i=0;i<lres.size();i++){
                TreeNode root = new TreeNode(rootVal);
                root.left = lres.get(i);
                res.add(root);
            }
        }else if(rres.size()!=0){//当根节点只有右子树时
            for(int j=0;j<rres.size();j++){
                TreeNode root = new TreeNode(rootVal);
                root.right = rres.get(j);
                res.add(root);
            }
        }
        return res;
    }
}
```