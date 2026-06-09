### 解题思路
和55题的差别是在于，55题没有看具体在哪里起跳，只是看能否达到终点。具体哪里起跳使得跳的步数最少，就要看当前位置到当前所能到达的最大位置之间，找到一个最远的下一跳，用tmpMaxIndex记录，并且在移动到当前所能到达最大位置之后，更新jumpTimes和currMaxIndex。

### 代码

```c
int jump(int* nums, int numsSize){
    int *index;
    index = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
    {
        index[i] = nums[i] + i;
    }

    if (numsSize < 2)
        return 0;


    int currMaxIndex = index[0];
    int tmpMaxIndex = index[0];
    int jumpTimes = 1;

    for (int j = 0; j < numsSize; j ++)
    {
        if (j > currMaxIndex)
        {
            jumpTimes ++;
            currMaxIndex = tmpMaxIndex;
        }
        if(tmpMaxIndex < index[j])
        {
            tmpMaxIndex = index[j];
        }
    }

    return jumpTimes;
}
```