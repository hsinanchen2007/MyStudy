### 解题思路
这道题考察的重点在模运算，就是用取余法寻找要更新的数组下标。让dex自增，用dex%num_people求下标。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* ans=(int*)malloc(sizeof(int)*num_people);
    for(int i=0;i<num_people;i++){
        ans[i]=0;
    }
    if(candies<=0){
        *returnSize=num_people;
        return ans;
    }
    int count=1;
    int dex=0;
    while(count<=candies){
        dex=dex%num_people;
        ans[dex]+=count;
        candies-=count;
        count++;
        dex++;
    }
    ans[dex%num_people]+=candies;
    *returnSize=num_people;
    return ans;
}
```
这两天又想到了一个代码更少的写法，思路一样代码少了点
```c
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *output=(int*)calloc(sizeof(int),num_people);
    *returnSize=num_people;
    int n=1;int i;
    for(i=0;candies>n;i=(i+1)%num_people){
        output[i]=output[i]+n;
        candies=candies-n;
        n++;
    }
    output[i]=output[i]+candies;
    return output;
}
```