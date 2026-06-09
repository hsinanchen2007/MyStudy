### 解题思路
数组类型题目，解题思路为：

1.将数组分为三段，前段为从0到最大值；中断为两个最大值之间；后段为最大值到尾部。

2.每段的处理逻辑较为简单，分别处理即可：
    （1）前段遍历，记录最大值，如果遇到当前值大于最大值，则更新最大值；否则可以存水并记录
    （2）中断遍历，最大值已知，记录存水情况；
    （3）后段反向遍历，逻辑和前段相同。

例如：
[0,1,0,3,1,0,1,3,2,1,2,1]
[-前段- | -中段-| -后段- ]

![image.png](https://pic.leetcode-cn.com/5ce93ef486e7e595b91800b0453c0d493f14327f9f3197f997674d974ea963a2-image.png)



### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//【算法思路】数组。数组为为上升序列，水平序列和下降序列三部分，简化处理逻辑。
int trap(int* height, int heightSize){
    if(heightSize <= 1) {
        return 0;
    }

    //找到序列最大值,将序列分成三部分
    int max = height[0];
    int mid_s = 0;
    int mid_e = 0;

    for(int i = 1; i < heightSize; i++) {
        if(height[i] > max) {
            max = height[i];
            mid_s = i;
            mid_e = i;
        } else if(height[i] == max) {
            mid_e = i;
        }
    }

    //printf("max = %d, mid_s = %d, mid_e = %d\n", max, mid_s, mid_e);

    int sum = 0;

    //处理前段
    int last = height[0];
    for(int i = 1; i <= mid_s; i++) {
        if(height[i] > last) {
            last = height[i];
        } else {
            sum += last - height[i];
        }
    }

    //处理中段
    last = max;
    for(int i = mid_s + 1; i<= mid_e; i++) {
        sum += last - height[i];
    }

    //处理后段
    last = height[heightSize - 1];
    for(int i = heightSize - 2; i >= mid_e; i--) {
        if(height[i] > last) {
            last = height[i];
        } else {
            sum += last - height[i];
        }
    }

    return sum;
}
```