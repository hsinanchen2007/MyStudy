# 解题思路：
1. 设置两个指针i，j遍历字符串，i停在当前数，j停在下一个不等于i的数上。设置一个指针m用在结果数组中，指示当前位置。
1. 若j与i的距离大于等于三，说明中间至少有三个相同的字符，则符合条件，将当前坐标存入结果数组中。
1. 刚开始先将结果数组的空间（即行数）初始化为strlen/3，因为只有大于三个的字符才满足条件，所以存储的坐标数必然小于strlen/3。之后在遍历字符串时，找到符合条件的坐标时，再初始化结果数组的子空间（即列数）。

**备注：**
returnSize 用于存放结果数组的行数，最后赋值一遍即可。
returnColumnSizes 用于存放每一个子空间的大小（即列，也就是固定为2）。(*returnColumnSizes)[m] 对应第m行的列数。（本来我没想明白returnColumnSizes的用处，看了别人的题解才理解）
PS：中间在执行时出过问题，但再执行一次又没问题了。提交时也是第一次出错，但同样的代码提交第二次就通过了。

执行用时：12ms，击败67.33%。
内存消耗：6.5MB，击败100%。


```
int** largeGroupPositions(char * S, int* returnSize, int** returnColumnSizes){
    int len = strlen(S);
    //申请一个长度为字符串1/3的数组，必定够用
    int** res = (int**)malloc(sizeof(int*) * (len/3));
    char temp;
    int i=0, j, m=0; //i，j指针遍历S字符串，m指向结果数组
    while(i < len){
        temp = S[i];
        j = i+1;
        while(j < len && S[j] == temp){ //j停在不同于i的下一个数上
            j++;
        }
        if(j-i >= 3){ //如果大于等于三个，存入结果中
            res[m] = (int*)calloc(2, sizeof(int)); //结果数组申请空间
            res[m][0] = i;
            res[m][1] = j-1;
            (*returnColumnSizes)[m] = 2;
            m++;
        }
        i = j;
    }
    *returnSize = m;
    return res;
}
```
