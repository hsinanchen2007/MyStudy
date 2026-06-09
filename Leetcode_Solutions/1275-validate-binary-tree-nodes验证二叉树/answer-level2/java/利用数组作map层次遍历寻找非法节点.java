
比较直接的暴力法，用int数组创建map，0表示当前节点的父节点，1,2,表示左右子节点。
遍历输入的两个数组，当检查到非法情况时直接返回
1.当前节点的左右子节点是否与父节点相同，相同则非法。
2.当前节点的左右子节点是否已经有父节点，已有则非法。
3.除了根节点以外的节点是否存已经存在父节点，不存在则非法。

```
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[][] map = new int[n][3];
        for(int[] l:map){
            Arrays.fill(l,-1);  
        }
     
        for(int i = 0;i<n;i++){         
            if(i>0 && map[i][0]==-1) return false;
           
            if(leftChild[i] > -1){
                if(leftChild[i] == map[i][0]) return false;
                map[i][1] = leftChild[i];
                if(map[leftChild[i]][0] != -1)return false;
                map[leftChild[i]][0] = i;
            }
           
            if(rightChild[i] > -1){ 
                if(rightChild[i] == map[i][0]) return false;
                map[i][2] = rightChild[i];
                if(map[rightChild[i]][0] != -1)return false;
                map[rightChild[i]][0] = i; 
            }         
        }
        
        return true;

    }
}
```
