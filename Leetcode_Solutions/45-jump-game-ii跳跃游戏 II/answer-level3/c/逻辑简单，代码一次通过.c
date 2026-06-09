### 解题思路
此处撰写解题思路
1、每一步跳跃后看落点的区域，最近和最远点；
2、遍历下一跳最近和最远点之后的区域，确定新的最远点；
3、最远点覆盖了末位，则结束。
代码逻辑简单，运行效果如下：
![跳跃游戏.jpg](https://pic.leetcode-cn.com/652ef669167d4682aee328c3aabf01c510f726e44999b0bd0198d5c140e62b37-%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.jpg)

### 代码

```c
int jump(int* nums, int numsSize){
    if(numsSize<1)return 0;
    int step = 0;
    int minPos = 0;
    int minTmp = 0;
    int maxPos = 0;
    int maxTmp = 0;
    int minStep = 0;
    int maxStep = 0;

    while(maxPos<numsSize-1){
        minTmp = maxPos;
        maxTmp = minPos;
        for(int i=minPos;i<=maxPos;i++){
            minStep = nums[i] > 0 ? 1 : 0;
            maxStep = nums[i] > 0 ? nums[i] : 0;
            minTmp = i + minStep < minTmp ? i + minStep : minTmp;
            maxTmp = i + maxStep > maxTmp ? i + maxStep : maxTmp;
        }
        minPos = minTmp;
        maxPos = maxTmp;
        step++;
    }
    return step;
}
```