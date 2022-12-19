### 解题思路
此处撰写解题思路
拿到这道题先思考什么情况下跳不到最后面的位置，很明显当数组中出现0的时候，有可能只能停在原地而跳不动。下面是我的代码，有详细注释。
### 代码

```c
bool canJump(int* nums, int numsSize){


    
    if(numsSize==1)return true;//特殊情况1：只有一个元素的数组
    if(nums[0]==0&&numsSize>1)return false;//特殊情况2：开头是0，但数组的长度大于1，无论如何他只能在原地
    for(int i =0;i<numsSize;++i)//找到数组中是0的元素
    {
        if(nums[i]==0&&i!=numsSize-1)//特殊情况3：最后一个元素是0的话不用做下面的操作了，已经成功了
        {
            if(nums[i-1]==1||nums[i-1]==0)//如果前一个元素是0或者1那有可能跨不过当前的0位置，因为前面的数可能最多只能跨到当前的0位置，如果前面有很大的元素那就有可能跨过0位置，如下判断：
            {
                int com = 1;
                int flag = 0;//能跨过为1，不能为0
                for(int j=i-1;j>=0;j--)//开始判断当前0元素的前面元素是否能跨过当前0位置
                {
                    if(nums[j]-nums[i]>com)//能跨过
                    {
                        flag = 1;
                        break;//能跨过了就不用再继续找前面的数了，跳出来执行最外层循环继续找0
                    }
                    else
                    com++;
                }
                if(flag==0)return false;
            }
        }
    }
    return true;

}
```