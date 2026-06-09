执行结果：通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了99.31%的用户
内存消耗 :7.8 MB, 在所有 C 提交中击败了74.84%的用户

```
int maxArea(int* height, int heightSize){
    int max = 0;
    int min = 0;
    int tmp = 0;
    int i = 0;
    int j = heightSize - 1;
    
    while (i < j) {
        min = height[i] < height[j] ? height[i] : height[j];
        tmp = min * (j - i);
        max = tmp > max ? tmp : max;
        while (height[i] <= min && i < j) ++i;
        while (height[j] <= min && i < j) --j;
    }
    
    return max;
}
```