C语言动态数组的生成-----使用malloc()函数
栈的思想----使用两个栈，通过比较两个栈顶元素来实现删除相邻重复项
char * removeDuplicates(char * S){
    int len = strlen(S);
    char *s1 = (char *)malloc(sizeof(char)*len);
    char *s2 = (char *)malloc(sizeof(char)*len);
    int top1 = len - 1, top2 = -1, flag = 1;

    for(int i = len - 1, j = 0; i >= 0, j < len; i--, j++)
    {
        s1[j] = S[i];
    }
    for(top1 = len - 1; top1 >= 0; top1--)
    {
        if(top2 == -1)   //边界处理
        {
            s2[++top2] = s1[top1];
        }
        else
        {
            if(s1[top1] != s2[top2])
            {
                s2[++top2] = s1[top1];
            }
            else{
                top2--;
            }
        }
    }
    s2[top2+1] = '\0';
    return s2;
}
执行用时 :12 ms, 在所有 c 提交中击败了61.34%的用户
内存消耗 :9.1 MB, 在所有 c 提交中击败了100.00%的用户
