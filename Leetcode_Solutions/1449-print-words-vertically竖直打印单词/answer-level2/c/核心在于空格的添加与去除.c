### 解题思路
![image.png](https://pic.leetcode-cn.com/eb7af40e32c4a8a824c42fd7b4af9c71df1d37b2223710cad069a17700f34a83-image.png)


### 代码

```c
#define  NUM 201
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize){
    if(NULL == s)
    {
        *returnSize = 0;
        return NULL;
    }

    //申请返回的内存
    char **res = (char**)malloc(sizeof(char*) * NUM);
    memset(res,0,sizeof(char*) * NUM);

    char temp[NUM][NUM] = {0};

    int row = 0;
    int col = 0;
    

    //拆分字符串得到每个单词
    char *sword = strtok(s," ");
    while( NULL != sword)
    {
        strcpy(temp[row++],sword);
        col = col > strlen(sword)?col:strlen(sword);
        sword = strtok(NULL," ");
        
    }

    //创造新单词
    for(int i = 0; i < col;i++)
    {
        res[i] = (char*) malloc(sizeof(char)*(row+ 1));
        memset(res[i],0,sizeof(char)*(row+1));
    }
    for(int i = 0;i < col;i++)
    {
        for(int j = 0;j < row;j++)
        {     
                if(temp[j][i]=='\0')
                {
                    res[i][j] = ' ';
                }
                else
                {
                    res[i][j] = temp[j][i];
                }
                
                printf("i = %d j = %d res[i][j] = %c temp[j][i]= %c\n",i,j,res[i][j],temp[j][i]);
        }
    }

    //删除旋转后单词尾部的空格，其实就是用'\0'去替换
    for(int i = 0;i < col;i++)
    {
        while(res[i][strlen(res[i])-1] == ' ')
        {
            res[i][strlen(res[i])-1] = '\0';
        }
    }

    *returnSize = col ;
    return res;
}
```