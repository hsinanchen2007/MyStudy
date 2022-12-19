使用二维数组和等式的传递性保存等式的逻辑，再检查不等式是否合理.
```
#define ALPHANUM 26 // 二维数组的行和列，用于判断2个字母是否相等 a[i][j] = 1标识相等
bool equationsPossible(char ** equations, int equationsSize)
{
    int relation[ALPHANUM][ALPHANUM] = { 0 };
    int i, index1, index2, j, k;
    int relationNew = 0;
    if(equationsSize == 0 || equations == NULL) {
        return false;
    }
    // 初始化自己与自己的关系
    for (j = 0; j < ALPHANUM; j++) {
        relation[j][j] = 1;
    }
    // 先处理等式
    for (i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            continue;
        }
        if (equations[i][1] == '=') {
            relationNew = 1;
        } 
        index1 = equations[i][0] - 'a';
        index2 = equations[i][3] - 'a';
        relation[index1][index2] = relationNew;
        relation[index2][index1] = relationNew;
        for (j = 0; j < ALPHANUM; j++) {
            // a=b, b=c ==>a=c
            if (relation[index1][j] == 1) {
                relation[j][index2] = relationNew;
                relation[index2][j] = relationNew;
                // 利用等式的传递性，a=b, c=d,  b=c ==> a=d 
                for (k = 0; k < ALPHANUM; k++) {
                    if (relation[index2][k] == 1) {
                        relation[j][k] = 1;
                        relation[k][j] = 1;
                    }
                }
            }
            // a=b, c=b ==>a=c  
            if (relation[index2][j] == 1) {
                relation[j][index1] = relationNew;
                relation[index1][j] = relationNew;
            }
        }
    }
   // 打印所有查看是否正确
    for (i = 0; i < ALPHANUM; i++) {
        for (j = 0; j < ALPHANUM; j++) {
            printf("[%d] ",relation[i][j]);
        }
        printf("\n");
    }
    // 检查不等式
    for (i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=') {
            continue;
        }
        if (equations[i][1] == '!') {
            relationNew = -1;
        }
        index1 = equations[i][0] - 'a';
        index2 = equations[i][3] - 'a';
        printf("check:[%d][%d] value:%d\n", index1, index2, relation[index1][index2]);
        if ( relation[index1][index2] != 0 &&
             relation[index1][index2] != relationNew) {
            return false;
        }
    }    
    return true;
}
```
