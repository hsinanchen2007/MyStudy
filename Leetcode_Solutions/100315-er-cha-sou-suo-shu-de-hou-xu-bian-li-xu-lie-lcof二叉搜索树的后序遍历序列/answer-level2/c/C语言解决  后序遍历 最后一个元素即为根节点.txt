### 解题思路
1. 递归判断，最后一个元素即为根，若左子树中出现大于根的元素返回false；若右子树中出现小于根的元素返回false；
2. 先找到左右子树分界index，然后递归判断左右子树；
3. 注意返回条件。

### 代码

```c

bool IsPostorder(int* postorder, int start, int end) 
{
    if (start >= end) {
        return true; // 此条件很重要
    }

    int rightTreeIndex = end;
    for (int i = start; i < end; i++) {
        if (postorder[i] > postorder[end]) {
            rightTreeIndex = i;
            break; // break 重点
        }
    }

    bool leftFlag = true;
    bool rightFlag = true;
    // 若右子树有出现小于根的，则标记false
    for (int i = rightTreeIndex; i < end; i++) {
        if (postorder[i] < postorder[end]) {
            rightFlag =  false;
        }
    }
    if (rightFlag) {
        rightFlag = IsPostorder(postorder, rightTreeIndex, end - 1);
    }

    // 若左子树有出现大于根的，则标记false
    for (int i = start; i < rightTreeIndex; i++) {
        if (postorder[i] > postorder[end]) {
            leftFlag = false;
        }
    }
    if (leftFlag) {
        leftFlag = IsPostorder(postorder, start, rightTreeIndex - 1);
    }

    if (leftFlag && rightFlag) {
        return true;
    } else {
        return false;
    }
}

bool verifyPostorder(int* postorder, int postorderSize)
{
    if (postorder == NULL || postorderSize == 0) {
        return true; // 输入[]是返回true
    }

    return IsPostorder(postorder, 0, postorderSize - 1);
}
```