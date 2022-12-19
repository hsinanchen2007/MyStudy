### 解题思路
1.从数组第一项开始作为候选人can，对应的票数count=1。
2.之后每遇到相同就票数count加一，不同就票数减一。
3.在减一后，应判断count是否为负数，为负数则淘汰候选人，设置候选人can为当前的数组元素，count初始化为1。
4.当循环结束时，count必定大于等于1，其对应的候选人can就是所求主元素。

### 代码

```c


int majorityElement(int* nums, int numsSize){
    int count=1,can=nums[0];
    for(int i=1;i<numsSize;i++){
        if(can==nums[i]){
            count++;
        }else{
            count--;
            if(count<0){
                can=nums[i];
                count=1;
            }
        }
    
    }
    return can;
}


```