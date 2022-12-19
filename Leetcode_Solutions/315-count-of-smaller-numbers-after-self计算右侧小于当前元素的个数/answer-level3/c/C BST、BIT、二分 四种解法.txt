【直接利用BST】
48 ms	23.7 MB
比较难想到

```
#include <stdio.h>

struct BstNode {
    int val;
    int smallCnt;
    struct BstNode *left;
    struct BstNode *right;
};

static struct BstNode g_root;

static int g_smallCnt;
static struct BstNode *AddNode(struct BstNode *root, int val)
{
    if (root == NULL) {
        root = (struct BstNode *)calloc(1, sizeof(struct BstNode));
        root->val = val;
        return root;
    }
    /* 如果val小于等于root->val，说明val不会大于已有的值，所以g_smallCnt不更新，只需要更新小于该节点val的节点个数 */
    if (root->val >= val) {
        root->smallCnt++;
        root->left = AddNode(root->left, val);
    /* 如果val大于root->val，说明root节点以及root的左子树节点都是小于val的，+1是表示root节点本身 */
    } else {
        g_smallCnt += root->smallCnt + 1;
        root->right = AddNode(root->right, val);
    }
    
    return root;
}

int* countSmaller(int* nums, int numsSize, int* returnSize){
    int i;
    int *ans = (int *)calloc(1, sizeof(int) * numsSize);

    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    memset(&g_root, 0, sizeof(g_root));
    g_root.val = nums[numsSize - 1];

    for (i = numsSize - 2; i >= 0; i--) {
        g_smallCnt = 0;
        AddNode(&g_root, nums[i]);
        ans[i] = g_smallCnt;
    }

    *returnSize = numsSize;
    return ans;
}
```

【间接利用BST】
52 ms	29.1 MB
和树状数组思路一样
```
#include <stdio.h>

struct RNode {
    int val;
    int index;
    int rank;
};

static struct RNode *g_record;
static int g_recordIndex;

typedef struct SegNode {
    int sum;
    int begin, end;
    struct SegNode *left, *right;
} NumArray;

static NumArray *AddNode(int *nums, int i, int j)
{	
    NumArray *p, *leftP, *rightP;
    int mid;

    p = (NumArray *)calloc(1, sizeof(NumArray));
    if (i == j) {
        p->begin = p->end = i;
        p->sum = nums[i];
        return p;
    }
    mid = (i + j) / 2;
    leftP = AddNode(nums, i, mid);
    rightP = AddNode(nums, mid + 1, j);
    p->begin = i;
    p->end = j;
    p->left = leftP;
    p->right = rightP;
    p->sum = leftP->sum + rightP->sum;
    return p;
}

static NumArray* numArrayCreate(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return NULL;
    }
    return AddNode(nums, 0, numsSize - 1);
}

static NumArray *UpdateNode(NumArray *root, int val, int index)
{	
    NumArray *p;
    int mid;

    if (root->begin == root->end) {
        root->sum = val;
        return root;
    }
    mid = (root->begin + root->end) / 2;
    if (index <= mid) {
        UpdateNode(root->left, val, index);
    } else {
        UpdateNode(root->right, val, index);
    }
    root->sum = root->left->sum + root->right->sum;
    return root;
}

static int numArraySumRange(NumArray* root, int i, int j) {
    int mid, leftSum, rightSum;
    if (i == root->begin && j == root->end) {
        return root->sum;
    }
    mid = (root->begin + root->end) / 2;
    leftSum = 0;
    rightSum = 0;
    if (j <= mid) {
        leftSum = numArraySumRange(root->left, i, j);
    } else if (i > mid) {
        rightSum = numArraySumRange(root->right, i, j);
    } else {
        leftSum = numArraySumRange(root->left, i, mid);
        rightSum = numArraySumRange(root->right, mid + 1, j);
    }
    return leftSum + rightSum;
}

static void numArrayFree(NumArray* obj) {
    if (obj == NULL) {
        return;
    }
    numArrayFree(obj->left);
    numArrayFree(obj->right);
    free(obj);
}

static int Comp(void *a, void *b)
{
    struct RNode *pa = (struct RNode *)a;
    struct RNode *pb = (struct RNode *)b;
    if (pa->val == pb->val) {
        return pb->index - pa->index;
    }
    return pa->val - pb->val;
}

static int CompIndex(void *a, void *b)
{
    struct RNode *pa = (struct RNode *)a;
    struct RNode *pb = (struct RNode *)b;

    return pa->index - pb->index;
}

static void Reverse(int *arr, int len)
{
    int tmp, left, right;

    left = 0;
    right = len - 1;
    while (left < right) {
        tmp = arr[right];
        arr[right] = arr[left];
        arr[left] = tmp;
        left++;
        right--;
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize){
    int i, rank, tmp;
    int *rankNum, *ans;
    NumArray *root;

    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    rankNum = (int *)calloc(1, sizeof(int) * (numsSize + 1));
    ans = (int *)calloc(1, sizeof(int) * numsSize);
    g_record = (struct RNode *)calloc(1, sizeof(struct RNode) * numsSize);

    Reverse(nums, numsSize);

    for (i = 0; i < numsSize; i++) {
        g_record[i].val = nums[i];
        g_record[i].index = i;
    }
    qsort(g_record, numsSize, sizeof(struct RNode), Comp);

    for (i = 0; i < numsSize; i++) {
        g_record[i].rank = i;
    }

    qsort(g_record, numsSize, sizeof(struct RNode), CompIndex);

    root = numArrayCreate(rankNum, (numsSize + 1));

    for (i = 0; i < numsSize; i++) {
        rank = g_record[i].rank;
        UpdateNode(root, 1, rank + 1);
        tmp = numArraySumRange(root, 0, rank);
        ans[i] = tmp;
    }
    Reverse(ans, numsSize);
    *returnSize = numsSize;
    free(g_record);
    free(rankNum);
    return ans;
}
```

