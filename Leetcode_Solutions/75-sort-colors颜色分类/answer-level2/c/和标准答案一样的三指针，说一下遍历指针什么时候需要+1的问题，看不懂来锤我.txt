### 解题思路
cur+1只有两种情况
1、nums[cur]==1   这个没啥说的肯定要进行cur+1，他又不用交换
2、nums[cur]==0   nums[cur]和nums[i]交换，这时需要cur+1，因为交换前，nums[i]不可能等于2。这又是为什么呢，因为cur>=i,没交换前nums[i]不可能等于2，已经被cur遍历过了i
3、nums[cur]==2   这是不需要cur+1,因为交换过去的nums[j]有可能是0,cur+1这个0就没法处理了

### 代码

```c
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sortColors(int* nums, int numsSize){
    int i=0;
    int j=numsSize-1;
    int cur=0;
    while(cur<=j){
        if(nums[cur]==0){
            swap(&nums[i],&nums[cur]);
            i++;
            cur++;
        }
        else if(nums[cur]==2){
            swap(&nums[j],&nums[cur]);
            j--;
        }
        else
            cur++;
        
    }
}
```