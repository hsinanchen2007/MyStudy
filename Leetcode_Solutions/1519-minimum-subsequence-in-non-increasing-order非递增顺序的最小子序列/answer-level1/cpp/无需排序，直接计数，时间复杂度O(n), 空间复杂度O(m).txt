定义数组sort_arr[101], sort_arr[i]代表数字i出现的次数。

要满足长度最小与元素之和最大的条件，就需要从大往小选取数字，

计数完毕之后从后往前找sort_arr即可满足条件，直到满足所选数字之和大于剩余数字之和。

对于相同的数字，因为sort_arr[i]代表相同数字i的数量，所以需要选取sort_arr[i]个i之后再换下一个

```
int* minSubsequence(int* nums, int numsSize, int* returnSize){
    int i = 0, sum,sub_sum,count, pos_num, same_num_size;
    int sort_arr[101] = {0};
    int *ans = (int*)malloc(sizeof(int) * 501);
    sum = 0;
    for(i = 0; i < numsSize; i ++){
        sum += nums[i];
        sort_arr[nums[i]] ++;
    }
    sub_sum = 0;
    count = 0;
    i = 100;//从后往前，满足非递增
    same_num_size = 0;
    while(sub_sum <= (sum - sub_sum)){
        if(same_num_size == 0){
            //相同数字已经选完，换下一个数字
            while(sort_arr[i] == 0){
                i --;
            }
            //相同数字一共有sort_arr[i]个
            same_num_size = sort_arr[i];
            pos_num = i;
            i--;
        }
        ans[count++] = pos_num;
        sub_sum += pos_num;
        same_num_size --;
    }
    *returnSize = count;
    return ans;
}
```
