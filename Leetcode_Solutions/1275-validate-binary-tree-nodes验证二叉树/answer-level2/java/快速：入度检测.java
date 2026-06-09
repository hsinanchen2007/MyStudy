**由题意**：
    有效二叉树满足：
    1. 根节点入度==0；
    2. 非根节点入度==1；
    则，二叉树无效情况：
    1. 根节点入度>0;(如示例3)
    2. 非根节点入度!=1;
        -入度>1;(如实例2)
        -入度<1;(如示例4)
**解题思路**：
    使用usedTimes[n]标识节点i的入度，同时遍历leftChild[]和rightChild[]，leftChild[i]、rightChild[i]若不为-1，则将usedTimes[leftChild[i]]、usedTimes[rightChild[i]]入度+1；
    例如，示例4中，leftChild[0]=1，rightChild[0]=2，则i=0遍历时将usedTimes[1]、usedTimes[2]分别+1；
    为简化逻辑，本题解中将usedTimes[0]初始置为1，即特殊处理根节点入度为1，这样在遍历体中可减少根节点与非根节点的区分：子树根节点入度==0？无效，节点入度+1之前入度>0?无效;（节省时间）

**代码：**
    
```
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        //本题可省略该部分异常检测
        if(n < 1 || n != leftChild.length || leftChild.length != rightChild.length ){
            System.out.println("输入参数错误！");
            return false;
        }
        int[] usedTimes = new int[n];  //存放每个节点的入度,初始All=0
        usedTimes[0] = 1;   //为简化逻辑，将根节点入读也置为1
        for(int i = 0; i < n; i++){
            //若i节点入度==0，则存在除根结点之外的节点入度==0 -> 无效BST
            if(usedTimes[i] == 0) return false;
 
            //将i节点leftChild入度+1
            if(leftChild[i] != -1){ 
                if(usedTimes[leftChild[i]] > 0) return false;
                else usedTimes[leftChild[i]]++; 
            }

            //将i节点rightChild入度+1
            if(rightChild[i] != -1){
                if(usedTimes[rightChild[i]] > 0) return false;
                else  usedTimes[rightChild[i]]++; 
            }
        } 
        return true;
    }
}


```
