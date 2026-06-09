### 解题思路
此处撰写解题思路

### 代码

```c
int search(int* nums, int numsSize, int target){
int low=0,high=numsSize-1,mid=0;

while(low<=high){
    mid=(low+high)/2;
    if(*(nums+mid)<target) low=mid+1;
    else if(*(nums+mid)>target) high=mid-1;
    else break;
}
if(low>high) return -1;
else return mid;
}
```