
排序法：
C与C++库中有qsort函数，在 stdlib.h 中声明。该函数可以对任何类型的一维数组排序。使用语句：qsort(nums, numsSize, sizeof(int), compare);。
compare函数的原型：int 函数名(const void * elem1, const void * elem2);该函数的两个参数，elem1 和elem2，指向待比较的两个元素。
　　1) 如果 * elem1 应该排在 * elem2 前面，则函数返回值是负整数（任何负整数都行）
　　2) 如果 * elem1 和* elem2 哪个排在前面都行，那么函数返回0
　　3) 如果 * elem1 应该排在 * elem2 后面，则函数返回值是正整数（任何正整数都行）
排序之后，在第n/2的元素必然是众数。
```c
int compare(const void *a, const void *b){
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa)- (*pb);  
//or return *(int *)a - *(int *)b; //均为从小到大排序
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[numsSize/2];
}
```


摩尔投票法：
评论区的解释很优秀：核心就是对拼消耗。玩一个诸侯争霸的游戏，假设你方人口超过总人口一半以上，只要你们不要内斗，最后肯定你赢。最后能剩下的必定是自己人。
先假设第一个队伍能赢；遍历后面的数如果相同（碰到友军人数+1）则cnt++，不同（碰到敌人战死-1）则cnt--，当cnt为0时放弃这个队，投注于下一个出现的队。就这样墙头草一样投注给当前最强的队伍，最后剩下的队伍一定就是赢的队伍。
```c
int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int cnt=0;
    for (int i = 0; i < numsSize; i++){
        nums[i]==key ? cnt++:cnt--;
        if(cnt <= 0){
            key = nums[i+1]; //换对
        }       
    }
    return key;
}
```