思路：先找到最高的位置，然后左右分别遍历天坑，求和减去原始柱子高度和，搞定。

方法一，3次遍历
执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了98.45%的用户
内存消耗 :7.5 MB, 在所有 C 提交中击败了76.39%的用户

```
int trap(int* height, int heightSize){
    int total = 0;
    short maxIdx = 0;
    short tmph = 0;
    
    for (int i = 0; i < heightSize; i++) {
        total += height[i];
        if (height[maxIdx] < height[i]) {
            maxIdx = i;
        }
    }
    
    total = 0 - total;
    for (int i = 0; i < maxIdx; i++) {
        tmph = tmph < height[i] ? height[i] : tmph;
        total += tmph;
    }
    
    tmph = 0;
    for (int i = heightSize - 1; i >= maxIdx; i--) {
        tmph = tmph < height[i] ? height[i] : tmph;
        total += tmph;
    }
    
    return total;
}
```


方法二：优化一下，一次遍历搞定

执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了98.45%的用户
内存消耗 :7.4 MB, 在所有 C 提交中击败了87.50%的用户

```
int trap(int* height, int heightSize){
    int total = 0;
    short left = 0;
    short right = heightSize - 1;
    short tmph1 = 0;
    short tmph2 = 0;
    
    if (heightSize == 0) {
        return 0;
    }
    
    tmph1 = height[left];
    tmph2 = height[right];
    while (left < right) {
        if (tmph1 < tmph2) {
            left++;
            tmph1 = tmph1 < height[left] ? height[left] : tmph1;
            total += (tmph1 - height[left]);
        } else {
            right--;
            tmph2 = tmph2 < height[right] ? height[right] : tmph2;
            total += (tmph2 - height[right]);
        }
    }
    
    return total;
}
```