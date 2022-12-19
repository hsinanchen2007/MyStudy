
思路：类似1054，先求最多包含的字符个数，根据该个数来判断是否存在合法的，如果存在合法的排列，填最大值位，奇数位、偶数位。
int getMaxValIndex(int *nums, int size)
{
    int i, index = 0, max = 0;
    for (i = 0; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
            index = i;
        }
    }
    return index;
}
void setAns(int *nums, char *ans, int maxCnt, int maxIndex, int len)
{
    int i = 0, j, index;
    /* 填最大值 */
    while (maxCnt > 0 && i < len) {
        ans[i] = maxIndex + 'a';
        maxCnt--;
        nums[maxIndex]--;
        i += 2;
    }
    /* 补奇数位 */
    for (j = 0; j < 26; j++) {
        while (nums[j] && i < len) {
            ans[i] = j + 'a';
            i += 2;
            nums[j]--;
        }
    }
    /* 补偶数位 */
    i = 1;
    for (j = 0; j < 26; j++) {
        while (nums[j] && i < len) {
            ans[i] = j + 'a';
            i += 2;
            nums[j]--;
        }
    }    
    return;
}
char * reorganizeString(char * S){
    int nums[26] = {0};
    int i, j, index, maxCnt, len;
    char *ans;
    if (S == NULL) {
        return NULL;
    }
    len = strlen(S);
    ans = calloc(len+1, sizeof(char));
    if (len == 0) {
        return ans;
    }
    if (len == 1) {
        ans[0] = S[0];
        return ans;
    }    
    i = 0;
    while(S[i] != '\0') {
        index = S[i] - 'a';
        nums[index]++;
        i++;
    }
    index = getMaxValIndex(nums, 26);
    
    maxCnt = nums[index];
    /* 根据最多出现次数的字符判断是否存在 */
    if (maxCnt * 2 -1 > len) {
        return ans;
    }
    //printf("index=%d, len=%d, maxCnt=%d\r\n", index, len, maxCnt);
    setAns(nums, ans, maxCnt, index, len);
    return ans;
}