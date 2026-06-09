### 解题思路
维护递增单调栈，从小到大遍历数组，看到比当前值小的，即可得到右向最大长度；
从大到小再遍历一次，可以得到左向最大长度；
加起来，即为当前高度下长方形长度最大值；
然后计算乘积最大值。
![image.png](https://pic.leetcode-cn.com/87e2f160b0f0957157711029abfb8b1e49cd953a4cca8652a1de1f40211764a7-image.png)



### 代码

```c
typedef struct
{
    int index;
    int val;
}Temp;
int largestRectangleArea(int* heights, int heightsSize){
    int* long_right = (int*)malloc(sizeof(int) * heightsSize);
    int* long_left = (int*)malloc(sizeof(int) * heightsSize);
    Temp* stack = (Temp*)malloc(sizeof(Temp) * heightsSize);
    int i;
    int max = 0;
    for(i = 0; i < heightsSize; i++) {
        long_right[i] = 0;
        long_left[i] = 0;
    }
    
    int top = -1;
    for(i = 0; i < heightsSize; i++) {
        while(top > -1 && stack[top].val > heights[i]) {
            long_right[stack[top].index] = i - stack[top].index;
            top--;
        }
        top++;
        stack[top].val = heights[i];
        stack[top].index = i;
    }
    
    for(i = 0; i < top + 1; i++) {
        long_right[stack[i].index] = heightsSize - stack[i].index;
    }

    top = -1;
    for(i = (heightsSize - 1); i >= 0; i--) {
        while(top > -1 && stack[top].val > heights[i]) {
            long_left[stack[top].index] = stack[top].index - i - 1;
            top--;  
        }
        top++;
        stack[top].val = heights[i];
        stack[top].index = i;
    }
    
    for(i = 0; i < top; i++) {
        long_left[stack[i].index] = stack[i].index;
    }

    for(i = 0; i < heightsSize; i++) {
        printf("num[%d] right:%d left:%d\n", i, long_right[i], long_left[i]);
        long_left[i] = long_left[i] + long_right[i];
        max = fmax(max, heights[i] * long_left[i]);
    }
    return max;
}
```