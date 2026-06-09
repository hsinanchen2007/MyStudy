
```c
//交换函数
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
//非递减字符排序函数
int cmp(const void *a, const void *b){
    return *(char*)a > *(char*)b;
}
//题目函数
int nextGreaterElement(int n){
    if (n < 10)
        return -1;
    //将n转化为字符数组
    char nums[33];
    sprintf(nums, "%d", n);
    int len = strlen(nums);
    int i = len - 1;
    for (; i > 0; i--){
        //从右到左找到第一个大于它左边紧邻的数(实际为数字字符)nums[i]
        if (nums[i] > nums[i - 1]){
            //nums[i]以及其后的数非递减排序
            qsort(&nums[i], len - i, sizeof(char), cmp);
            //找到排序后的nums[i]以及其以后的数中第一个大于nums[i - 1]的数(即大于nums[i - 1]的最小数)
            for (int j = i; j < len; j++){
                if (nums[j] > nums[i - 1]){
                    //找到后交换两者位置
                    swap(&nums[j], &nums[i - 1]);
                    break;
                }
            }
            break;
        }
    }
    //本来就是非递减排序的数
    if (i == 0)
        return -1;
    //可能会有结果超过int表示范围的情况，比如：1999999999
    long N;
    sscanf(nums, "%ld", &N);
    if (N > INT_MAX)
        return -1;
    return (int)N;
}


```