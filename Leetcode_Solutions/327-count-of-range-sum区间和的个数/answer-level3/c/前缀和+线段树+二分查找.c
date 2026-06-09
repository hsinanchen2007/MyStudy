```
#define L(t) ((t<<1) + 1)
#define R(t) ((t<<1) + 2)
#define MAX_N 10000
#define FACTOR 4
typedef struct {
    int left;
    int right;
    int val;
}NODE;

NODE g_node[MAX_N * FACTOR];
long long int g_preSum[MAX_N];
// 二分查找，查找[begin,end)范围内第一个大于等于val的元素，返回该元素的位置
// 注:数组必须是排好序的
int BiSearchLowerBound(long long int *nums, int begin, int end, long long int val)
{
    int l, r;
    int mid;
    l = begin;
    r = end;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (nums[mid] > val) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return (nums[l] >= val ? l : r);
}
// 二分查找，查找[begin,end)范围内第一个大于val的元素，返回该元素的位置
int BiSearchUpperBound(long long int *nums, int begin, int end, long long int val)
{
    int l, r;
    int mid;
    l = begin;
    r = end;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (nums[mid] > val) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return (nums[l] > val ? l : r);
}

// 去重, 返回新的数组长度
int Unique(long long int *nums, int numsSize)
{
    int l, r;
    if (numsSize <= 1) {
        return numsSize;
    }
    l = 0;
    r = l + 1;
    while (r < numsSize) {
        if (nums[l] != nums[r]) {
            nums[++l] = nums[r];
        }
        r++;
    }
    return l + 1;
}
void Build(int root, int l, int r)
{
    int mid;
    g_node[root].left = l;
    g_node[root].right = r;
    if (l == r) {
        g_node[root].val = 0;
        return;
    }
    mid = (l + r) / 2;
    Build(L(root), l, mid);
    Build(R(root), mid + 1, r);
    g_node[root].val = g_node[L(root)].val + g_node[R(root)].val;
}
void Update(int v, int root)
{
    int mid;
    if (g_node[root].left == g_node[root].right &&
    g_node[root].left == v) {
        g_node[root].val += 1;
        return;
    }
    mid = (g_node[root].left + g_node[root].right) / 2;
    if (v <= mid) {
        Update(v, L(root));
    } else {
        Update(v, R(root));
    }
    g_node[root].val = g_node[L(root)].val + g_node[R(root)].val;
}
int Query(int root, int l, int r)
{
    int ans = 0;
    int mid;
    if (l <= g_node[root].left && g_node[root].right <= r) {
        return g_node[root].val;
    }
    mid = (g_node[root].left + g_node[root].right) / 2;
    if (l > mid) {
        ans += Query(R(root), l, r);
    } else if (r <= mid) {
        ans += Query(L(root), l, r);
    } else {
        ans += Query(L(root), l, mid);
        ans += Query(R(root), mid + 1, r);
    }
    return ans;
}
int Comp(const void *a, const void *b)
{
    const long long int *pa = (const long long int *)a;
    const long long int *pb = (const long long int *)b;
    if ((*pa) > (*pb)) {
        return 1;
    } else if ((*pa) < (*pb)) {
        return -1;
    } else {
        return 0;
    }
}
int countRangeSum(int* nums, int numsSize, int lower, int upper){
    int i;
    int ret = 0;
    long long int preSum = 0;
    long long int up;
    long long int low;
    int preSumSize;
    if (numsSize <= 0) {
        return 0;
    }
    (void)memset(g_node, 0, sizeof(g_node));
    (void)memset(g_preSum, 0, sizeof(g_preSum));
    for (i = 1; i <= numsSize; i++) {
        g_preSum[i] = g_preSum[i - 1] + nums[i - 1];
    }
    preSumSize = numsSize + 1;
    qsort(g_preSum, preSumSize, sizeof(long long int), Comp);
    preSumSize = Unique(g_preSum, preSumSize);
    preSum = 0;
    Build(0, 0, preSumSize - 1);
    Update(BiSearchLowerBound(g_preSum, 0, preSumSize, preSum), 0);
    for (i = 0; i < numsSize; i++) {
        preSum += nums[i];
        up = BiSearchLowerBound(g_preSum, 0, preSumSize, preSum - upper);
        low = BiSearchUpperBound(g_preSum, 0, preSumSize, preSum - lower) - 1;
        // printf("up,low:%d,%d\n",up,low);
        if (up <= low) {
            ret += Query(0, up, low);
        }
        Update(BiSearchLowerBound(g_preSum, 0, preSumSize, preSum), 0);
    }
    return ret;
}
```
