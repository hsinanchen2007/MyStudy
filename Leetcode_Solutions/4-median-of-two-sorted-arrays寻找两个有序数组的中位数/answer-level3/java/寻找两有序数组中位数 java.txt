### 解题思路
终于自己搞定了一道题！！！扫了一眼官方代码，看不懂，看了一下别人的思路。自己不断试错，终于通过了。各种情况都要考虑到。
基本思想是这样的：
    1.首先是两个有序数组，求他们的中位数，就要考虑到他们长度之和是奇数还是偶数
    2.分别求得两个数组的长度len1和len2，然后创建一个数组ans存放两数组重新排序的结果
    3.根据两数组总长度是奇偶分两种情况，不过内容都差不多
        3.1求得奇偶对应的mid
        3.2for循环，奇就循环到ans[mid-1]的位置，偶就循环到ans[mid]的位置
        3.3循环内进行两数组比较，小值放在ans[i]，但是之前为了防止[0,1][2,3]这种情况，就需要在比较两数组值之前判断两个数组的索引j和k是否越界，进行ans[i]=未越界数组的赋值，所以循环内是if-else的情况
        3.4循环完成，因为返回的是double，所以奇就返回(double)ans[mid-1],偶就返回((double)(ans[mid-1]+ans[mid]))/2
还提交了三次错误答案，主要是考虑疏忽，第一次没考虑[0,1][2,3]的情况，第二次是偶数情况哪里忘了怎么整除/2等于小数，就直接return (double)(ans[mid-1]+ans[mid])/2)+0.5;真是愚蠢。第三次是因为判断越界那里，本来是j写成了i，太不应该了。
虽然这代码比不上大佬的，但还是超开心，继续加油。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int[] ans = new int[(len1+len2)/2 + 1];
        if((len1+len2)%2 != 0){
            int mid = (len1+len2)/2 + 1;
            for(int i = 0,j=0,k=0;i<mid;i++){
                if(j>=len1){
                    ans[i] = nums2[k];
                    k++;
                }else if(k>=len2){
                    ans[i] = nums1[j];
                    j++;
                }else if(nums1[j]<=nums2[k]){
                    ans[i] = nums1[j];
                    j++;
                }else{
                    ans[i] = nums2[k];
                    k++;
                }
            }
            return (double)ans[mid-1];
        } else{
            int mid = (len1+len2)/2;
            for(int i = 0,j=0,k=0;i<=mid;i++){
                if(j>=len1){
                    ans[i] = nums2[k];
                    k++;
                }else if(k>=len2){
                    ans[i] = nums1[j];
                    j++;
                }else if(nums1[j]<=nums2[k]){
                    ans[i] = nums1[j];
                    j++;
                }else{
                    ans[i] = nums2[k];
                    k++;
                }
            }
            return ((double)(ans[mid-1]+ans[mid]))/2;
        }
    }
}
```