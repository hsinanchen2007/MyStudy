回溯算法的难点在于画出递归树，只要画出了递归树代码就不太难了。

回溯算法的优点是代码简单，清晰易懂。缺点是时间复杂，那么我们往往需要利用回溯加剪枝，这样就能够提升算法的效率。

那么我们再来分析一下这道题，存在N对括号，那么我们就可以假设一个字符串中有2N个待填入的空格，我们可以填入左括号或者右括号。

那么我就就可以把所有的情况枚举出来。

但是这里是有条件的，我们要求左括号的个数要大于等于右括号的个数。这个就是剪枝的条件了。

那么代码就不难了，不明白的欢迎留言~一定细心解答。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void generate(char *item,int index,int left,int right,char **result,int *count,int n)
 {
     if(left==0&&right==0)//已经全部插满了
        {
            result[(*count)]=(char*)malloc(sizeof(char)*(2*n+1));
            strcpy(result[(*count)++],item);
            return;
        }
        //result[(*count)++][]=item;
        item[index]='(';//插入左括号
        item[index+1]='\0';

        if(left>0)
        generate(item,index+1,left-1,right,result,count,n);
        if(right>left)//待插入右括号的个数多余待插入左括号的个数
        {
            item[index]=')';//插入右括号
            generate(item,index+1,left,right-1,result,count,n);
        }
 }
char ** generateParenthesis(int n, int* returnSize){
    int left=n,right=n;
    int length=2*2*n;
    int count=0;//记录已经插入的个数
    int index=0;//记录当前插入元素的下标

    char **result=(char **)malloc(sizeof(char *)*(5000));//创建二维数组
    char *item=(char *)malloc(sizeof(char)*(2*n+1));//创建存储数组

    generate(item,index,left,right,result,&count,n);
    *returnSize=count;

    return result;
}
```
