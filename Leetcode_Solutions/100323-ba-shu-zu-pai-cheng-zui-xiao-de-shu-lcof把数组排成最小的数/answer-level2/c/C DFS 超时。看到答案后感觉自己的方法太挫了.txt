int flag[110] = {0};
char tmp[10000] = {0};
int firstflag = 0;
int g_index = 0;

void dfs(int *nums ,int numsSize, int step, char *ans)
{
    int ret = 0;
    if(step == numsSize)
    {
        if(firstflag == 0)
        {
            strncpy(ans, tmp, strlen(tmp));
            firstflag = 1;
        }

        if(firstflag == 1)
        {
            if( strncmp(ans, tmp, strlen(tmp)) > 0 )
            {
                strncpy(ans, tmp, strlen(tmp));
                ans[strlen(tmp)] = '\0';
            }

        }
        
        return;
    }

    for(int i = 0; i < numsSize; i++)
    {
        memset(tmp + g_index, 0, 10000- g_index);
        if(flag[i] == 0)
        {   
            flag[i] = 1;
            ret = sprintf(tmp + g_index, "%d", nums[i]);
            //g_index = strlen(tmp);
            g_index = g_index + ret;
            dfs(nums, numsSize, step+1, ans);
            g_index = g_index - ret;
            flag[i] = 0;
        }
    }
    
    return;
}


char* minNumber(int* nums, int numsSize)
{
    char *ans = NULL;
    ans = (char *)malloc(sizeof(char) *10000);
    memset(ans, 0, sizeof(char) *10000);

    g_index = 0;
    firstflag = 0;
    memset(tmp, 0 ,10000);
    memset(flag, 0, 110 * 4);

    dfs(nums, numsSize, 0, ans);

    return ans;
}