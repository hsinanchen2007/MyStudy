```
int maxArea(int* height, int heightSize){
    int maxArea = 0;
    int i       = 0;
    int j       = heightSize - 1;
    while(j > i) {
        int temp = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
        maxArea  = temp > maxArea ? temp : maxArea;
        height[i] < height[j] ? i++ : j--;
    }
    return maxArea;
}
```
