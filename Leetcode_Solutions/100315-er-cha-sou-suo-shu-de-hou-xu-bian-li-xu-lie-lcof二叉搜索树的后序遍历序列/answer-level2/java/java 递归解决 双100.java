### 解题思路
1.二叉查找树，基本特征为根节点的数比左子树大，比右子树小
2.后序遍历为【左右根】，所以数组的最后一个元素为根节点，从后向前遍历，找到第一个比根节点小的数，即为左右子树的分水岭
    2.1》如果根节点左边的数全部小于根，则此根无右子树
    2.2》如果根节点左边的数全部大于根，则此根无左子树
    2.3》如果根节点左边数据先大于根后小于根，则此根存在左右子树，且第一个比根小的数为左右子树分水岭
    2.4》如果从根向前遍历时，发现了比根大的数，同时，再此之前发现过比根小的数，则直接返回false（因为此情况违反了二叉查找树的规律）

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if(postorder.length==0){
            return true;
        }
        return recursion(postorder,0,postorder.length-1);
    }

    public boolean recursion(int[] postorder,int left,int right){
        if(left==right){
            return true;
        }
        int root=postorder[right];
        int ltreeEnd=-1;
        boolean hasRightTree=false;
        boolean hasLeftTree=false;
        for(int i=right-1;i>=left;i--){
            if(postorder[i]>root){
                //证明存在右子树
                if(hasLeftTree){
                    //在右子树之前出现了左子树的值，直接返回false
                    return false;
                }
                hasRightTree=true;
            }else{
                if(!hasLeftTree){
                    //记录左右子树的界限
                    ltreeEnd=i;
                }
                hasLeftTree=true;
            }
        }
        boolean res=true;
        if(hasLeftTree){
            res=res&(recursion(postorder,left,ltreeEnd));
        }
        //处理边界值
        ltreeEnd=(ltreeEnd==-1)?left:ltreeEnd+1;
        if(hasRightTree){
            res=res&(recursion(postorder,ltreeEnd,right-1));
        }
        return res;
    }
}
```