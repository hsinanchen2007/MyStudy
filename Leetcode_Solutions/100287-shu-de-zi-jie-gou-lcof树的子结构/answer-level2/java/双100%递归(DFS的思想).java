### 递归思路
很自然的思路！！
**递归出口：**
AB同时为null false； 
A为空B不为空 false；
***如果A和B的根节点值相同，那么接下来做判断的时候，若A不为空，B为空则可以返回true***
***如果A和B的根节点值相同，那么接下来做判断的时候，若A和B的子树的根节点也必须相等，否则返回false***
***如果A和B的根节点值不同，那么若A不为空，B为空则false，等价于题目说明的[空树不等成为子树]***
例子：A = [1,0,1,-4,-3], B = [1,-4]
**递归体：**
1. 若AB的根节点值**相等**，则B的左子树是A的左子树的子结构 && B的右子树是A的右子树的子结构 =>true
2. 若AB的根节点值**不相等**，则B是A的左子树的子结构 || B是A的右子树的子结构 =>true
**总结**
通过以上分析，可以得知，在递归的时候，需要有一个参数存储A/B上一次递归判断的时候，A和B的根节点值是否相同，因此
这里使用**boolean isSub(TreeNode A, TreeNode B, boolean b)**作为辅助函数


### 代码

```java
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        return isSub(A, B, false);
    }
    private boolean isSub(TreeNode A, TreeNode B, boolean b){
        if(A == null && B == null){
            return true;
        }
        if(A == null && B != null){
            return false;
        }
        if(A != null && B == null){
            if(b == true){
                return true;
            }
            return false;
        }
        if(A.val == B.val){
            return isSub(A.left, B.left, true) && isSub(A.right, B.right, true);
        }else{
            if(b == true){
                return false;
            }
            return isSub(A.left, B, false) || isSub(A.right, B, false);
        }
    }
}
```