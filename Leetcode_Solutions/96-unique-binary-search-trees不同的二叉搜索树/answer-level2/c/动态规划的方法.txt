### 解题思路
此处撰写解题思路

### 代码

```c
/*
    BST:二叉搜索树，它的左、右子树也分别为二叉排序树，左子树比根节点小，右子树比根节点大
*/

int numTrees(int n) {
    /* 感觉是一个动态规划，或者递归 */
    int number[1000] = {0};
    /*
        假设n-1个数已经知道了，加入第n个数

        a(n) = a(0) * a(n-1)  + a(1) * a(n-2) + ...;

    */
    number[0] = 1;
    number[1] = 1;
    number[2] = 2;
    number[3] = 5;

    for (int i = 4; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            number[i] += number[j] * number[i-j-1];
        }
    }
    return number[n];

}
```