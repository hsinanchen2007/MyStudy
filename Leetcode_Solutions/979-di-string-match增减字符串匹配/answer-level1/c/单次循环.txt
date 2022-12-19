解题思路
最后一个字符往前走
如果s[i]是I，则对应位置数字一定是当前可用最大
如果s[i]是D，则对应位置数字一定是当前可用最小

推导过程
如果S全I， 如IIIII， 则返回数组是0到N的递增；
如果S全D， 如DDDDD， 则返回数组是N到0的递减；

如果S为ID的组合， 那么S的子集中全I的部分，是一个递增；那么S的子集中全D的部分， 是一个递减
由此可得解题思路



int* diStringMatch(char * S, int* returnSize){
    int curMax = strlen(S);
    int curMin = 0;
    int i = strlen(S);
    int *p = (int *)malloc((i + 1) * sizeof(int));

    for(; i > 0; i--){
        if(S[i - 1] == 'I'){
            p[i] =  curMax;
            curMax--;
        }else{
            p[i] = curMin;
            curMin++;
        }
    }
    p[0] = curMax;
    *returnSize = strlen(S) + 1;
    return p;
}