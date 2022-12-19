题目要求最小规模，首先想到的是广搜，
要点：
1、降低计算复杂度，先将字符串匹配变成位运算（套路）
2、广搜，没多一个人，相当于广播多走一步，看下当前所有人的技能全集是否满足要求
3、剪枝，记录所有技能合集，不能出现重复计算的，后出现的肯定比前出现的规模大

待优化：
剪枝：如果之前出现的技能合集包含后出现的，则可以减掉
```
/* *
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define printf
typedef struct {
    int peopleIdx; // 当前人索引
    int way[60];   // 走过的路，便于输出
    int skill;     // 所有之前遍历人的技能合集
    int step;      // 遍历到第几个人
} StepInfo;

int SkillIndex(char **req_skills, int req_skillsSize, char *skill)
{
    for (int j = 0; j < req_skillsSize; j++) {
        if (strcmp(req_skills[j], skill) == 0) {
            return j;
        }
    }

    return -1;
}

// 处理输出
int *result(StepInfo step, int *returnSize)
{
    int *resultArray = (int *)malloc(sizeof(int) * step.step);
    *returnSize = step.step;
    memcpy(resultArray, step.way, step.step * sizeof(int));

    return resultArray;
}


int *smallestSufficientTeam(char **req_skills, int req_skillsSize, char ***people, int peopleSize, int *peopleColSize,
    int *returnSize)
{
    int peopleSkill[peopleSize];
    memset(peopleSkill, 0, sizeof(peopleSkill));

    int skillMask = (1 << req_skillsSize) - 1;
    printf("skillMask=%#x\n", skillMask);

    // 转化位运算
    for (int i = 0; i < peopleSize; i++) {
        for (int j = 0; j < peopleColSize[i]; j++) {
            int idx = SkillIndex(req_skills, req_skillsSize, people[i][j]);
            // printf("people[%d-%d]=%d\n", i, j, idx);
            if (idx >= 0) {
                peopleSkill[i] |= (1 << idx);
            }
        }

        printf("people[%d]=%#x\n", i, peopleSkill[i]);
    }

    StepInfo stepArray[(peopleSize + 1)*(peopleSize + 1)*(peopleSize + 1)];
    memset(stepArray, 0, sizeof(stepArray));
    int start = 0;
    int end = 0;

    // 技能合集，便于剪枝
    int skills[1 << req_skillsSize];
    memset(skills, 0, sizeof(skills));

    // 所有人先第一次遍历
    for (int i = 0; i < peopleSize; i++, end++) {
        if (peopleSkill[i] == 0) {
            continue;
        }
        stepArray[i].peopleIdx = i;
        stepArray[i].way[0] = i;
        stepArray[i].skill = peopleSkill[i];
        stepArray[i].step = 1;

        skills[stepArray[i].skill] = 1;
    }

    // DFS
    while (start < end) {
        StepInfo *curStep = &stepArray[start];
        printf("cur %d-%d-%#X\n", stepArray[start].peopleIdx, stepArray[start].step, stepArray[start].skill);
        // 每次遍历当前人后面的所有人
        for (int i = curStep->peopleIdx + 1; i < peopleSize; i++) {
            if (peopleSkill[i] == 0) { // 无技能的人跳过，不考虑
                continue;
            }
            StepInfo nextStep = *curStep;
            nextStep.peopleIdx = i;
            nextStep.way[nextStep.step++] = i;
            nextStep.skill |= peopleSkill[i];

            printf("next %d-%d-%#X, end=%d\n", nextStep.peopleIdx, nextStep.step, nextStep.skill, end);

            if (skills[nextStep.skill] == 1) {
                continue;
            }

            stepArray[end++] = nextStep;
            skills[nextStep.skill] = 1;

            if (nextStep.skill == skillMask) {
                return result(nextStep, returnSize);
            }
        }
        start++;
    }

    *returnSize = 0;
    return NULL;
}
```
