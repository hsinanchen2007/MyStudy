### 解题思路
1.众数即为出现次数最多的元素，首先先设maxCount=1，依次得出当前出现最多的次数，如果大于maxCount,
则更新最大次数，并清空集合，从新放入数据。如果小于maxCount，则进行下一个比较，如果等于，直接放入集合数据。
2.利用中序遍历，即可得到一个升序排列的数据，便于比较。

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
    TreeNode preNode=null;
    int curCount=1,maxCount=1;
    public int[] findMode(TreeNode root) {
        List<Integer> list=new LinkedList<>();
        inOrder(root,list);
        int[] times=new int[list.size()];
        int i=0;
        for(int num:list)
            times[i++]=num;
        return times;
    }
    public void inOrder(TreeNode root,List<Integer> nums){
        if(root==null) return;
        inOrder(root.left,nums);
        if(preNode!=null){
            if(root.val==preNode.val) curCount++;
            else curCount=1;
        }
        if(curCount>maxCount){
            maxCount=curCount;
            nums.clear();
            nums.add(root.val);
        }
        else if(curCount==maxCount){
           nums.add(root.val); 
        }
        preNode=root;
        inOrder(root.right,nums);
    }
}
```