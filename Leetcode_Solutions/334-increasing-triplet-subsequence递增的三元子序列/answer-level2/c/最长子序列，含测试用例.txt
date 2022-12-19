### 解题思路

脑海中想到的就是找到最长子序列的题目，思路是这样的：
记录前一个数的递增长度，若遇到比其小的则重新计数，同时将新旧递增长度比较作为最大递增长度
然后发现了第一个问题：不一定是连续递增子序列，详见注释代码
Fail Ex.[2,1,5,0,4,6]
然后遇到一系列问题：入参未判断等详见注释
Fail Ex.[]
最后发现一个大问题：
当后面数变更小导致长度不够但是突然有个大数满足一开始较小数时之前的要求则算法失败
Fail Ex.[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,3]
后来参考了题解发现有一个巧妙的解决方案：不重新计数，理由详见注释，最终通过
执行用时：12ms 内存消耗：7.5MB

### 测试用例(必测)
[1,2,3,4,5]
[5,4,3,2,1]
[2,1,5,0,4,6]
[0,3,1,2]
[]
[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,3]

### 代码

```c
bool increasingTriplet(int* nums, int numsSize){
    //不一定是连续递增子序列
    /*
    int length=0;
    int i;
    for(i=1;i<numsSize;i++){
        if(nums[i]>nums[i-1]){
            length++;
            if(length==2){
                break;
            }
        }
        else{
            length=0;
        }
    }
    return (length==2)?true:false;
    */
    //入参判断
    if(nums==NULL||numsSize<3){
        return false;
    }
    //记录前一个数的递增长度，若遇到比其小的则重新计数，同时将新旧递增长度比较作为最大递增长度
    //会遇到一个问题:当后面数变更小导致长度不够但是突然有个大数满足之前的要求则算法失败
    int tempLen=0;
    int i;
    int minFirstNumber=nums[0];
    int minSecondNumber=nums[0];
    for(i=1;i<numsSize;i++){
        if(nums[i]>minFirstNumber){
            if(tempLen==0){
                minSecondNumber=nums[i];
                tempLen=1;
            }
            else if(tempLen==1){
                //当遇到更小的第二个数时应该替换掉
                if(nums[i]>minSecondNumber){
                    tempLen=2;
                    break;
                }
                else{
                    minSecondNumber=nums[i];
                }
            }
            else{
            }
        }
        //当相等时则不需要重新计算
        else if(nums[i]==minFirstNumber){

        }
        else{
            minFirstNumber=nums[i];
            //当不重新计数时，若有比当前first更大的则会自动更新templen
            //若有比以前sencond更大的则直接返回
            //tempLen=0;
        }
    }
    return (tempLen==2)?true:false;
}
```