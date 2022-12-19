![2019-10-16_11-12.png](https://pic.leetcode-cn.com/2383e6255be1038edae73ea59b88b4edc28a24de13efc20db153c37ca15d0de0-2019-10-16_11-12.png)

```c
void merge(int * nums, int * tmp, int leftStart, int rightStart, int rightEnd, int reverse) {
    int cur = leftStart;
    int leftEnd = rightStart - 1;
    int numsSize = rightEnd - leftStart + 1;
    while (leftStart <= leftEnd && rightStart <= rightEnd) {
        if ((nums[leftStart] < nums[rightStart]) ^ reverse)
            tmp[cur++] = nums[leftStart++];
        else
            tmp[cur++] = nums[rightStart++];
    }
    while (leftStart <= leftEnd)
        tmp[cur++] = nums[leftStart++];
    while (rightStart <= rightEnd)
        tmp[cur++] = nums[rightStart++];
    for (int i = 0; i < numsSize; i++, rightEnd--) {
        nums[rightEnd] = tmp[rightEnd];
    }
}

// 归并排序
void mergeSort(int * nums, int * tmp, int left, int right, int reverse) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(nums, tmp, left, mid, reverse);
        mergeSort(nums, tmp, mid + 1, right, reverse);
        merge(nums, tmp, left, mid + 1, right, reverse);
    }
}

// 每个 node 储存一种解法
typedef struct _Node {
    int *data;
    int len;
    struct _Node *next;
} Node;

Node *create_node(int num) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = (int *) malloc(sizeof(int));
    node->data[0] = num;
    node->len = 1;
    node->next = NULL;

    return node;
}

// 动态规划递归求解
Node *combinationSumHelper(int *candidates, int left, int right, int target) {
    Node *head = NULL;
    Node **ptr = &head;
    // 记录上一次的值，防止重复
    int prev = -1;
    // 从前往后扫描数组
    for (int i = left; i < right; i++) {
        // 如果本次的值与上一次相同，则直接跳过，因为本次的解必然是上一次的子集
        if (prev == candidates[i])
            continue;
        prev = candidates[i];

        // 如果 candidates[i] > target，说明找不到 target 的组合
        if (target < candidates[i]) {
            break;
        }
        // 如果找到一个 candidates[i] 与 target 相等，则创造一个新组合 [target]
        else if (target == candidates[i]) {
            *ptr = create_node(target);
            break;
        }
        // 以 target - candidates[i] 作为子问题进行求解
        *ptr = combinationSumHelper(candidates, i + 1, right, target - candidates[i]);

        // 对于求得的所有子问题解，扩展为当前问题
        while (*ptr) {
            Node *node = *ptr;
            node->data = (int *) realloc((void *) node->data, sizeof(int) * (node->len + 1));
            node->data[node->len++] = candidates[i];
            ptr = &(*ptr)->next;
        }
    }

    return head;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    // 对 candidates 进行排序
    int *tmp = (int *) malloc(sizeof(int) * candidatesSize);
    mergeSort(candidates, tmp, 0, candidatesSize - 1, 0);
    free(tmp);

    // 计算最后总的组合个数
    *returnSize = 0;
    Node *head = combinationSumHelper(candidates, 0, candidatesSize, target);
    Node *node = head;
    while (node) {
        (*returnSize)++;
        node = node->next;
    }

    int **ret = (int **) malloc(sizeof(int *) * (*returnSize));
    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        node = head;
        ret[i] = node->data;
        (*returnColumnSizes)[i] = node->len;
        head = head->next;
        free(node);
    }

    return ret;
}
```