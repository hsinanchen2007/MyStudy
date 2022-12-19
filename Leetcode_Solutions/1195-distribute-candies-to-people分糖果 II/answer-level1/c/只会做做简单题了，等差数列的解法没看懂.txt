执行用时 : 4 ms , 在所有 C 提交中击败了 74.52% 的用户 内存消耗 : 7 MB , 在所有 C 提交中击败了 95.71% 的用户

只需要在while判断剩余的candies数量，不需要再做其他判断了，如果循环结束了canditmp是负数或0，更新下最后一位小朋友的candies数量就行了。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* a = (int* )malloc(num_people*sizeof(int));
    memset(a,0,num_people*sizeof(int));
    int dis = 0;
    int index = -1;
    int canditmp = candies;
    while(canditmp>0){
        dis++;
        index++;
        a[index%num_people]+=dis;
        canditmp-=dis;
    }
    a[index%num_people]+=canditmp;
    *returnSize = num_people;
    return a;
}
```
