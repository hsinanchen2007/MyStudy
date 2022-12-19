```
 typedef struct po{
     int val,id;//原值，下标值
 }po;
 int cmpfunc (const void * a, const void * b)
{
    return  (*(po*)a).val - (*(po*)b).val ;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans = malloc(sizeof(int)*2);
    po* data = malloc(sizeof(po)*numsSize);
    for(int i=0;i<numsSize;i++){
        data[i].id=i;
        data[i].val=nums[i];
    }
    qsort(data, numsSize, sizeof(data), cmpfunc);//排序O(nlgn)
    for(int i=0;i<numsSize;i++){
        int y=target-data[i].val;//假设组合为(data[i].val, y)，查找y是否存在于nums中 
        int l=i+1,r=numsSize-1,mid,rt=0;//(假定y比data[i].val更大)
        while(l<=r){//二分查找O(lgn)
            mid=(l+r)>>1;
            if(data[mid].val<y)
                l=mid+1;
            else if(data[mid].val == y){
                rt=mid;
                break;
            }
            else
                r=mid-1;
        }
        if(rt){
            ans[0]=data[i].id;
            ans[1]=data[rt].id;
            break;
        }
    }
    *returnSize=2;
    return ans;
}
```
其实思想和哈希是一样的，只不过c语言哈希不好弄，就改排序了23333
执行用时 :8 ms, 在所有 C 提交中击败了97.39%的用户
内存消耗 :8 MB, 在所有 C 提交中击败了14.98%的用户