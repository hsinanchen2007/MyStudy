### 解题思路
先从左向右找，找到比自己大的，算出值。左会停在最高的位置
然后从右向左找，同样的思路。

### 代码

```c
int trap(int* height, int heightSize){
    int left = 0;
    int right = 2;
    int maxRain =0;

    if (heightSize < 3) {
        return 0;
    }
    // 找到有效的右边界
    for (int i = heightSize -1; i > 0; i--) {
        if(height[i-1] < height[i]) {
            right = i;
            break;
        }
    }
    //printf ("right %d\n",right);
    for (int i = 1; i <= right; i++) {
        if (height[i] >= height[left]) {         
            if (left < (i - 1)) {
                for (int j = left; j < i; j++) {
                    maxRain += height[left] - height[j];
                    //printf("left %d, right %d, maxrain %d\n",left, right, maxRain);
                }
            }
            left = i;
            continue;
        } 
    }
    for (int i = right; i >= left; i--) {
        if (height[i] >= height[right]) {
            if(right > i + 1) {
                 for (int j = right; j > i ; j--) {
                    maxRain += height[right] - height[j];
                }
            }
            right = i;
        }
    }
    return maxRain;
}
```