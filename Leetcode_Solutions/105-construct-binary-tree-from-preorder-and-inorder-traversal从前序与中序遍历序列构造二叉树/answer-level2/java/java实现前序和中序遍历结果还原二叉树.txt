### 解题思路
此处撰写解题思路
这道题主要是需要理解通过前序和中序还原二叉树的基本算法和伪码，再通过java实现出来就相对简单了。
`int pre[] = {1,2,4,7,3,5,6,8};
int in[] = {4,7,2,1,5,3,8,6};`
前序和中序如上
每次递归执行的算法：根节点位于pre的第一个，in的根节点的左边是其左子树，右边是其右子树，即为，左根右，因此可以通过每次抽出其根节点和左右子树来实现一次递归
而每个子子树又同样适合以上算法，
我们抽出根节点1 然后进入in中进行分割，分为左子树4，7，2 右子树 5，3，8，6
再根据两个子树 去pre里面找到 左子树2，4，7 右子树 3，5，6，8
根据左子树第一个为 2 即为根节点，再到对应的in 里面找，得到2的左子树为4，7 再执行相同的算法
顺序，pre-> in ->pre ->in 循环往复，代码如下
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int nodes = 0;
    public TreeNode buildTree(int [] pre,int []in){
        if(pre.length==0||in.length==0||pre.length!=in.length){
            return null;
        }
        TreeNode r = new TreeNode(pre[0]);
        r.left = buildTree(new_array(indexOf(in,pre[0]),1,pre),new_array(indexOf(in,pre[0]),0,in)); 
        r.right = buildTree(new_array(in.length-indexOf(in,pre[0])-1,indexOf(in,pre[0])+1,pre),new_array(in.length-indexOf(in,pre[0])-1,indexOf(in,pre[0])+1,in));
        return r;
    }
    private int[] new_array(int length,int begin,int[] arr){ 
        //根据子树长度和起始位置生成新的子树列表用于下次递归
        int [] new_array = new int[length];
        int j = 0;
        for(int i=begin;i<begin+length;i++){
            new_array[j] = arr[i];
            j++;
        }
        return new_array;
    }
    private int indexOf(int []arr,int key){
        //根据数值获取对应索引
        for(int i=0;i<arr.length;i++){
            if(key==arr[i]){
                return i;
            }
        }
        return -1;
    }
}
```
执行用时和内存消耗都比较高
这里推荐先用对列表做字典处理，这样可以有效降低每次迭代的查询时间（从o（n）降低到o（1））.