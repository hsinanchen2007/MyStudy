很努力的看官方题解了，实在看不懂，心塞。
我的解法：根据题目推测出来字符串下标和转换后的二维数组的关系。然后再按顺序输出。
    解题思路：
        1. 变换为numRows行，第i个字符(从0开始计数）在变形后的二维阵列的行数：
        如果 i/(numRows-1) 为偶数，则 y = i % (numRows - 1)
        如果 i/(numRows - 1) 为奇数，则 y = (numRows - 1) - i%(numRows - 1)
        2. 第i个字符(从0开始计数）在变形后的二维阵列的列数：
        如果 i/(numRows - 1)为偶数，则 x = (i / (numRows - 1)) / 2 * (numRows-1)
        如果 i/(numRows - 1)为偶数，则 x = (i / (numRows - 1) - 1) / 2 * (numRows-1) + i % (numRows - 1)

    解法一：正向思维，构造出对应的二维数组，遍历得到最终结果。空间复杂度会很高。
    解法二：
            算出各行元素在二维数组的坐标。有如下规则：
                1）如果是首位两行，在未到达最大列前，其下一个元素的列为： i*(numRows-1)
                2）如果是中间行，在未到达最大列前，其下一个元素的列为：
                    i为偶数，则为i*(numRows-1)。
                    i为奇数，则为(i-1)*(numRows-1)+(numRows-1-rows)。
            根据二维数组的坐标(rows,column)，算出在原字符串所在的位置。有如下规则：
                1）如果所在列满足column%(numRows-1)==0，则一维数组所在位置为column*2+rows
                2）如果所在列不满足column%(numRows-1)==0，则一维数组所在位置为 column/(numRows-1)*(numRows-1)*2 + (numRows-1) + (numRows-1-rows)
            时间复杂度就O（N）,空间复杂度O（1）
```
*解法一*/
//获取行数
int getRows(int i, int numRows){
    //如果为奇数
    if ((i/(numRows-1))%2){
        return ((numRows-1)-(i%(numRows-1)));
    }else {
        return (i%(numRows-1));
    }
}

//获取列数
int getColumn(int i, int numRows){
    //如果为奇数
    if ((i/(numRows-1))%2){
        return ((i/(numRows-1) - 1)/2 * (numRows-1) + i%(numRows-1));
    }else {
        return (i/(numRows-1))/2 * (numRows-1);
    }
}

char * convert(char * s, int numRows){
    int column = 0;
    int rows = 0;

    if (s == NULL){
        return NULL;
    }
    int len = strlen(s);
    if (len == 0){
        return s;
    }
    int maxColumn = getColumn(len-1, numRows);
    char** conArray = (char**)malloc(sizeof(char*)*numRows);
    for(int i = 0; i < numRows; i++){
        conArray[i] = (char*)malloc(sizeof(char)*(maxColumn+1));
        memset(conArray[i], 0, sizeof(char)*(maxColumn+1));
    }
    
    for (int i = 0; i < len; i++){
        column = getColumn(i, numRows);
        rows = getRows(i, numRows);
        conArray[rows][column] = s[i]; 
    }
    int k = 0;
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < maxColumn+1; j++){
            if (conArray[i][j] != 0){        
                s[k++] = conArray[i][j];
            }
        }
    }
    for(int i = 0; i < numRows; i++){
        free(conArray[i]);
        conArray[i] = NULL;
    } 
    free(conArray);
    conArray = NULL;
    return s;
}
```
```
/*解法二*/
//获取列数
int getColumn(int i, int numRows){
    //如果为奇数
    if ((i/(numRows-1))%2){
        return ((i/(numRows-1) - 1)/2 * (numRows-1) + i%(numRows-1));
    }else {
        return (i/(numRows-1))/2 * (numRows-1);
    }
}

int getSrcIndex(int rows, int column, int numRows){
    if(column%(numRows-1)==0){
        return column*2+rows;
    } else {
        return column/(numRows-1)*(numRows-1)*2 + (numRows-1) + (numRows-1-rows);
    }
}

void getMinLineChar(int rows, int numRows, int maxColumn, const char* srcStr, char* outStr, int* outStrIndex){
    int i = 0;
    int column = 0;
    int index = 0;
    do
    {
        if (i%2){
            column = ((i-1)/2)*(numRows-1)+(numRows-1-rows);
        }else {
            column = (i/2)*(numRows-1);
        }
        if (column > maxColumn){
            return;
        }
        index = getSrcIndex(rows,column, numRows);
        if (index >= strlen(srcStr)){
            printf("Error!\n");
            return;
        }
        outStr[(*outStrIndex)++]=srcStr[index];
        if (*outStrIndex >= strlen(srcStr)){
            printf("Error! outStrIndex = %d\n", *outStrIndex);
            return;
        }
        i++;
    }while(1);
}

void getLineChar(int rows, int numRows, int maxColumn, const char* srcStr, char* outStr, int* outStrIndex){
    int i = 0;
    int column = 0;
    int index = 0;
    do
    {
        if (rows == 0 || rows == numRows-1){
            column = i * (numRows-1);
        } else {
            if (i%2){
                column = ((i-1)/2)*(numRows-1)+(numRows-1-rows);
            }else {
                column = (i/2)*(numRows-1);
            }
        }

        if (column > maxColumn){
            return;
        }
        index = getSrcIndex(rows,column, numRows);
        if (index >= strlen(srcStr) || *outStrIndex >= strlen(srcStr)){
            printf("Error! index = %d outStrIndex = %d\n", index, *outStrIndex);
            return;
        }
        outStr[(*outStrIndex)++]=srcStr[index];
        if (*outStrIndex >= strlen(srcStr)){
            printf("Error! outStrIndex = %d\n", *outStrIndex);
            return;
        }
        i++;
    }while(1);
}

char * convert(char * s, int numRows){
    if (s == NULL){
        return NULL;
    }
    int len = strlen(s);
    if (len == 0 || numRows <= 1){
        return s;
    }
    char* ret = (char*)malloc(sizeof(char)*(strlen(s)+1));
    memset(ret, 0, strlen(s)+1);
    int retStrIndex = 0;
    int maxColumn = getColumn(len-1, numRows);
    for(int i = 0; i < numRows; i++){
        getLineChar(i,numRows,maxColumn,s,ret,&retStrIndex);

    }
    ret[retStrIndex] = '\0';
    return ret;
}
```

