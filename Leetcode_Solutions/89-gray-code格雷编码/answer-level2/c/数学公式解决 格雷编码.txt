### 解题思路
    链接  https://leetcode-cn.com/problems/gray-code/solution/ge-lei-ma-shu-xue-xing-zhi-by-world-16/
    数学大法强无敌，大佬的思路真的棒 ~ ~ ~
### 代码

```c
int* grayCode(int n, int* returnSize){
    int num = 1 << n;
    int *a = malloc(sizeof(int) * num);
    for(int i = 0;i < num;i++)
        a[i] = (i >> 1) ^ i;
    *returnSize = num;
    return a;
}
```