![1111111111111111.JPG](https://pic.leetcode-cn.com/4999d7cf17af6c799254259f83218ac1d46c1ea6f8550eeaa5e476a846b81b54-1111111111111111.JPG)


```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void generate(char *item, int index, int left, int right, char **result, int *count, int n)
{
    if(left==0 && right==0) // 已经全部插满了
    {
        result[(*count)]=(char*)malloc(sizeof(char)*(2*n+1));
        strcpy(result[(*count)++],item);
        return;
    }
    
    item[index]='('; // 插入左括号
    item[index+1]='\0';

    if(left > 0) {
        printf("left=%d, right=%d\r\n", left, right);
        generate(item, index+1, left-1, right, result, count, n);
    }
    
    if(right > left) // 待插入右括号的个数多余待插入左括号的个数
    {
        printf("left=%d, right=%d\r\n", left, right);
        item[index]=')'; // 插入右括号
        generate(item, index+1, left, right-1, result, count, n);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    int left = n, right = n;
    int length = 2*2*n;
    int count = 0; // 记录已经插入的个数
    int index = 0; // 记录当前插入元素的下标

    char **result = (char **)malloc(sizeof(char *)*(5000)); // 创建二维数组
    char *item = (char *)malloc(sizeof(char)*(2*n+1)); // 创建存储数组

    generate(item, index, left, right, result, &count, n);
    *returnSize=count;

    return result;
}
```
