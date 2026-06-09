### 解题思路
同样使用划窗法，与209. 长度最小的子数组不同，该问题是求最大子串。把条件稍加修改，老代码就可以复用了。

### 代码

```c
int maxSubArrayLen(int s, int* nums, int numsSize){
    int leftWin = 0;
    int rightWin = 0;
    int len = 0;
    long sum = 0;
    //printf("------- \n");
    //printf("%lu \n", numsSize);
    while (rightWin <  numsSize) {
        sum += (long)nums[rightWin];
        while (sum > (long)s) {
            if (sum < (long)(nums[leftWin])) {
                break;
            }
            sum -= (long)nums[leftWin];
            leftWin++;
        }
        //printf("%lu ,%lu  \n", leftWin, rightWin);
        if ((sum <= s) && (len <= (rightWin - leftWin + 1))) {
                len = rightWin- leftWin + 1;
                //printf("%lu \n", len);
        }
        rightWin++;
    }
    return len;
}




int equalSubstring(char * s, char * t, int maxCost){
    /* 输入有效性判断 */
    if ((s == NULL) || (maxCost < 0)) {
        return 0;
    }

    int sLen = strlen(s);
    int* costArr = (int *)malloc(sizeof(int) * sLen);
    //printf("------------start ----------- \n");
    for (int idx = 0; idx < sLen; idx++) {
        costArr[idx] = abs(s[idx] - t[idx]);
        //printf("%lu \n", costArr[idx]);
    }
    int ret = maxSubArrayLen(maxCost, &costArr[0], sLen);
    return ret;
}
```