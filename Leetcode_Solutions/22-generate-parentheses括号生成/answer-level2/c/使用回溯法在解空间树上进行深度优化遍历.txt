使用回溯法，在解空间树上进行深度优化遍历，遍历时剪掉不可能的分枝：
（1）解空间为 （ 和 ）。
（2）解向量的正确性，可以由一个标志测试。
（3）解向量和非解向量隐含地挂在一个满二叉树上，左子为 （ ，右子为 ）。

这道题有一个地方没讲清楚，很撮：每一个成功的解需要构成一个字符串，如果是一个字符数组，会失败。

```
#include <stdio.h>

typedef struct tagEnv {
    /* 所有的括号序列 */
    char** allVecs;

    /* allVecs的容量 */
    int vecsSpcLen;

    /* 可以在此序号上写入一个括号序列到allVecs */
    int vecsIdx;

    /* 要求的1个括号序列长度 */
    int vecLen;
} ENV_S;

void SavePt(ENV_S* env, char* ptVec)
{
    if (env->vecsIdx >= env->vecsSpcLen) {
        int newVecsSpcLen = env->vecsSpcLen + 32;
        char** newAllVecs = (char **)malloc(newVecsSpcLen * sizeof(char *));
        if (newAllVecs == NULL) {
			return;
        }

        if (env->vecsIdx > 0) {
            (void)memcpy(newAllVecs, env->allVecs, env->vecsIdx * sizeof(char *));
            (void)free(env->allVecs);
        }

        env->allVecs = newAllVecs;
        env->vecsSpcLen = newVecsSpcLen;
    }

    char* curVec = (char *)malloc((env->vecLen + 1) * sizeof(char));
    if (curVec == NULL) {
		return;
    }
    (void)memcpy(curVec, ptVec, env->vecLen * sizeof(char));
    curVec[env->vecLen] = '\0';

    env->allVecs[env->vecsIdx] = curVec;
    env->vecsIdx += 1;
}

/*
 * 如果一道题的解是一些向量的集合，则可以使用递归的方法在解向量树上进行深度优先遍历得到解。 
 * (1)解空间: ( 和 )
 * (2)解向量: 空; (()); ()();
 * (3)解向量树: 由解向量和非解向量组成的满树, 可在其上进行dfs得到所有解向量, 且在dfs时可以剪枝。
 * (4)DfsFunc的一般格式: DfsFunc(ENV, curV, lel, inElem);
 *    ENV是环境; curV是当前正在求的解向量(!简单数组!); lel是inElem要放在curV的偏移量,即树的层数。
*/
void DfsGenPt(ENV_S* env, char* ptVec, int lel, char c, int cptParam)
{
    /* 判断前一次次遍历的结果是否结束 */
    if (lel + 1 > env->vecLen) {
        /* 如果上次形成了正确的括号序列, 则保存到结果中 */
        if (cptParam == 0) {
            SavePt(env, ptVec);
        }
        return;
    }

    /* 处理当前的输入 */
    if (c == '(') {
        cptParam += 1;
    } else {
        cptParam -= 1;
    }
    ptVec[lel] = c;

    /* dfs孩子节点: ( 和 ), 前提是要满足条件 */
    if (cptParam >= 0 && cptParam < env->vecLen / 2) {
        DfsGenPt(env, ptVec, lel + 1, '(', cptParam);
    }
    if (cptParam > 0) {
        DfsGenPt(env, ptVec, lel + 1, ')', cptParam);
    }
}

char ** generateParenthesis(int n, int* returnSize)
{
    int ptLen = 2 * n;
    ENV_S env = { .allVecs = NULL, .vecsSpcLen = 0, .vecsIdx = 0, .vecLen = ptLen };
    char* ptVec = (char *)malloc(ptLen * sizeof(char));

    *returnSize = 0;
    if (ptVec == NULL) {
        return NULL;
    }

    DfsGenPt(&env, ptVec, 0, '(', 0);
    (void)free(ptVec);

    *returnSize = env.vecsIdx;
    return env.allVecs;
}
```
