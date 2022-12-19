### 解题思路
此处撰写解题思路
对于搜索二叉树的后续遍历，最先遍历的是最左侧的左叶子节点，最后遍历的是根节点，因此反映在数组中则是，数组首元素为左叶子节点，末元素是根节点。根节点的右节点大于根节点，左节点小于根节点。根据此条件划分为两个子树。
递归出口，如果start>=end，返回true，说明此时二叉搜索树的条件都已经满足
递归操作： 定义两个临时变量用来记录划分左右节点的位置，按照右子树大于根节点的条件，j--,直到不满足这个条件，此时j已经到左子树的位置，按照左子树小于根节点i++直到不满足条件，此时i已经到右子树的位置；判断划分位置的大小，如果i<j,则出现矛盾因此返回false。
返回值： 根据划分位置遍历左子树和右子树。

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        //数组的末尾是根节点，根节点的前一个是右子树节点
        //数组的首个元素是左叶子节点，是二叉树的最小元素
        if(postorder.length == 0)
            return true;
        return verify(postorder,0,postorder.length-1);
    }

    private boolean verify(int[] array, int start, int end){
        if(start >= end)
            return true;
        int i = start, j = end - 1;
        while(i < end && array[i] < array[end]){
            i++;
        }
        while(j >= start && array[j] > array[end]){
            j--;
        }
        if(i < j)
            return false;
        return verify(array,j+1,end-1) && verify(array,start,i-1);
    }
}
```