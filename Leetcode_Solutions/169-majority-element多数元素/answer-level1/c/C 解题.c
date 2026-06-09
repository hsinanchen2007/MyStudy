### 解题思路
因为多数元素大于n/2，所以每一个多数元素和非多数元素抵消后剩下的元素肯定是大于0的多数元素
所以假设第一个元素是多数元素，碰到不同的数计数减一，计数为0就跳到下一个元素（此时前面的元素都一一抵消了），最后剩下的就是多数元素

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int num = nums[0];
    int count = 0;
        for(int i = 0; i < numsSize; i++){
            if(num == nums[i])
                count++;
            else
                count--;    
            if(count <= 0)
                num = nums[i + 1];
        }
    return num;
}
```