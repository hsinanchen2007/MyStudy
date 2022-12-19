### 解题思路
使用几个变量分别记录当前状态
left_arr_index  -> 目前左边数组结束index
left_arr_big    -> 目前左边数组包含的最大值
now_big         -> 目前遍历到i节点时遇到的最大的值

### 代码

```c
int partitionDisjoint(int* A, int ASize){
    int mm = A[0];
    int i = 0;
    int left_arr_index = 0;
    int left_arr_big = A[0];
    int now_big = A[0];
    
    for(i=1;i<ASize;i++)
    {
        if(A[i] > now_big)
        {
            now_big = A[i];
        }
        if(A[i] < left_arr_big)
        {
            left_arr_big = now_big;
            left_arr_index = i;
        }
    }
    return left_arr_index + 1;
}
```