使用了暴力解法
直接按问题描述进行。对于数组中的每个元素，我们找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值。

int trap(int* height, int heightSize)
{
    int i = 0;
    int j = 0;
    int total = 0;
    int max_left = 0;
    int max_right = 0;
    int temp = 0;

    for (i = 1; i < heightSize - 1; i++) {
        max_left = 0;
        //计算左边能达到的最高值
        for (j = i - 1; j >= 0; j--) {
            max_left = MAX(max_left, height[i - 1]);
        }
        max_right = 0;
        //计算右边能达到的最高值
        for (j = i + 1; j < heightSize; j++) {
            max_right = MAX(max_right, height[j]);
        }
        //计算面积，宽度都是1，不需要额外乘
        temp = MIN(max_left, max_right);
        if (temp >= height[i]) {
            total += (temp - height[i]);
        }
    }
    return total;
}

这个解法会超时，优化了一下


#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

int trap(int* height, int heightSize)
{
    int i = 0;
    int j = 0;
    int total = 0;
    int max_left = 0;
    int max_right = 0;
    //右边最大值坐标
    int max_r_index = 0;
    int temp = 0;

    for (i = 1; i < heightSize - 1; i++) {
        //左边坐标不停右移，不需要循环遍历，比较最新的左边坐标和历史最高值即可
        max_left = MAX(max_left, height[i - 1]);
        //第一次进行遍历，以及右移之后，当最大值坐标超出最大值范围，再重新计算
        if (max_right == 0 || i + 1 > max_r_index) {
            max_right = 0;
            for (j = i + 1; j < heightSize; j++) {
                if (max_right <= height[j]) {
                    max_right = height[j];
                    max_r_index = j;
                }
            }
        }

        temp = MIN(max_left, max_right);
        if (temp >= height[i]) {
            total += (temp - height[i]);
        }
    }
    return total;
}