### 解题思路
dp[left][right] == 1：表示从下标left~right的子串为回文子串
buf[i] == x：表示回文子串的的下标位置。一组子串的起点下标：buf[i-1]+1 终点下标：buf[i]
start：遍历原字符串s时的当前位置。
1.先用中心扩展的思想遍历原字符串s，将所有回文子串存储到dp[][]中
2.用start=0开始搜索原字符串s。不断递归调用search()函数
3.当start==strlen(s)时，说明已经找到一组子串，则将这组子串存到res中去

### 代码

```c

#define MAX_SIZE 1024
//从中心扩展，将所有回文子串的位置存储到dp中
void judgeFromCenter(int left, int right, char *s, int **dp){
    while(left>=0 && right<strlen(s) && s[left] == s[right]){
        dp[left][right] = 1;
        left--;
        right++;
    }
}
void search(int start, int buf_index, int *buf, int **dp, char*** res, char *s, int* returnSize, int** returnColumnSizes ){
    if(start == strlen(s)){
        res[(*returnSize)] = (char**)malloc(sizeof(char*) * (buf_index-1));
        for(int i=1; i<buf_index; i++){
            res[(*returnSize)][i-1] = (char*)malloc((buf[i]-buf[i-1]+1)*sizeof(char));
            //把s的子串赋值给res
            int k=0;
            for(int j = buf[i-1]+1; j<=buf[i]; j++){
                res[(*returnSize)][i-1][k++] = s[j];
            }
            res[(*returnSize)][i-1][k] = '\0';
        }
        (*returnColumnSizes)[(*returnSize)] = buf_index-1;
        (*returnSize)++;
        return;
    }
    for(int i=start; i<strlen(s); i++){
        if(dp[start][i] != 1) continue;   //剪枝
        //否则，若dp[start][i]==1(即起点为start、终点为i，为回文子串)，则继续执行
        buf[buf_index] = i;     //记录终点下标i
        search(i+1, buf_index+1, buf, dp, res, s, returnSize, returnColumnSizes);
    }

}
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    int len = strlen(s);
    if(len<=0) return NULL;
//分配空间
    char *** res = (char***)malloc(sizeof(char**) * MAX_SIZE);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * MAX_SIZE);
/** 初始化buf[]，记录回文子串的的下标位置
*  一组子串的起点下标：buf[i-1]+1 终点下标：buf[i]  */
    int *buf = (int*)malloc(sizeof(int) * (len+1) );
    buf[0] = -1;
//初始化dp
    int **dp = (int**)malloc(sizeof(int*) * len);
    for(int r = 0; r<len; r++){
        dp[r] = (int*)malloc(sizeof(int) * len);
        memset(dp[r], 0, sizeof(int) * len);
    }
//遍历中心点,进行预处理 dp[left][right]==1表示从下标left~right的子串为回文子串
    for(int i=0; i<len; i++){
        judgeFromCenter(i,i,s, dp);   //当s的长度为奇数时，访问n个中心点
        judgeFromCenter(i,i+1,s, dp); //当s的长度为偶数时，访问n-1个中心点
    }
//回溯 start从0开始 buf_index从1开始
    (*returnSize) = 0;
    search(0, 1, buf, dp, res, s, returnSize, returnColumnSizes);
    return res;
}
```