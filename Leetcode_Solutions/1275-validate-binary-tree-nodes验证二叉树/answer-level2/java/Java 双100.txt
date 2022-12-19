### 解题思路
此处撰写解题思路

### 代码
1、统计每个节点的入度，如果存在节点入度大于2或总入度不等于n-1则返回false,其他返回true
```java
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] table = new int[n];
        int in = 0;
        for(int i=0;i<leftChild.length;i++){
            if(leftChild[i]==-1) continue;
            in++;
            table[leftChild[i]] +=1;
        }
        for(int i=0;i<rightChild.length;i++){
            if(rightChild[i]==-1) continue;
            in++;
            table[rightChild[i]] +=1;
        }
        for(int i=0;i<n;i++){
            if(table[i]>1) return false;
        }
        if(in!=n-1) return false;
        return true;
    }
}
```