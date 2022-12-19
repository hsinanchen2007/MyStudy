### 解题思路
# 中序+后序 判断后序遍历是否是BST的后序遍历

判断是否为二叉搜索树的后序序列，首先我们要知道，BST是个中序序列递增的，所以我们可以根据将后序排序得到中序，然后遍历中序序列，直到找到与后序的最后一个元素（根节点）相同的下标，找到处理后break（提高时间效率），判断右子树是否都大于根节点，都大于继续递归右子树；判断左子树是否都小于根节点，都小于继续递归左子树；最后判断左右子树都符合条件的话，返回true，否则false。

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if(postorder.length==0){
            return true;
        }
        
        int [] temp=Arrays.copyOf(postorder,postorder.length);
        //中序
        Arrays.sort(temp);
        boolean right=false;
        boolean left=false;
        //遍历中序
        for(int i=0;i<postorder.length;i++){
            //找到根节点
            if(temp[i]==postorder[postorder.length-1]){
                if(isBig(Arrays.copyOfRange(postorder,i,postorder.length-1),temp[i])){
                    right = verifyPostorder(Arrays.copyOfRange(postorder,i,postorder.length-1));
                }else{
                    return false;
                }
                if(isSmall(Arrays.copyOfRange(postorder,0,i),temp[i])){
                    left = verifyPostorder(Arrays.copyOfRange(postorder,0,i));
                }else{
                    return false;
                }
                //找到就没必要再遍历后序的下标，直接跳出
                break;
                
                
            }
            
        }
        //判断左右两边
        if(right==true && left==true){
            return true;
        }
        return false;
    }
    //判断右子树是否都大于根节点
    public boolean isBig(int [] a,int n){
        int i;
        for(i=0;i<a.length;i++){
            if(a[i]<n){
                break;
            }
        }
        if(i==a.length){
            return true;
        }
        return false;
    }
    //判断左子树是否都小于根节点
    public boolean isSmall(int [] a,int n){
        int i;
        for(i=0;i<a.length;i++){
            if(a[i]>n){
                break;
            }
        }
        if(i==a.length){
            return true;
        }
        return false;
    }
}
```