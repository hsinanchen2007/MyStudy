### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct tagNode {
    int pos[2];
    int len;
} Node;

int cmp(const Node *a, const Node *b) {
    return (a->len - b->len);
}
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int length = R * C;
    int **data = (int **)calloc(1, sizeof(int *) * length);
    Node *input = (Node *)calloc(1, sizeof(Node) * length);
    int i, j, row, col;
    int index = 0;

    *returnColumnSizes = (int *)malloc(sizeof(int) * length);
    //先存入input，然后对input排序，最后把input.pos的地址赋给data。
    for (i = 0; i < R; i++) {
        row = r0 - i; 
        if (row < 0) {
            row = 0 - row;
        }
        for (j = 0; j < C; j++) {
            col = c0 - j;
            if (col < 0) {
                col = 0 - col;
            }
            input[index].pos[0] = i;
            input[index].pos[1] = j;
            input[index].len = row + col;
            (*returnColumnSizes)[index] = 2;
            index++;
        }
    }

    qsort(input, length, sizeof(Node), cmp);
    for (i = 0; i < length; i++) {
        data[i] = input[i].pos;
    }

    *returnSize = length;
    return data;
}
```