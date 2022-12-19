### 解题思路

滑动窗口，一次只动一个指针，并且每次只动一步：
右指针移动，sum++，一次只动一步。
如果sum超过了阈值，就开始循环向右移动左指针，每次只移动一步，将左边的值减去。
需要注意的是min值的记录。
首先min的初始值不能给0，否则没法进行判断，可以给一个超大值，如0xfffffff。

其次，min的值需要在判断sum >= s时马上给出，否则后续执行了left++，当前的状态就不一定再是sum >= s满足这个条件的了。


### 代码

```c
int minSubArrayLen(int s, int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int sum = 0;
    int left = 0;
    int right = 0;
    int min = 0xfffffff;
    
    while (right < numsSize && left <= right) {
        sum += nums[right];
        right++;
        while (sum >= s) {
            min = min <= (right - left) ? min : (right - left);
            sum -= nums[left++];         
        }
    }

    return min < 0xfffffff ? min : 0;
}
```