【树状数组】
36 ms	11.3 MB
执行效率较高，代码简洁，推介使用！
```
static int Lowbit(int x)
{
	return x & (-x);
}

static void FenUpdate(int *arr, int len, int i, int delta)
{
	while (i < len) {
		arr[i] += delta;
		i += Lowbit(i);
	}
}

static int FenQuery(int *arr, int i)
{
	int sum = 0;

	while (i > 0) {
		sum += arr[i];
		i -= Lowbit(i);
	}
	return sum;
}

struct Node {
	int index;
	int val;
	int rank;
};

int Comp(void *a, void *b)
{
	struct Node *pa = (struct Node *)a;
	struct Node *pb = (struct Node *)b;
	if (pa->val == pb->val) {
		return pa->index - pb->index;
	}
	return pa->val - pb->val;
}

int CompIndex(void *a, void *b)
{
	struct Node *pa = (struct Node *)a;
	struct Node *pb = (struct Node *)b;
	return pa->index - pb->index;
}

int* countSmaller(int* nums, int numsSize, int* returnSize){
	struct Node *nodes = (struct Node *)calloc(1, sizeof(struct Node) * numsSize);
	int *ans = (int *)calloc(1, sizeof(int) * numsSize);
	int *fenArr = (int *)calloc(1, sizeof(int) * (numsSize + 1));
	int i;

	for (i = 0; i < numsSize; i++) {
		nodes[i].index = i;
		nodes[i].val = nums[i];
	}
	qsort(nodes, numsSize, sizeof(struct Node), Comp);
	for (i = 0; i < numsSize; i++) {
		nodes[i].rank = i;
	}
	qsort(nodes, numsSize, sizeof(struct Node), CompIndex);
	for (i = numsSize - 1; i >= 0; i--) {
		ans[i] = FenQuery(fenArr, nodes[i].rank + 1);
		FenUpdate(fenArr, numsSize + 1, nodes[i].rank + 1, 1);
	}
	*returnSize = numsSize;
	return ans;
}
```

【二分】
408 ms	10.2 MB
比较容易想到，但是更新数组需要逐个移动，效率很低，比其他算法运行时长大10倍。
```
#include <stdio.h>

static int *g_record;
static int g_recordIndex;

static int GetLower(int val)
{
    int left, right, mid;

    left = 0;
    right = g_recordIndex;

    while (right > left) {
        mid = left + (right - left) / 2;
        if (g_record[mid] >= val) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

static void Insert(int index, int val)
{
    int i;
    for (i = g_recordIndex - 1; i >= 0; i--) {
        if (i == index) {
            g_record[i] = val;
            break;
        } else {
            g_record[i] = g_record[i - 1];
        }
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize){
    
    int i, index;
    int *ans;

    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    ans = (int *)calloc(1, sizeof(int) * numsSize);
    g_record = (int *)calloc(1, sizeof(int) * numsSize);
    g_recordIndex = 0;

    for (i = numsSize - 1; i >= 0; i--) {
        index = GetLower(nums[i]);
        ans[i] = index;
        g_recordIndex++;
        Insert(index, nums[i]);
    }
    free(g_record);
    *returnSize = numsSize;
    return ans;
}
```
