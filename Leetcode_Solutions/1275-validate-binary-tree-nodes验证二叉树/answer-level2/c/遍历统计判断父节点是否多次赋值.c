### 解题思路
1.建立一个节点数组，针对每一个节点，判断其父节点是否存在多次赋值，父节点每赋值一次，nullparenetCount--；
2.最后判断是否只有一个父节点，如果为0，表示环，大于1表示有多个root节点；
3.特殊情况：其中部分成环，存在单独的root节点，需要特殊判断

### 代码

```c
typedef struct{
    int parent;
    int lChild;
    int rChild;
}BinTree, *BTree;

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){

    if (n == 0) {
        return true;
    }else if((leftChildSize != rightChildSize)) {
        return false;
    }

    BTree obj = (BTree)malloc(sizeof(BinTree) * n);
    if(obj == NULL) {
        return false;
    }
    
    for (int i = 0; i < n; i++) {
        obj[i].parent = -1;
        obj[i].lChild = -1;
        obj[i].rChild = -1;
    }

    int flag = true;

    int nullParentCount = n;
    for (int i = 0; i < n; i++) {
        obj[i].lChild = leftChild[i];
        if (leftChild[i] != -1) {
            if (obj[leftChild[i]].parent != -1) {
                flag = false;
                break;
            }
            obj[leftChild[i]].parent = i;
            nullParentCount--;
        }
        
        obj[i].rChild = rightChild[i];
        if (rightChild[i] != -1) {
            if (obj[rightChild[i]].parent != -1) {
                flag = false;
                break;
            }
            obj[rightChild[i]].parent = i;
            nullParentCount--;
        }

        if((i != 0) && (obj[i].parent == -1) && (obj[i].lChild == -1) && (obj[i].rChild == -1)) {
            flag = false;
        }
    }

    if (nullParentCount != 1) {
        flag = false;
    }

    return flag;
}
```