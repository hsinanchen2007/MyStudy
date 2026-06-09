### 解题思路
![Snipaste_2020-03-09_17-16-49.png](https://pic.leetcode-cn.com/fabc55e0b3a5092ee6cc9ae0f6542bdf2edf8337c31e999f42fe7dcd02d0d6d4-Snipaste_2020-03-09_17-16-49.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isSelfDiv(int x){
    if(x==0) return false;
    int tmp=x;
    while(x!=0){
        int y=x%10;
        if(y==0||tmp%y!=0) return false;
        x/=10;
    }
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int count=0,i;
    int *num=(int *)malloc(sizeof(int)*200);
    for(i=left;i<=right;i++){
        if(i==0) continue;
        if(isSelfDiv(i)){
            num[count]=i;
            count++;
        }
    }
    *returnSize=count;
    return num;

}
```