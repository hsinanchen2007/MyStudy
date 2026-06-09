[https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/he-bing-yi-hou-zhao-gui-bing-guo-cheng-zhong-zhao-/]()
参考这个思路用c编写
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size_left = (nums1Size + nums2Size + 1)/2;
    int i = 0, j = size_left-i;
    double max_left,min_right;
    if(nums1Size > nums2Size){  
        int *temp,t;
        temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        t = nums1Size;
        nums1Size = nums2Size;
        nums2Size = t;
    }
    if(nums1Size==0 && nums2Size==0)
        return 0;
    else if(nums1Size==0){
        max_left = nums2[(nums2Size-1)/2];
        min_right = nums2[nums2Size/2];
    } 
    else{
        while(i<=nums1Size){
            if(i == nums1Size){
                if(j==0)
                    max_left = nums1[i-1]; 
                else
                    max_left = nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1];
                min_right = nums2[j];
                break;
            }
            else if(nums1[i]>=nums2[j-1]){
                if(i==0){
                    if(j==nums2Size)
                        min_right = nums1[i];
                    else
                        min_right = nums1[i]<nums2[j]?nums1[i]:nums2[j];
                    max_left = nums2[j-1];
                    break;
                }
                max_left = nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1];
                min_right = nums1[i]<nums2[j]?nums1[i]:nums2[j];
                break;

            }
            else{   
                i++;
                j = size_left-i;
            }    
        }
    }
    if((nums1Size + nums2Size)%2 == 0)
        return (max_left+min_right)/2;
    else
        return max_left;

}

```
![20200114144432611.png](https://pic.leetcode-cn.com/f51b5e261fae07e39be7408510ea047cfa4ba56542f129d37027bb30b7934dc0-20200114144432611.png)
