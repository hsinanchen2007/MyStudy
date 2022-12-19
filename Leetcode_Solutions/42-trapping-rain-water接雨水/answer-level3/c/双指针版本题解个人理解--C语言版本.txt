
# 提交结果
0ms 100%
6.1MB 100%
x_x 这个结果有点意外，0ms不知道怎么得出来的

我的双指针应该多计算了开头和结尾，不过也懒得改了.

# 解释:

**假如存在最高峰，那么峰左边，数据趋势是向上增加的; 峰右边，数据趋势是向下递减的.**
对于最高点左侧，找到第一个波峰，然后向右查，只要比这个波峰小，那么就加上去差值，否则就是下一个波峰，再更新差值基数，再累加.
对于最高点右侧，同理.

**但是，对于双指针这个操作，不知道最高峰在哪里，因为没有遍历过.**
所以两侧交错更新各自的波峰，往最高峰靠拢, 这样就可以一次遍历即可得到雨水总数，还可以顺便得到最高峰.

# 代码展示
```
int trap(int* height, int heightSize){
/*
                       top2 == top1 
                        __     __
                       |  |   |  |
           __          |  |   |  |   __            __
          |  |    __   |  |   |  |  |  |    __    |  |
    __    |  |   |  |  |  |   |  |  |  |   |  |   |  |
   |__|___|__|___|__|__|__|___|__|__|__|___|__|___|__|

 */
        /*double pointer */
        int result = 0;
        int left_index = 0;
        int right_index = heightSize - 1;
        int left_max = 0, right_max = 0;
        
        if (heightSize < 2) {
                result = 0;
                goto out;
        }
        
        left_max = height[left_index];
        right_max = height[right_index];

        while(right_index - left_index >= 1) {
                if(left_max <= right_max) {
                        //calcute left
                        result += (left_max - height[left_index] > 0) ? (left_max - height[left_index]) :0;
                        left_index++;
                        //update left max
                        left_max = left_max > height[left_index] ? left_max : height[left_index];
                }
                else {
                        //calcute right
                        result += (right_max - height[right_index] > 0) ? (right_max - height[right_index]) : 0;
                        right_index--;
                        //update right_max
                        right_max = right_max > height[right_index] ? right_max : height[right_index];
                }
        }

out:
        return result;

}
```
