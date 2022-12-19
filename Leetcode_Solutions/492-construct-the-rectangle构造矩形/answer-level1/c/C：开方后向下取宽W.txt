思路：
满足条件的宽W一定是小于等于area的平方根的，所以求平方根后向下递减找W
W 是第一个小于等于area平方根且能被area整除的数
```
int* constructRectangle(int area, int* returnSize){
    *returnSize = 2;
    int *ret = malloc(sizeof(int) * *returnSize);
    ret[1] = (int)sqrt(area);
    while(ret[1]){
        if(area % ret[1] == 0){
            ret[0] = area / ret[1];
            return ret; 
        }
        ret[1]--;
    }
    return NULL;
}
```
