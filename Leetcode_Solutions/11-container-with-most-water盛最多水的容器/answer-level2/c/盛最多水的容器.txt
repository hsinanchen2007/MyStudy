### 解题思路
1:面积最大，尽量让高和宽大
2:首先，选择最大的宽度，计算面积
3：收缩寻找更优解：短板效应，找出短的那一块，让他向里面收缩，争取让他变长，这样短的向里可能会有更优解
### 代码

```c
int maxArea(int* height, int heightSize){
    int left = 0,right=heightSize-1;
    int maxArea = 0;
    int curArea = 0;
    while(left < right){
        curArea = (right-left)*(height[left]>height[right]?height[right]:height[left]);
        if(curArea > maxArea) maxArea = curArea;
        if(height[left]>height[right]) right--;
        else left++;
    }
    return maxArea;
}
```