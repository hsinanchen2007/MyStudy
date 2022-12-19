### 解题思路
定义两个数组分别存放solution和guess的字符数量，两者取最小值即为包含猜中总量，减去真猜的的就是伪猜数。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int* masterMind(char* solution, char* guess, int* returnSize){
    int i,count=0;
    int *res = (int*)malloc(sizeof(int)*2);
    int c1[26]={0},c2[26]={0};
    res[0]=0;
    res[1]=0;
    *returnSize=2;
    for(i=0;i<4;i++)
    {
        if(solution[i]==guess[i])
            res[0]++;
        c1[solution[i]-'A']++;
        c2[guess[i]-'A']++;
    }
    for(i=0;i<26;i++)
    {
        count += min(c1[i],c2[i]);
        res[1]=count-res[0];
    }
    return res;
}
```