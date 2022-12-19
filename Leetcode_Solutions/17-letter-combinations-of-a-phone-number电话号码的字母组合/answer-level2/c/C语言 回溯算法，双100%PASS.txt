```
/**
 * 本解答模仿 https://www.cnblogs.com/wuyuegb2312/p/3273337.html 编写
 * 本解答以供自己学习提升和分享 MasterXU
 */
static char g_ch[10][4] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};
static int g_total[10] ={0,0,3,3,3,3,3,4,3,4}; 
/**
 * number: 输入待转换数字
 * answer：解空间,存放路径上每个节点的选择,由于是递归实现 需要保存1条路径节点即可
 * index:  当前深度
 * depth:  最大路径深度
 * ans:    返回结果
 * pathIdx:当前路径编号
 */
void recursive(char *number, int *answer, int index, int depth, char **ans, int *pathIdx)
{
    // 判断当前解空间是否是符合条件的解, 一条路劲
    if(index == depth) {
        // 输出
        ans[*pathIdx] = (char *)malloc((depth + 1) * sizeof(char));
        for(int i = 0; i < depth; i++) {
            ans[*pathIdx][i] = g_ch[number[i] - '0'][answer[i]];
        }
        // 记得给字符串加上结束符,否则会报错
        ans[*pathIdx][depth] = '\0';
        // 路径记数++
        (*pathIdx)++;
        // 剪枝, 避免路径重复
        return;
    }
    // 先执行 index + 1, 增加搜索深度
    // 再执行 answer[index]++, 回到上一个节点 继续搜索解
    for(answer[index] = 0; answer[index] < g_total[number[index] - '0']; answer[index]++) {
    // 构造下一步选择, DFS走深度增加方向
        recursive(number, answer, index + 1, depth, ans, pathIdx);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    int a[100] = {0};               // 临时解空间
    int depth = strlen(digits);     // 最大深度
    int num = (int)pow(4, depth);   // 最大路径个数
    *returnSize = 0;                // 路径记数

    if (depth == 0) {
        return NULL;
    }

    char **ans = (char **)malloc(num * sizeof(char *));

    recursive(digits, a, 0, depth, ans, returnSize);

    return ans;
}

```
