### 解题思路
1.设置快慢指针，快指针指向不为0的数，慢指针表示数组的当前已经赋值的位置
2.循环结束时，快指针fast遍历完整个数组，慢指针slow到快指针fast之间就是要赋值为0的地方
3.当for循环写成如下时，理论上是一致的，不知为何，执行时间却多了很多。
for(slow=fast=0;fast<numsSize;fast++){
        if(nums[fast] != 0){
            nums[slow++] = nums[fast];
        }
    }

### 代码

```c

//快慢指针
void moveZeroes(int *nums, int numsSize){
    int slow,fast;
    for(slow=fast=0;fast<numsSize;){
        if(nums[fast] == 0){
            fast++;
        }else{
            nums[slow++] = nums[fast++];
        }
    }
    for(int i=slow;i<numsSize;i++){
        nums[i]=0;
    }
}
```