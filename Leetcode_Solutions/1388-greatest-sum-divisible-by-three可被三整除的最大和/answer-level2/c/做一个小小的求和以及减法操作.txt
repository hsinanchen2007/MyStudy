### 解题思路
![leetcode.PNG](https://pic.leetcode-cn.com/3fca381a7ec42320d032cbfa53f084083e10f484c3ecc850f84c9419eb72fa91-leetcode.PNG)

思路已经在注释处用蹩脚的英文给出了,大体就是这样：
1. 首先将所有数加起来
2. 同时找出模3余2的最小的两个数以及模3余1的两个数
3. 最后判断sum模3余几，余0直接返回；余1就考虑减去最小的余1的数，或者和最小的两个余2的数，详见**case1**部分；余2与余1相反，查看**case2**部分
4. 最后别忘了default，虽然这里永远不可能进入，但是这个语法很无奈！

### 代码

```c
/*
calculate the sum of the nums
divide the nums into 3 groups, named mod 0, mod 1, mod 2;
let the sum mod 3, if the result is zero, return;
if the result is 1, delete the smallest num in mod 1 group
if the result is 2, delete the smallest num in mod 2 group
*/

int maxSumDivThree(int* nums, int numsSize){
    int min_mod_1_1 = 10001;
    int min_mod_1_2 = 10001;
    int min_mod_2_1 = 10001;
    int min_mod_2_2 = 10001;
    int sum = 0;
    for(int numIndex = 0; numIndex < numsSize; numIndex++){
        sum += nums[numIndex];
        if(nums[numIndex] % 3 == 1){
            if(nums[numIndex] < min_mod_1_2){
                if(nums[numIndex] < min_mod_1_1){
                    min_mod_1_2 = min_mod_1_1;
                    min_mod_1_1 = nums[numIndex];
                }
                else{
                    min_mod_1_2 = nums[numIndex];
                }
                
            }
        }
        else if(nums[numIndex] % 3 == 2){
            if(nums[numIndex] < min_mod_2_2){
                if(nums[numIndex] < min_mod_2_1){
                    min_mod_2_2 = min_mod_2_1;
                    min_mod_2_1 = nums[numIndex];
                }
                else{
                    min_mod_2_2 = nums[numIndex];
                }
                
            }
        }
    }

    switch(sum % 3){
        case 0:
            return sum;
        case 1:
            return sum - (min_mod_1_1 < (min_mod_2_1+min_mod_2_2) ? min_mod_1_1 : (min_mod_2_1+min_mod_2_2));
        case 2:
            return sum - (min_mod_2_1 < (min_mod_1_1+min_mod_1_2) ? min_mod_2_1 : (min_mod_1_1+min_mod_1_2));
        default:
            return 0;
    }
}
```