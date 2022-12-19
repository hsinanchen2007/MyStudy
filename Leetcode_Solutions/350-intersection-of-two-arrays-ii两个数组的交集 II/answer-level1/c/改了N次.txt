我哭了，改了N次，终于过了，先排序再用双指针法，不过使用qsort函数的时候要注意compare函数的返回，因为测试点中的元素包括了signed int 的下限， 所以不能进行减法，只能通过判断来返回
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int compare(const void*a, const void*b){
   if(*(int*)a>*(int*)b) return 1;
   if(*(int*)a<*(int*)b) return -1;
   else return 0;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *ans=(int*)malloc(sizeof(int)*1000);
    // memset(ans,0,sizeof(struct abc)*1000);
    int cnt1, cnt2, pos1=0, pos2=0, flag, count=0, number;
    qsort(nums1,nums1Size,sizeof(int),compare);
     qsort(nums2,nums2Size,sizeof(int),compare);
     while(pos1<nums1Size && pos2<nums2Size){
         if(nums1[pos1]==nums2[pos2]){
             cnt1=0, cnt2=0;
             flag=nums2[pos2];
             for(pos1;pos1<nums1Size && nums1[pos1]==flag; pos1++) cnt1++;
             for(pos2;pos2<nums2Size && nums2[pos2]==flag; pos2++) cnt2++;
             number= cnt1>cnt2 ? cnt2 : cnt1;
             while(number--) ans[count++]=flag;
         }
         else if(nums1[pos1]>nums2[pos2]) pos2++;
         else pos1++;
     }
     *returnSize=count;
     return ans;
}
```