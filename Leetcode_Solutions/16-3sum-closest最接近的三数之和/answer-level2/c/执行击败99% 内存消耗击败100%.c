### 解题思路
先用qsort排序，再用双指针解题

### 代码

```c
int cmp(int *a,int *b){
    return *a-*b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    int p;//差值
    int fp;//p的绝对值
    int re;//结果
    int now=0,l,r;
    int sum=0;
    
    qsort(nums,numsSize,sizeof(int),cmp);//快排
    int min=10000;
    while(now<numsSize-2){//双指针，循环开始
        sum=0;
        l=now+1;
        r=numsSize-1;
        while(l<r){
            
            sum=nums[now]+nums[l]+nums[r];//和
            p=sum-target;//和与目标数的差值
            
            if(p==0)
                return sum;//如果和与目标值相同，直接返回该值
            else if(p>0){//和小于目标值，右指针向左移 因为左边的数较小，能降低和的值
                r--;
            }
            else{//左指针右移
                l++;
            }
            fp=fabs(p);//差值的绝对值
            if(fp<min){//如果该绝对值比最小的差值绝对值还小，则最小值绝对值设为该数
                min=fp;
                re=sum;//记录下此时的和
            }
        }
        now++;
    }
    return re;
}
```