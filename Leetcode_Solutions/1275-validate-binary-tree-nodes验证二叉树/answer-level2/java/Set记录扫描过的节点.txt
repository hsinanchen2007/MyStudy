### 解题思路
该题树的遍历方式类似广度优先搜索的层次遍历，这样就决定了，除了根节点之外的每个节点遍历到的时候，**他的父节点都是之前已经遍历过的**。只要该节点的编号出现在之前遍历的节点中，同时，左右孩子没有出现过，就表示该节点是一个合法节点，否则，就是非法节点。（成环了）

用一个Set来记录之前的节点，如果新来的节点**不在**set中，则表示这是一个新的root节点。非法，左右孩子节点**存在**set中，则表示成环了。同样非法

### 代码

```java
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        Set<Integer> set = new HashSet<>(n);// 初始化，防止频繁扩容
        set.add(0);
        for (int i = 0;i < leftChild.length ;i++){
            if (!set.contains(i)){
                return false;// 根节点要包含，否则就是新的一个root
            }
            if (leftChild[i] != -1){
                if (set.contains(leftChild[i])){
                    return false;// 左节点之前不能存在，否则成环
                }
                set.add(leftChild[i]);
            }
            if (rightChild[i] != -1){
                if (set.contains(rightChild[i])){
                    return false;// 右节点之前不能存在，否则成环
                }
                set.add(rightChild[i]);
            }
        }
        return true;
    }
}
```