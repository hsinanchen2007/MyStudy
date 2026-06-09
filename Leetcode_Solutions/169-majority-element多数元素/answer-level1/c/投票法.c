### 解题思路
设置candidate与count两个变量，遍历数组。如果count==0则将当前值赋给candiadate。若count！=0则比较当前值与candidate，相同count++，不同count--。最后输出candidate。

### 代码

```c
int majorityElement(int* nums, int numsSize){
      int cndidate=nums[0],count=1;
      for(int i=1;i<numsSize;i++){
          if(count==0){
              cndidate=nums[i];
              count++;
          }
          else{
              if(cndidate==nums[i]) count++;
              else count--;
          }
    
      }
      return cndidate;
}
```