### 解题思路
中序遍历，然后把出现的众数存储在list集合中。

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
    int maxNum=0;//某个节点的值出现最大次数。
    int thisNum=1;//某个节点这次出现是第几次出现。
    List<Integer> list=new ArrayList<Integer>();
    TreeNode pre=null;
    public int[] findMode(TreeNode root) {
        helper(root);
        int len=list.size();
        int []arr=new int[len];
        for(int i=0;i<len;i++){
            arr[i]=list.get(i);
        }
        return arr;

    }
    public void helper(TreeNode root){
        if(root==null) return;
        helper(root.left);
        if(pre!=null&&pre.val==root.val){//当前值等于前一个节点的值时则表明这个节点再一次出现。
            thisNum++;
        }else{
            thisNum=1;//表明这个节点第一次出现
        }
        if(thisNum==maxNum){//当最大出现次数和节点总共出现的次数相等的时候，则把这个节点加入到数组中。
            list.add(root.val);
        }else if(thisNum>maxNum){//表明众数出现，更新最大次数，并把节点存入到数组中。
            maxNum=thisNum;
            list.clear();
            list.add(root.val);
        }
        pre=root;
        helper(root.right);
    }
}
```