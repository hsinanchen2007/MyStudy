### 解题思路
单调栈的经典问题，这里给出c语言的解法

0.构造单调栈用于记录数据id
1.遍历数据
2.当数据增长时，入栈
3.当数据降低时，进行结算：高度为栈顶id对应的高度，宽度为栈顶前一个数据到i
4.数据入栈完毕，结算栈中数据：高度为栈顶id对应的高度，宽度为栈顶前一个数据到终点

![image.png](https://pic.leetcode-cn.com/7530fa2bf96dddacdcd5f7abe4bb8c5e4a2a6a2370f60ae19ed5bd552c60c338-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MMAX(a, b)      ((a) > (b)? (a) : (b))

//【算法思路】单调栈。经典的单调栈问题，用于解决柱状图中的最大矩形。
// 1.当数据增长时，直接入栈
// 2.当数据降低时，进行结算，注意结算的位置为从i到stk[top - 1]
// 3.数据处理完成，对于栈中数据进行处理，结算位置从stk[top - 1]到终点
// 4.注意当top为0时，起点为-1
int largestRectangleArea(int* heights, int heightsSize){
    if(heightsSize == 1) {
        return heights[0];
    } else if(heightsSize == 0) {
        return 0;
    }
    int *stk  = (int *)calloc(heightsSize, sizeof(int));
    int ssize = 0;

    stk[ssize++] = 0;
    int max = heights[0];

    for(int i = 1; i < heightsSize; i++) {
        if(heights[i - 1] <= heights[i]) {
            //单调增
            stk[ssize++] = i;
        } else {
            //发现小的高度，进行结算
            while(ssize > 0) {
                int top = ssize - 1;  
                int id = stk[top];
                if(heights[id] <= heights[i]) {
                    break;
                }

                max = MMAX(max, heights[id] * (i - (top == 0? -1 : stk[top - 1]) - 1));
                ssize--;

                //printf("max = %d\n", max);
            }

            stk[ssize++] = i;
        }
/*
        for(int i_ = 0; i_ < ssize; i_++) {
            printf("%d    ", stk[i_]);
        }
        printf("\n");
*/
    }

    //处理栈中数据，所有数据左侧延申到前面更低的位置，右边延申到最右侧

    for(int i = 0; i < ssize; i++) {
        max = MMAX(max, heights[stk[i]] * (heightsSize - (i == 0? -1 : stk[i - 1]) - 1));
        //printf("--max = %d\n", max);
    }

    return max;
}
```