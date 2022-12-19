![WechatIMG611.jpeg](https://pic.leetcode-cn.com/3a5c043aa8fc88cdaa0ecaaacb0f4c10afa825ba61e1a8760cbe73af866f2ba5-WechatIMG611.jpeg)

参数为有序数组，平衡二叉树节点值大于左子数值小于右子树值，二分法可以有效解决问题。基本思想：
1:根结点值为中位数值
2:左子树，利用左半部分数组进行递归操作。同理，右子树为右半部分数组递归结果。
3:处理好临界值，进行操作时，要求左数组存在，或者右数组存在时才进行相应子树的递归操作。
代码如下：
```
public  TreeNode sortedArrayToBST(int[] nums) {
        TreeNode retVal;
        int left = 0, right, mid;
        if (nums.length > 0) {
            right = nums.length - 1;
            mid = (left + right) >>> 1;
            retVal = new TreeNode(nums[mid]);
            if (left <= mid - 1) {
                int[] numsL = Arrays.copyOfRange(nums, left, mid);
                retVal.left = sortedArrayToBST(numsL);
            } else
                retVal.left = null;
            if (mid + 1 <= right) {
                int[] numsR = Arrays.copyOfRange(nums, mid + 1, right + 1);
                retVal.right = sortedArrayToBST(numsR);
            } else {
                retVal.right = null;
            }
        } else {
            retVal = null;
        }
        return retVal;
    }
```

