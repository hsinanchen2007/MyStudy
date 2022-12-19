### 解题思路
对于排序数组`nums`，要想建立高度平衡的二叉搜索树，显然最优的一种的情况就是取中间的数为根，两侧分别作为左右子树。
由此，递归函数`build()`，参数传入起始点`start`和终点坐标`end`，返回TreeNode;
方法步骤如下：
1. 如果`start>end`，返回`null`;
2. 求出中点`mid=start+(end-start)/2`;根则为`root=new TreeNode(nums[mid]);`
3. 求出`root`的左右子树:`root.left=build(start,mid-1);` `root.right=build(mid+1,end);`
4. 返回`root`;
### 代码

```java
class Solution {

    private int[] nums;
    private TreeNode build(int start,int end)
    {
        if(start>end)return null;
        if(end-start+1==2)
        {
            TreeNode root=new TreeNode(nums[end]);
            root.left=new TreeNode(nums[start]);
            root.right=null;
            return root;
        }

        int mid=start+(end-start)/2;
        TreeNode root=new TreeNode(nums[mid]);

        TreeNode left=build(start,mid-1);
        TreeNode right=build(mid+1,end);
        root.left=left;
        root.right=right;
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) 
    {
        if(nums.length==0)return null;
        this.nums=nums;
        return build(0,nums.length-1);
    }
}
```