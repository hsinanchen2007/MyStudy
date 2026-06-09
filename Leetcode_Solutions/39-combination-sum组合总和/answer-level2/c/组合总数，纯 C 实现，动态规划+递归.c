![2019-10-15_15-55.png](https://pic.leetcode-cn.com/02301f25a08e4e676a0c654e8de3889267216bcfcd1753e15c6ea8f6553bf34c-2019-10-15_15-55.png)

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
Node *combinationSumHelper(int *candidates, int candidatesSize, int target, int max) {
    Node *head = NULL;
    Node **ptr = &head;
    // 从前往后扫描数组
    for (int i = 0; i < candidatesSize; i++) {
        // 如果 candidates[i] > target，说明找不到 target 的组合
        // 如果 candidates[i] > max，说明会出现重复组合
        if (target < candidates[i] || max < candidates[i]) {
            break;
        }
        // 如果找到一个 candidates[i] 与 target 相等，则创造一个新组合 [target]
        else if (target == candidates[i]) {
            *ptr = create_node(target);
            break;
        }
        // 以 target - candidates[i] 作为子问题进行求解，并且子问题的解最大值不超过 candidates[i]
        *ptr = combinationSumHelper(candidates, candidatesSize, target - candidates[i], candidates[i]);

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

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    // 就地去除重复数字，newSize 为新数组的长度
    int newSize = 1;
    for (int i = 1; i < candidatesSize; i++) {
        if (candidates[i] != candidates[newSize - 1]) {
            candidates[newSize] = candidates[i];
            newSize++;
        }
    }

    // 对 candidates 进行排序
    int *tmp = (int *) malloc(sizeof(int) * newSize);
    mergeSort(candidates, tmp, 0, newSize - 1, 0);
    free(tmp);

    // 计算最后总的组合个数
    *returnSize = 0;
    Node *head = combinationSumHelper(candidates, newSize, target, target);
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
    free(head);

    return ret;
}
```