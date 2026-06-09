### 解题思路
![image.png](https://pic.leetcode-cn.com/a3fc38c647769335a5059e625718b02c21e2e634a780e83b5333b8ff71e6cc51-image.png)

### 代码

```c
int maxArea(int* height, int heightSize){
    int max_area;
    int tmp_area;
    int i, j;

    i = 0;
    j = heightSize - 1;
    max_area = 0;
    while (i != j) {
        int min_height;
        if (height[i] <= height[j]) {
            min_height = height[i];
            ++i;
        } else {
            min_height = height[j];
            --j;
        }
        tmp_area = min_height * (j - i + 1);
        if (tmp_area > max_area) {
            max_area = tmp_area;
        }
     }
    return max_area;
}
```