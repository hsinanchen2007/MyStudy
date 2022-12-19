### 解题思路
递归+折半，请参考详细代码

### 代码

```java
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length==0){
            return null;
        }
        // 数组只有1个元素只返回单个节点
        if(nums.length==1){
            return new TreeNode(nums[0]);
        }
        // 找到中间的元素
        int middle = nums.length / 2;
        TreeNode node = new TreeNode(nums[middle]);

        // 如果中间数大于等于1
        // 可以继续拆分左子树
        if(middle>=1){
            int[] leftArray = Arrays.copyOfRange(nums,0,middle);
            node.left = sortedArrayToBST(leftArray);
        }else{
            node.left = null;
        }

        // 如果右子树不到数组长度
        // 可以继续拆分右子树
        if(middle+1 < nums.length){
            int[] rightArray = Arrays.copyOfRange(nums,middle+1,nums.length);
            node.right = sortedArrayToBST(rightArray);
        }else{
            node.right = null;
        }

        return node;
    }
}
```