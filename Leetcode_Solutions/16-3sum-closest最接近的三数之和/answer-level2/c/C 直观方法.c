### 解题思路
1.排序
2.设置三个指针。i指针从头至尾遍历。j、k在i的循环内部，j指针初值为i+1，k指针初值为numsSize-1。
3.判断三数之和与target的大小，并移动j或k。
4.j=k时，跳出最内层循环，i++，j、k设为初值，回到3，直到i=numsSize-2或ans==target
### 代码

```c
int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; // 快排构造递增序列
}

int threeSumClosest(int* nums, int numsSize, int target){
    int i=0,j=i+1,k=numsSize-1,ans=nums[i]+nums[j]+nums[k]-target,temp;
    qsort(nums, numsSize, sizeof(int), comp);//快速排序
    for(;i<numsSize-1;i++){
        j=i+1;k=numsSize-1;
        while(j<k){
            temp=nums[i]+nums[j]+nums[k]-target;
            ans=abs(ans)>abs(temp)?temp:ans;
            if(temp>0) k--;
            else if(temp<0) j++;
            else return ans+target;
        }
    }
    return ans+target;
}


```