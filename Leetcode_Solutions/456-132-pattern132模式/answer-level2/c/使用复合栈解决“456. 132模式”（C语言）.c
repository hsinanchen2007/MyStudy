### 解题思路
本题解效率并非最高，但思路更为直观。

本题是典型的复合栈问题。这里给出C语言的解法。

1.建立栈，**栈中元素记录当前最小值min，以及该值出现后的最大值max**。

2.遍历数据，分情况判断。

3.当前数据A小于栈顶元素的min，需要向栈中压入新元素，max和min都为A。

4.当前数据A大于栈顶元素的max，更新栈顶元素max为A，同时反向遍历站内元素：
(1)站内元素的最小值大于等于A，停止遍历，不会再出现132模式

(2)站内元素的min和max与A构成132模式，返回true

5.当前数据A与栈顶元素min或max相等，无需处理

6.当前元素A与栈顶元素构成132模式，返回true

7.遍历完成无法找到，返回false

![image.png](https://pic.leetcode-cn.com/e94fea7a5d277ea2b2e6e9d2e03b5775b4955972cea0b7cc560dde48115606d2-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _info_st {
    int max;
    int min;
}info_st;

//【算法思路】复合栈。栈中元素记录当前最小值和最大值
bool find132pattern(int* nums, int numsSize){
    if(numsSize < 3) {
        return false;
    }

    info_st *stk = (info_st *)calloc(numsSize, sizeof(info_st));
    int ssize = 0;

    stk[ssize].max = nums[0];
    stk[ssize].min = nums[0];
    ssize++;

    for(int i = 1; i < numsSize; i++) {
        if(nums[i] > stk[ssize - 1].max) {
            //当前值大于栈顶最大值，需要尝试向前匹配
            for(int j = ssize - 1; j >= 0; j--) {
                if(nums[i] <= stk[j].min) {
                    //站内数据min逐渐降低，反向遍历时已经小于当前min，则退出
                    break;
                } else if(nums[i] > stk[j].min && nums[i] < stk[j].max) {
                    //在前面找到了匹配模式
                    return true;
                }
            }

            stk[ssize - 1].max = nums[i];
        } else if(nums[i] == stk[ssize - 1].max || nums[i] == stk[ssize - 1].min) {
            //和栈顶上下限相等，无需处理
            continue;
        } else if(nums[i] < stk[ssize - 1].min) {
            //小于栈顶下限，需要新开辟栈元素
            stk[ssize].max = nums[i];
            stk[ssize].min = nums[i];
            ssize++;
        } else {
            //找到匹配的模式
            return true;
        }
    }

    return false;
}
```