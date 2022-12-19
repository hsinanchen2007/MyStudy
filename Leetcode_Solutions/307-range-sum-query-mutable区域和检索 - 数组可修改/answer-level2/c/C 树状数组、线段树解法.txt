### 解题思路
该题就是区间查询、区间更新的典型题目，可以使用树状数组、线段树实现，树状数组执行效率更高

### 代码

【树状数组】
```c
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

typedef struct Node {
    int *arr;
    int *oldArr;
    int len;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    int i;
    NumArray *obj = (NumArray *)calloc(1, sizeof(NumArray));
    obj->arr = (int *)calloc(1, sizeof(int) * (numsSize + 1));
    obj->oldArr = nums;
    obj->len = numsSize + 1;
    for (i = 0; i < numsSize; i++) {
        FenUpdate(obj->arr, obj->len, i + 1, nums[i]);
    }
    return obj;
}

void numArrayUpdate(NumArray* obj, int i, int val) {
    FenUpdate(obj->arr, obj->len, i + 1, val - obj->oldArr[i]);
    obj->oldArr[i] = val;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int a, b;
    a = FenQuery(obj->arr, i);
    b = FenQuery(obj->arr, j + 1);
    return b - a;
}

void numArrayFree(NumArray* obj) {
    free(obj->arr);
    free(obj);
}
```
【线段树】
```
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

NumArray* numArrayCreate(int* nums, int numsSize) {
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

void numArrayUpdate(NumArray* obj, int i, int val) {
	UpdateNode(obj, val, i);	
}

int numArraySumRange(NumArray* root, int i, int j) {
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

void numArrayFree(NumArray* obj) {
	if (obj == NULL) {
		return;
	}
	numArrayFree(obj->left);
	numArrayFree(obj->right);
	free(obj);
}
```
