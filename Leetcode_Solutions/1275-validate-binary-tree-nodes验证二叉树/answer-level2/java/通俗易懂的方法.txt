按照题目的提示信息，如果能构成一棵树，每个节点只有一个父节点，只有根节点没有父节点。
用parent数组来表示每个节点父节点的位置。
```
if (leftChild[i] != -1){
    //设置父节点
    if (parent[leftChild[i]] == -1){
        parent[leftChild[i]] = i;
    }else {
    //一个节点不可能有两个不同的父节点，返回false
        return false;
    }
}
```
设置完所有节点的父节点后，再遍历一次parent数组
```
for (int p : parent){
    if (p == -1){
        count++;
    }
}
```
count表示没有父节点的根节点，count为1表示这是一棵树，否则false。
完整代码如下：
```
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] parent = new int[n];
        Arrays.fill(parent,-1);
        for (int i = 0;i<n;i++){
            if (leftChild[i] != -1){
                if (parent[leftChild[i]] == -1){
                    parent[leftChild[i]] = i;
                }else {
                    return false;
                }
            }
            if (rightChild[i] != -1){
                if (parent[rightChild[i]] == -1){
                    parent[rightChild[i]] = i;
                }else {
                    return false;
                }
            }
        }
        int count = 0;
        for (int p : parent){
            if (p == -1){
                count++;
            }
        }
        if (count != 1)
            return false;
        else
            return true;
    }
```
