void IntToChar(int val,char *temp, int *i)
{
    char str[100];
    int j = 0;
    if (val == 0){
        temp[(*i)++] = '0';
        return;
    }
    if (val < 0) {
        temp[(*i)++] = '-';
        val = -(val);
    }
    while (val > 0){
        str[j++] = (val % 10 + '0');
        val = val / 10;
    }
    //整数转换的字符串是逆序的 123----依次取出来最低位后为321，需要调整放入temp中
    for (int k = j - 1;k >= 0; k--) {
        printf("i = %d\n", *i);
        temp[(*i)++] = str[k];
    }
}
void Dfs(struct TreeNode* root, char ** result, char * temp, int* returnSize, int i)
{
    if (root == NULL) {
        return;
    }else {
        // 注意这里要考虑到val位数大于1位 ，负数的情况，不能直接简单转换temp[i] = (char)((root -> val) + '0');
        // 函数里面完成i下标的变动，处理一位，跳变1，防止函数外处理，跳变次数不固定
        IntToChar(root -> val, temp, &i); 
    }

    if (root -> left == NULL && root -> right == NULL) {
        result[*returnSize] = (char *)malloc(sizeof(char) * (i + 1));     // 一条路径探索完毕，申请空间，多申请1个结束符的空间
        memcpy(result[* returnSize], temp, sizeof(char) * (i)); //当前跳变的i为有效字符个数
        result[* returnSize][i] = '\0';//末尾加0
        for (int j = 0;j < i; j++) { //为了调试打印
            printf("data = %c\n", temp[j]);
        }
        (* returnSize)++;
        return;
    }
    temp[i++] = '-'; // 按照格式拼装
    temp[i++] = '>';
    Dfs(root -> left, result, temp, returnSize, i);//遍历左孩子和右孩子，i代表临时空间temp中的下一个写入位置
    Dfs(root -> right, result, temp, returnSize, i);
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    char ** result = (char **)malloc(sizeof(char *) * 10000000);
    char *temp = (char *)malloc(sizeof(char) * 10000000);
    *returnSize = 0;
    Dfs(root, result, temp, returnSize, 0);
    return result;
}