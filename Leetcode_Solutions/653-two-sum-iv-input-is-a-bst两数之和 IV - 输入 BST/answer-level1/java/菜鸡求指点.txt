### 解题思路

执行用时 :7 ms, 在所有 Java 提交中击败了21.59%
内存消耗 :41.8 MB, 在所有 Java 提交中击败了55.69%

中序遍历出由小到大的数组，数组长度不可变，因为我太菜，不知道别的办法了，只好放进list，然后再进行比较，
前后两个标识位，相加小于t，最左边的标识位右移，反之，最右边的标识位左移。调试发现好多没考虑到的条件，
一点一点加。

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
    public List<Integer> list=new ArrayList<>();
    public boolean findTarget(TreeNode root, int k) {    
        midFind(root);
        int i=0;
        int j=0;
        int low=0;
        int high=list.size()-1;
        if(low==high){
            return false;
        }
        while(list.get(low)+list.get(high)!=k){
            if(list.get(low)+list.get(high)<k){
                low++;
            }else if(list.get(low)+list.get(high)>k){
                high--;
            }
            j++;
            if(j>=list.size()*(list.size()-1)/2||low>=high){
                return false;
            }
        }
        return true;
    }

    public void midFind(TreeNode node){
        if(node==null)return;
        midFind(node.left);
        list.add(node.val);
        midFind(node.right);
        
    }

}
```