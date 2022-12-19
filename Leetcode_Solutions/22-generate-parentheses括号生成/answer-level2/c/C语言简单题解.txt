典型的递归，C语言麻烦的地方在于怎么把有效的括号组合保存下来，一种方法是用一个u32来保存，但是u32只能支持n<=16的情况，不过这个题目的用例不多，好像n也不是很大，有人尝试也可以通过。另外一种方法是用一个全局字符数组来保存每次递归的结果，在递归结束满足条件的时候copy到返回的数组中取；需要注意的是递归回溯的时候更新全局数组的下标需要回退回去。其次是剪枝的时候要判断right始终是小于left的。
 int    pos;
 char   *cur;
int genParenthesis(int left, int right, int  n, char **rst, int count)
{
    if (left == n && right == n) {
        cur[pos] = '\0';
        strcpy(rst[count], cur);
         count++;
        return count;
    }
    if (right > left) {
        return count;
    }
    if (left < n) {
        cur[pos++] = '(';
        count = genParenthesis(left + 1, right, n, rst, count);
        pos--;
    }
    if (right < n) {
        cur[pos++] = ')';      
        count = genParenthesis(left, right + 1, n, rst, count);
        pos--;
    }
    
    return count;
}

char ** generateParenthesis(int n, int* returnSize){
    int     i, count;
    char    **rst;
    count = 1 << (2 * n - 1);
    rst = (char **)malloc(sizeof(char *) * count);
    for (i = 0;i < count; i++) {
        rst[i] = (char *)malloc(sizeof(char) * (2 * n + 1));
    } 
    cur = (char *)malloc(sizeof(char) * (2 * n + 1));
    count = 0;
    pos = 0;
    count = genParenthesis(0, 0, n, rst, count);
    *returnSize = count;
    free(cur);
    return rst;
}