### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)

int maxArea(int* height, int heightSize){
    /* 输入有效性判断 */
    if ((height == NULL) || (heightSize < 2)) {
        return 0;
    }

    int leftIdx, rightIdx;
    int max = 0;

    leftIdx  = 0;
    rightIdx = heightSize - 1;

    while (leftIdx < rightIdx) {
        //printf("start:leftIdx:%d; rightIdx:%d\n", leftIdx, rightIdx);
        if (height[leftIdx] < height[rightIdx]) {
            max = MAX(max, height[leftIdx] * (rightIdx - leftIdx));
            leftIdx++;
        } else {
            max = MAX(max, height[rightIdx] * (rightIdx - leftIdx));
            rightIdx--;
        }
        //printf("max:%d\n", max);
        //printf("end:leftIdx:%d; rightIdx:%d\n", leftIdx, rightIdx);
    } 
    return max;
}
```