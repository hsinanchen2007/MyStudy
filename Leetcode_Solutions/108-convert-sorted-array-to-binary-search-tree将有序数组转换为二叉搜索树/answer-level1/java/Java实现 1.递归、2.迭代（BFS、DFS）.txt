### 解题思路
1. 二分法找到中间节点，作为**根节点**
2. 使用二分法在左边区间找到中间节点作为**左节点**
3. 使用二分法在左边区间找到中间节点作为**右节点**
4. 然后一直寻找下去
5. 注意使用二分法int值相加时会越界，因此使用`>>>`无符号右移运算更为合适
    - 下面程序运行情况可以看出
    ```
    System.out.println(Integer.toBinaryString((Integer.MAX_VALUE)));
    System.out.println(Integer.toBinaryString((Integer.MAX_VALUE+Integer.MAX_VALUE)>>1));
    System.out.println(Integer.toBinaryString((Integer.MAX_VALUE+Integer.MAX_VALUE)>>>1));
    //运行结果
    1111111111111111111111111111111
    11111111111111111111111111111111
    1111111111111111111111111111111
    ```

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
    /*
     * 使用递归
     * 取中间的值作为节点
     * 1. 二分：如果长度是奇数取中位数，长度偶数取中间较大的那个
     * */
    public TreeNode sortedArrayToBST(int[] nums) {
        TreeNode treeNode = initTree(nums,0,nums.length-1);
        return treeNode;
    }

    public TreeNode initTree(int[] nums,int le,int ri){
        if(le==ri){
            return new TreeNode(nums[le]);
        } else if(le>ri){
            return null;
        }else{
            int mid = (le+ri+1)>>1;
            TreeNode t = new TreeNode(nums[mid]);
            t.left=initTree(nums,le,mid-1);
            t.right=initTree(nums,mid+1,ri);
            return t;
        }
    }
    class MyTreeNode{
        public TreeNode node;
        public int le;
        public int ri;
        public MyTreeNode(TreeNode node,int le,int ri){
            this.node=node;
            this.le=le;
            this.ri=ri;
        }
    }
    /*
     * BFS迭代方法模拟递归解决
     * */
    public TreeNode sortedArrayToBST1(int[] nums) {
        LinkedList<MyTreeNode> list = new LinkedList<>();
        if(nums.length==0){
            return null;
        }
        TreeNode root = new TreeNode(nums[(0+nums.length-1+1)>>>1]);
        list.add(new MyTreeNode(root,0,nums.length-1));
        while (!list.isEmpty()){
            int len = list.size();
            for(int i=0;i<len;i++){
                MyTreeNode myTreeNode = list.pollFirst();
                TreeNode node = myTreeNode.node;
                int le = myTreeNode.le;
                int ri = myTreeNode.ri;
                if(le<ri){
                    int mid = (le+ri+1)>>>1;
                    if(le<=mid-1){
                        int index = le==mid-1?le:(le+mid-1+1)>>>1;
                        node.left = new TreeNode(nums[index]);
                        MyTreeNode treeNodeLeft = new MyTreeNode(node.left,le,mid-1);
                        list.add(treeNodeLeft);
                    }
                    if(mid+1<=ri){
                        int index = mid+1==ri?ri:(mid+1+ri+1)>>>1;
                        node.right = new TreeNode(nums[index]);
                        MyTreeNode treeNodeRight = new MyTreeNode(node.right,mid+1,ri);
                        list.add(treeNodeRight);
                    }
                }
            }
        }
        return root;
    }
    /*
     * DFS迭代方法模拟递归解决
     * */
    public TreeNode sortedArrayToBST2(int[] nums) {
        LinkedList<MyTreeNode> list = new LinkedList<>();
        if(nums.length==0){
            return null;
        }
        TreeNode root = new TreeNode(nums[(0+nums.length-1+1)>>>1]);
        list.add(new MyTreeNode(root,0,nums.length-1));
        while (!list.isEmpty()){
            MyTreeNode myTreeNode = list.pollLast();
            TreeNode node = myTreeNode.node;
            int le = myTreeNode.le;
            int ri = myTreeNode.ri;
            if(le<ri){
                int mid = (le+ri+1)>>>1;
                if(mid+1<=ri){
                    int index = mid+1==ri?ri:(mid+1+ri+1)>>>1;
                    node.right = new TreeNode(nums[index]);
                    MyTreeNode treeNodeRight = new MyTreeNode(node.right,mid+1,ri);
                    list.add(treeNodeRight);
                }
                if(le<=mid-1){
                    int index = le==mid-1?le:(le+mid-1+1)>>>1;
                    node.left = new TreeNode(nums[index]);
                    MyTreeNode treeNodeLeft = new MyTreeNode(node.left,le,mid-1);
                    list.add(treeNodeLeft);
                }
            }
        }
        return root;
    }
}
```