### 解题思路
贪心算法，每次选择当前能跳范围内中，下一步最远的点。

### 代码

```c
int jump(int* nums, int numsSize){
    int current_max_index = nums[0];
    int pre_max_index = nums[0];
    int jump_step = 1;
    if(numsSize < 2)
        return 0;
    for(int i = 1; i < numsSize; i++){
        if(i > current_max_index){
            jump_step++;
            current_max_index = pre_max_index;
        }
        if(nums[i] + i > pre_max_index){
            pre_max_index = nums[i] + i;
        }
    }
    return jump_step;
}
```

![image.png](https://pic.leetcode-cn.com/983bad665486fed1309c720c10821c92176600767d52022cc49a40dcd03e3ed0-image.png)
