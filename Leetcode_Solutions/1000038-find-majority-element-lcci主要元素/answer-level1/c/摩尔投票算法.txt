### 解题思路
没有思路，干就完事儿了

### 代码

```c

//新技能get摩尔投票算法
int majorityElement(int* nums, int numsSize){
int s=1;
int mar=nums[0];
int i=1;
for(i;i<numsSize;i++){
    if(nums[i]==mar){
        s++;
    }else{
        s--;
    }
    if(s==0){
        mar=nums[i+1];
    }
}



return mar;

}
```