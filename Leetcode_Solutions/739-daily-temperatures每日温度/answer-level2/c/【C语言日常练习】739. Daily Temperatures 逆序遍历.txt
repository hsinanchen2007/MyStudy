### 解题思路
    //从右向左遍历法，倒数第一个为0， 从倒数第二个开始
     /*从i+1开始遍历，如果T[j]比T[i]大，则返回j-i
        如果T[j]比T[i]小，且day[j]为0，则day[i]为0
        如果T[j]比T[i]小，且T[j]不为0，遍历下标为j+day[j]的数组元素，
        这一步可以避免重复比较处理操作
    */

### 代码

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int*day=(int*)malloc(TSize * sizeof(int));
    memset(day, 0, sizeof(int)*TSize); 

    for(int i = TSize - 2; i>=0; i--){
        for(int j = i+1; j<= TSize - 1;j+=day[j]){
            if(T[j] > T[i]){
                day[i] = j - i;
                break;
            }else if(day[j] == 0){
                day[i] = 0;
                break;
            }
        }
    }
    *returnSize = TSize;
    return day;
}