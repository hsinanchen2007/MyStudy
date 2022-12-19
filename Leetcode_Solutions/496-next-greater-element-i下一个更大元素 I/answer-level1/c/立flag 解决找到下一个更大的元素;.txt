### 解题思路
此处撰写解题思路
1 step 返回长度,申请空间;
2 step 立flag 判定何时跳出；
3 step 返回指针;
### 代码

```c      
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
     int i=0,j=0 ,flag=0; 
     *returnSize=nums1Size;
     int *p=(int *)malloc(sizeof(int)*nums1Size);
     for(i=0;i<nums1Size;i++)
     {
         for(j=0;j<nums2Size;j++)  // 一次循环完立flag;
         {
             if(nums1[i]==nums2[j] && j-1<nums1Size)  //满足不为最后一个且nums1[i]==nums2[j]；flag=1；
             flag=1;
             else if(flag==1 && nums1[i]<nums2[j] ) //满足条件就跳出;
            {
                  p[i]=nums2[j];
                  break;  
            }
             else 
             p[i]=-1;
         } 
         flag=0; //复原falg=0;        
     }
       return p;
}

```法二普通的循环法;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i,j;
    int *result;
    result=(int *)malloc(sizeof(int)*nums1Size);
    *returnSize=nums1Size;
    for(i=0;i<nums1Size;i++){
        for(j=0;j<nums2Size;j++){
            if(nums2[j]==nums1[i]){
                while(j<nums2Size&&nums2[j]<=nums1[i]){  //判段条件在首while() 由 nums2[j]<=nums1[i]最后跳出的j为需要的j 
                    j++;
                }
                break;
            }
        }
         if(j==nums2Size){
                    result[i]=-1;
                }
                else{
                    result[i]=nums2[j];
                }
    }
    return result;
}