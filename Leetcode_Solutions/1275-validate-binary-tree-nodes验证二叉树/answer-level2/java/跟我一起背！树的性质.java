就算你不知道，看完题目的样例也明白了。
## 如何判断一个图是不是一个树啊
- 每个点的入度都不能超过 1  **（见题目样例 2)**
- 入度为 0 的点不能没有 **(见样例 3)**
- 入度为 0 的点也不能超过一个 **(见样例 4)**
完事~
（本题要判断的是二叉树，但是题目已经保证了每个点的出度都小于等于 2，故不用在出度上做额外判断）

## 代码

```java
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] in=new int[n];
        for(int i=0;i<n;i++){
            if(leftChild[i]>=0) in[leftChild[i]]++;
            if(rightChild[i]>=0) in[rightChild[i]]++;
        }
        int rootCount=0;
        for(int i=0;i<n;i++){
            if(in[i]>1) return false;
            if(in[i]==0) {
                if(rootCount>0) return false;
                rootCount++;
            }
        }
        if(rootCount==0) return false;
        return true;
    }
}
```