### 解题思路

摘自博客：https://blog.csdn.net/weixin_40673608/article/details/84262695

### 代码

```c
#define MAX(x,y) x > y ? x : y

int longestCommonSubsequence(char * text1, char * text2)
{
    int i,j;
    int len_text1,len_text2;
    len_text1 = strlen(text1) + 1;   // 用来统计的二维数组比实际大小长度多一个
    len_text2 = strlen(text2) + 1;

    // 动态申请一个二维数组用来存放公共子串的最大长度
    // len_text1 = 行数 len_text2 = 列数
    int **LCS = (int **)malloc(sizeof(int *) * len_text1);
	for (int i = 0; i < len_text1; ++i)
	{
		LCS[i] = (int *)malloc(sizeof(int) * len_text2);
	}
    // 初始化二维数组
    for ( i = 0; i < len_text1; ++i)     // 第一列为0
        LCS[i][0] = 0; 
    for ( j = 0; j < len_text2; ++j)     // 第一行为0
        LCS[0][j] = 0; 

    for ( i = 1; i < len_text1; ++i)
	{
		for ( j = 1; j < len_text2; ++j)
		{
            if(text1[i-1] == text2[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
            {
                LCS[i][j]  = MAX(LCS[i-1][j] , LCS[i][j-1]);
            }
		}
	}

    return LCS[len_text1 - 1][len_text2 - 1];
}
```