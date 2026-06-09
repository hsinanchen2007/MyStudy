自己的代码
```
//动态规划解法，使用两数组分两轮计算从两侧到height[i]的最大高度
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int trap(int* height, int heightSize){
    int *left_max  = (int *)malloc(sizeof(int) * heightSize);
    int *right_max = (int *)malloc(sizeof(int) * heightSize);
    int  i         = 0;
    int  res       = 0;

    if (heightSize == 0) {
        return 0;
    }

    memset(left_max,  0, sizeof(int) * heightSize);
    memset(right_max, 0, sizeof(int) * heightSize);

    left_max[0] = height[0];
    for (i = 1; i < heightSize; i++) {
        left_max[i] = MAX(height[i], left_max[i - 1]);
    }

    right_max[heightSize - 1] = height[heightSize - 1];
    for (i = heightSize - 2; i >= 0; i--) {
        right_max[i] = MAX(height[i], right_max[i + 1]);
    }

    for (i = 0; i < heightSize; i++) {
        res += MIN(left_max[i], right_max[i]) - height[i];
    }

    return res;
}
```


官方最优解，遍历一次
```
int trap(int* height, int heightSize){
    int left      = 0;
    int right     = heightSize - 1;
    int left_max  = 0;
    int right_max = 0;
    int res       = 0;
    while (left < right) {
        if (height[left] < height[right]) {
			height[left] > left_max ? (left_max = height[left]) : (res += left_max - height[left]);
			left++;
		} else {
			height[right] > right_max ? (right_max = height[right]) : (res += right_max - height[right]);
			right--;
		}
    }
    return res;
}
```
