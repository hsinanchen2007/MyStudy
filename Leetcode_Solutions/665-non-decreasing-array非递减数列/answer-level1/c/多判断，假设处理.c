### 解题思路
（1）一个数字，两个数字，三个数字必然可以调整为非递减数列
（2）找到逆序下标
（3）逆序下标距离末尾一个、两个数字，必然可以调整为非递减数列
（4）不是上面的情况对数组进行调整，分别处理类似2,4,2,3和2,4,1,5的情况
（5）滚动数组直到逆序下标或者末尾
（6）可以到达末尾证明为非递减数列，否则不是

### 代码

```c
bool checkPossibility(int* nums, int numsSize){
    int i=0,j=0;
    if(numsSize==1||numsSize==2) return true;
    while(i<numsSize-1){
        if(nums[i]>nums[i+1]){
            break;
        }
        i++;
    }
    if((i+1==numsSize)||(i+2==numsSize)) return true;
    if(nums[i]>nums[i+1]&&nums[i]<=nums[i+2]) nums[i+1]=nums[i];
    if(nums[i]>nums[i+1]&&nums[i]>nums[i+2]) nums[i]=nums[i+1];
    while(j<numsSize-1){
        if(nums[j]>nums[j+1]){
            break;
        }
        j++;
    }
    j++;
    if(j==numsSize) return true;
    else return false;

}
```