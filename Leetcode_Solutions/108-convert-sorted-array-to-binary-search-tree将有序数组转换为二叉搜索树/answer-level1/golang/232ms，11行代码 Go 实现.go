
![image.png](https://pic.leetcode-cn.com/0248b35ac7b5a612cc7603a94bed6aa4029e4364b7895599aaeacbadfdd3792d-image.png)

递归实现

代码
```
func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums)==0 {   // 叶子节点
        return nil
    }
    mid := (0 + len(nums)-1) / 2                // 中间元素下标
    cur := new(TreeNode)                        // 创建当前节点
    cur.Val = nums[mid]                         // 获取当前节点值
    cur.Left = sortedArrayToBST(nums[0:mid])    // 获取左子树和右子树
    cur.Right = sortedArrayToBST(nums[mid+1:])
    return cur
}
```