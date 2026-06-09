### 解题思路
此处撰写解题思路
题目是分糖果II，给小朋友依次循环分糖，每次多给一颗糖，直到糖分完为止；
实际上看完题目大概的思路就出来了，只是这种解法是最基础的，也是大家直接就能想出来的，利用while循环判断糖果是否分完，分完即停，使用一个计数变量来记录当前该分多少颗糖，利用mod方式获取小朋友的下标，给糖的时候判断糖果数量还够不够进行下一次的分糖；
我稍微压缩了一点代码，值得注意的是，分配完数组大小后记得数组清零，因为数组元素和需要等于candies
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    
    int *A = (int*)malloc(sizeof(int) * num_people);
    
    memset(A, 0, sizeof(int) * num_people);

    int i = 0;

    while((candies -= i++) && candies > 0)
    {
        A[(i-1)%num_people] += ((candies - i > 0) ? i : candies);
    }

    *returnSize = num_people;

    return A;
}
```