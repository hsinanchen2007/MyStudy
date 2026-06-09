### 解题思路
你有一个日志数组 logs。每条日志都是以空格分隔的字串。

对于每条日志，其第一个字为字母数字标识符。然后，要么：

标识符后面的每个字将仅由小写字母组成，或；
标识符后面的每个字将仅由数字组成。
我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。

将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按内容字母顺序排序，忽略标识符；在内容相同时，按标识符排序。数字日志应该按原来的顺序排列。

返回日志的最终顺序。

。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    char **l_arr = malloc((logsSize + 1) * sizeof(char *));
    int i,j,k=0;
    char c = ' ';
    char * temp;

    memset(l_arr,0,logsSize*sizeof(char *));

    for(i=0;i<logsSize;i++){
        temp = strchr(logs[i],c);
        //printf("%c \n",temp[1]);
        if(temp[1] >= 65)
            l_arr[k++] = logs[i];
    }

    char * left, *right;
    

    for(i=0;i<k-1;i++){
        for(j=i+1;j<k;j++){
            left = strchr(l_arr[i], c);
            right = strchr(l_arr[j], c);

            if(strcmp(left,right) > 0){
                left = l_arr[i];
                l_arr[i] = l_arr[j];
                l_arr[j] = left;
            }else if(strcmp(left,right) == 0){
                if(strcmp(l_arr[i],l_arr[j])){
                    left = l_arr[i];
                    l_arr[i] = l_arr[j];
                    l_arr[j] = left;
                }
            }
        }
    }

    for(i=0;i<logsSize;i++){
        temp = strchr(logs[i], c);
        if(temp[1] < 65)
            l_arr[k++] = logs[i];
    }

    *returnSize = logsSize;
    return l_arr;
}
```