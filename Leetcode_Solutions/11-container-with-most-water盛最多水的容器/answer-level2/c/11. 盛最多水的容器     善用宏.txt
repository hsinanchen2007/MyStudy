### 解题思路
1：双指针计算
2：看评论有说左右数一样时，两边都应该向中间挪动，但提交并无明显作用
3：利用宏做比较运算效果会比较好

### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))

int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int maxA = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            maxA = MAX(maxA, height[left]*(right - left));
            left++;
        } 
        else {
            maxA = MAX(maxA, height[right]*(right - left));
            right--;
        }  
    }
    return maxA;
}
```