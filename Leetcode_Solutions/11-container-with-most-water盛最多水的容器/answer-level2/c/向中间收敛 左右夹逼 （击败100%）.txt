### 解题思路
此处撰写解题思路

### 代码

```c
int maxArea(int* height, int heightSize){
    int area = 0;
    int max = 0;
    int i = 0, j = heightSize - 1;
    for (i, j; i < j; ) {
        if (height[i] <= height[j]) {
            area = (j - i) * height[i];
            i++;
        } 
        else {
            area = (j - i) * height[j];
            j--;
        }
        if (area > max) {
            max = area;
        }
    }
    return max;
}
```