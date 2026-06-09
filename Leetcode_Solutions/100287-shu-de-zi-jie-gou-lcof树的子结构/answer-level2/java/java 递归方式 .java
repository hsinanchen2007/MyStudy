```
    public class Pms26 {

    boolean compare = false;

    public boolean isSubStructure(TreeNode A, TreeNode B) {
        //如果都为true，则说明相等
        if (A== null && B == null) {
            return true;
        }
        //如果发现两变不等，则返回false
        if (A == null || B == null) {
            return false;
        }
        if (A.val != B.val) {
            //如果开始比较了，则不等返回false
            if (compare) {
                return false;
            }
            //如果还没有开始比较过，则说明还需要看是否在A的子树中
            return isSubStructure(A.left, B) || isSubStructure(A.right, B);
        } else {
            //将比较标志置为true
            compare = true;
            boolean result = true;
            //只对不为空的分支做比较，否则会被第if (A == null || B == null) 这个条件导致判断错误
            if (B.left != null) {
                result = result && isSubStructure(A.left, B.left);
            }
            if (B.right != null) {
                result = result && isSubStructure(A.right, B.right);
            }
            return  result;
        }
    }

}
```
