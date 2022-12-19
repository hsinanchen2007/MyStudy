![2019-09-23_06-16.png](https://pic.leetcode-cn.com/267a99a884ece2786041fe912f74cade7c05ec3c9ac1fdae7ef3aedf89d80a77-2019-09-23_06-16.png)

```c
int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int pivot = 0;
    int maxV = 0;
    int V = 0;

    while (right > left) {
        pivot = (height[left] > height[right])? height[right]: height[left];
        V = pivot * (right - left);
        maxV = V > maxV? V: maxV;
        if (height[left] > height[right])
            while (height[--right] < pivot);
        else
            while (height[++left] < pivot);
    }

    return maxV;
}
```