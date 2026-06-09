```
/*
按行排序

取numRows和s的长度中最小的个列表来表示 Z 字形图案中的非空行。

遍历s，通过向上移动和向下移动，将每个字符添加到合适的行。

只有当我们向上移动到最上面的行或向下移动到最下面的行时，移动方向才会发生改变。

*/

/* 通过二维数组实现 */
char *convert(char *s, int numRows)
{
    int len = strlen(s);
    /* 针对极端情况 */
    if(numRows > len) {
        return s;
    }
    if(numRows == 1) {
        return s;
    }
    
    int row = 0; /* 二维数组行数 */
    int col = 0; /* 二维数组列数 */
    int index = 0; /* 输入数组索引 */
    
    char arr[1001][1001] = {0}; /* 存放元素的二维数组 */
    char* arr1 = (char*)malloc(sizeof(char)*1001); /* 返回的一维数组 */
    memset(arr1,0,1001); /* 对数组初始化 */
    
    /* 通过二维数组实现按列存储s[index]，通过边界值row < numRows，以及row来转换方向 */
    while(s[index]) {
        while(row < numRows && s[index]) {
            arr[row++][col] = s[index++];
        }
        /* 当row = numRows - 1时 */
        row -= 2;
        col++;
        while(row && s[index]) {
            arr[row--][col++] = s[index++];
        }
    }
    
    /* 二维数组转换为一维数组 */
    int ret = 0;
    for(int i = 0;i < numRows;i++) {
        for(int j = 0;j < col;j++) {
            if(arr[i][j]) { /* 只存储有数值的数字，空字符跳过 */
                arr1[ret++] = arr[i][j];
            }
        }
    }
    
    return arr1;
    
}


```
