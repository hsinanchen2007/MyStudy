### 解题思路
思路
找到当前元素左边第一个比它小的元素，果断单调递减栈，从右往前遍历。

ps 单调栈应用范围
求解数组中元素右边第一个比它小的元素的下标，从前往后，构造单调递增栈；
求解数组中元素右边第一个比它大的元素的下标，从前往后，构造单调递减栈；
求解数组中元素左边第一个比它小的元素的下标，从后往前，构造单调递减栈；
求解数组中元素左边第一个比它小的元素的下标，从后往前，构造单调递增栈。

作者：huangyt
链接：https://leetcode-cn.com/problems/maximum-width-ramp/solution/dan-diao-di-jian-zhan-on-by-huangyt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

转化后同[962. 最大宽度坡](//leetcode-cn.com/problems/maximum-width-ramp/solution/dan-diao-di-jian-zhan-on-by-huangyt/)
### 代码

```c
int longestWPI(int* hours, int hoursSize){
    int isTired[hoursSize];// 标记“劳累的一天”和“不劳累的一天”， 1 vs -1
    for(int i = 0; i < hoursSize; i++){
        isTired[i] = hours[i] > 8 ? 1 : -1;//双目算符
    }
    int preSum[hoursSize + 1];//记录下到第i天“表现良好的时间段”的天数
    preSum[0] = 0;//增加一个头元素0
    for(int i = 1; i <= hoursSize; i++){
        preSum[i] =preSum[i - 1] + isTired[i - 1];
    }
    // 问题转化为：求preSum[]数组的最大宽度坡，构造单调递减栈
    int *stack = (int *)malloc(hoursSize * sizeof(int));
    int stackSize = 0;
    for(int i = 0; i < hoursSize; i++){
        if(stackSize == 0 || preSum[stack[stackSize - 1]] > preSum[i]){
            stack[stackSize++] = i;//推入数组首元素下标，或，小于栈顶元素即推入下标
        }
    }//得到一个按照下标排列的递减栈
    int res = 0;
    int i = hoursSize;
    int tmp;
    --stackSize;// 恢复栈长度
    while(i >= 0){
        while(stackSize >= 0 && preSum[stack[stackSize]] < preSum[i]){
            tmp = i - stack[stackSize];//找到元素左边第一个小于他的元素，出栈，继续比较
            res = res > tmp ? res : tmp;//记录下表差值，即坡的宽度
            stackSize--;
        }
        i--;
    }
    return res;
}
```