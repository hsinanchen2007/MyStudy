```
#define MAX_TREE_NODE_SIZE 100
#define MAX_TREE_SUB_NODES 10

typedef struct {
    int level;
    int pos;
    int weight;
    int totalSubNodes;
    int subNode[MAX_TREE_SUB_NODES];   /* 每个节点包含的子节点个数 */
}TreeNode;

void AnalyzeNum(int num, int *level, int *pos, int *weight)
{
    *weight = num % 10;     /* 个位用于存储权重，值为1~9 */
    num = num / 10;
    *pos = num % 10 - 1;        /* 十位用于存储位置，记为子节点在父节点的索引，值为1~8 */
    *level = num / 10 - 1;      /* 百位用于存储level，值为1~4 */
    return;
}

void UpdateParent(TreeNode *root, int sublevel, int subPos, int subIndex) 
{
    if (sublevel == 0) {
        return;
    }

    int parentPos = (subIndex >> 1) - (subPos % 2);
    root[parentPos].subNode[subPos] = subIndex;
    root[parentPos].totalSubNodes++;
    return;
}

void InitTree(int* nums, int numsSize, TreeNode *root)
{
    int level = 0;
    int pos = 0;
    int weight = 0;
    for (int i = 0; i < numsSize; i++) {
        AnalyzeNum(nums[i], &level, &pos, &weight);
        int nodePos = (1 << level) + pos - 1;        
        root[nodePos].level = level;
        root[nodePos].pos = pos;
        root[nodePos].weight = weight;
        UpdateParent(root, level, pos, nodePos);
    }
    return;
}

void ShowTree(TreeNode *root, int totalNodes)
{
    for (int i = 0; i < totalNodes; i++) {
        printf("Node[%d] Infomation:\n", i);
        printf("level:%d\n", root[i].level);
        printf("pos:%d\n", root[i].pos);
        printf("weight:%d\n", root[i].weight);
        printf("totalSubNodes:%d\n", root[i].totalSubNodes);
        for (int j = 0; j < MAX_TREE_SUB_NODES && root[i].subNode[j] != 0; j++) {
            printf("subNode[%d]:%d\n", j, root[i].subNode[j]);
        }
    }

    return;
}

void ScanTree(TreeNode *root, int index, int *pathValue, int *ans) 
{
    int totalSubNums = root[index].totalSubNodes;
    *pathValue = *pathValue + root[index].weight;

    if (totalSubNums == 0) {
        *ans = *ans + *pathValue;
        *pathValue = *pathValue - root[index].weight;
        return;
    }

    for (int i = 0; i < MAX_TREE_SUB_NODES; i++) {
        int subId = root[index].subNode[i];
        if (subId != 0) {
            ScanTree(root, subId, pathValue, ans);
        }
    }
    
    *pathValue = *pathValue - root[index].weight;
    return;
}

int pathSum(int* nums, int numsSize)
{
    int ans = 0;
    /* 入参合法性校验 */
    if (numsSize == 0) {
        return ans;
    }

    /* 初始化数据，申请必要的内存 */
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode) * MAX_TREE_NODE_SIZE);
    memset(root, 0, sizeof(TreeNode) * MAX_TREE_NODE_SIZE);
    InitTree(nums, numsSize, root);
    ShowTree(root, numsSize);

    /* 遍历路径获取路径之和 */
    int pathValue = 0;
    ScanTree(root, 0, &pathValue, &ans);

    return ans;
}

void testPathSum()
{
    int arr[] = {115,215,224,325,336,446,458};
    int size = sizeof(arr) / sizeof(int);
    printf("%d, ret:44\n", pathSum(arr, size));
}
```
