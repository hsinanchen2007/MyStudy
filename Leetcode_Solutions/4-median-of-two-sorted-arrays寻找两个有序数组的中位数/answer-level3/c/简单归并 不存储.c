### 解题思路
先计算两个数组的中的元素总数sum，将两个数组归并，若总数为偶数：则在归并到sum/2和sum/2+1时将归并的数加和并除2；若总数为奇数：则在归并到sum/2+1时将归并的数直接返回。

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    nums1Size--;
    nums2Size--;
    int loc1 =0,loc2=0,sum=nums1Size+nums2Size+2;/*loc1 loc2 是两个数组当前读取到的位置*/
    int temp = 0;/*用于暂时储存每次归并时提取的元素*/
    int count = 0;/*归并的次数*/
    double anwser = 0;
    if(sum%2==0){
        for(int i=1;i<=sum/2+1;i++){
            if(loc1>nums1Size){
                temp = nums2[loc2];
                loc2++;
                count++;
            }
            else if(loc2>nums2Size){
                temp = nums1[loc1];
                loc1++;
                count++;
            }
            else if(nums1[loc1]<=nums2[loc2]){
                temp = nums1[loc1];
                loc1++;
                count++;
            }
            else{
                temp = nums2[loc2];
                loc2++;
                count++;
            }
            if(count==sum/2||count==sum/2+1){
                anwser+=temp;
            }
        }
    return anwser/2;
    }
    else{
        for(int i=1;i<=sum/2+1;i++){
            if(loc1>nums1Size){
                temp = nums2[loc2];
                loc2++;
                count++;
            }
            else if(loc2>nums2Size){
                temp = nums1[loc1];
                loc1++;
                count++;
            }
            else if(nums1[loc1]<=nums2[loc2]){
                temp = nums1[loc1];
                loc1++;
                count++;
            }
            else{
                temp = nums2[loc2];
                loc2++;
                count++;
            }
            if(count==sum/2+1){
                anwser+=temp;
            }
        }
    return anwser;
    }
}
```