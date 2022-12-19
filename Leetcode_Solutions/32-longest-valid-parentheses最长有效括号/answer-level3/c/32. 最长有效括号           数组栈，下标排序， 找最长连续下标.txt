### 解题思路
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"



参考powcai 同学
常规思路1:

对于这种括号匹配问题,一般都是使用栈

我们先找到所有可以匹配的索引号,然后找出最长连续数列!

例如:s = )(()()) ,我们用栈可以找到,

位置2和位置3匹配,

位置4和位置5匹配,

位置1和位置6匹配,

这个数组为:2,3,4,5,1,6这是通过栈找到的,我们按递增排序!1,2,3,4,5,6

找出该数组的最长连续数列的长度就是最长有效括号长度!

### 代码

```c

//升序
int cmp(const void * _a, const void *_b){
    int * a = _a;
    int * b = _b;

    return *a - *b;
}

int longestValidParentheses(char * s){
    int i,j=0,len,top=0,temp_len=0,max_len=0;
    int *stack;
    int *arr;

    len = strlen(s);
    arr = malloc(len * sizeof(int));

    stack = (int *)malloc(len*sizeof(int));
    memset(stack,0,len*sizeof(int));

    for(i=0;i<len;i++){
        if(s[i] == '('){
            stack[top++] = i;
        }else if(top > 0){
            top--;
            arr[j++] = i;
            arr[j++] = stack[top];
        }
    }

    qsort(arr,j,sizeof(int),cmp);

    for(i=0;i<j-1;i++){
        if(arr[i+1] == arr[i]+1){
            temp_len++;
            if(temp_len > max_len)
                max_len = temp_len;
        }else{
            temp_len = 0;
        }
    }
    if(max_len)
        return max_len+1;
    else
        return max_len;
}
```