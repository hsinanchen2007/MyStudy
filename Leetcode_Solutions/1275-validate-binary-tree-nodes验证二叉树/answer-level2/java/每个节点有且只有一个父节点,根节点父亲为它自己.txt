```
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        //每个节点有且只有一个父节点,0是root,父节点为自己,-2表示没有父节点
        int[] parent = new int[n];
        Arrays.fill(parent, -2);
        parent[0] = 0;
        for (int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];
            if (left != -1) {
                if (parent[left] != -2) {
                    return false;
                }
                parent[left] = i;
            }
            if (right != -1) {
                if (parent[right] != -2) {
                    return false;
                }
                parent[right] = i;
            }
        }
        //不能存在没有父节点的节点
        for (int i = 0; i < parent.length; i++) {
            if (parent[i] == -2) {
                return false;
            }
        }
        return true;
    }
```
