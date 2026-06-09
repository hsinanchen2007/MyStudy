// ```javascript []
var rangeSumBST = function (root, L, R) {
    if (root === null) {
        return 0
    }
    if (root.val > R) {
        return rangeSumBST(root.left, L, R)
    }
    if (root.val < L) {
        return rangeSumBST(root.right, L, R)
    }
    return root.val + rangeSumBST(root.right, L, R) + rangeSumBST(root.left, L, R)
};

/**
 * 解题思路：
 * 
 *  1. 获取左树与右树之间的值并且相加
 *  2. 判断如果当前值大于右树则递归左树，小于左树递归右树
 *  3. 当然还有漏网之🐟【相等的情况】，这就交给下一步去做相等的情乱同时去左树和右树进行递归
 */
// ```

