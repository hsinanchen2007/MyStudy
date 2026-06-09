### 解题思路
常规思路，遍历加判断

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool check(int n){
    bool flag=false;
    while(n){
        if(n%10==0){
            flag=true;
            break;
        }
        n=n/10;
    }
    return flag;
}

int* getNoZeroIntegers(int n, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    int i;
    for(i=1;i<=n/2;i++){
        if(!check(i)&&!check(n-i))
            break;
    }
    res[0]=i;
    res[1]=n-i;
    return res;
}
```