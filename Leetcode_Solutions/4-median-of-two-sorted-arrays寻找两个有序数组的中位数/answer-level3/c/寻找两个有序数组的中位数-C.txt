```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size = nums1Size + nums2Size, mid = size/2;
    int i=0, j=0;
    
    if(size%2 != 0){
        while(i+j<mid && i<nums1Size && j<nums2Size){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        if(i==nums1Size){
            while(i+j<mid){
                j++;
            }

            return (double)nums2[j];
        }
        else if(j==nums2Size){
            while(i+j<mid){
                i++;
            }

            return (double)nums1[i];
        }
        else{
            return nums1[i]<nums2[j]?(double)nums1[i]:(double)nums2[j];
        }
    }

    else{
        while(i+j<mid-1 && i<nums1Size && j<nums2Size){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        if(i==nums1Size){
            while(i+j<mid){
                j++;
            }
            if(j>0)
                j--;

            return ((double)nums2[j] + (double)nums2[j+1])/2;
        }
        else if(j==nums2Size){
            while(i+j<mid){
                i++;
            }
            if(i>0)
                i--;

            return ((double)nums1[i] + (double)nums1[i+1])/2;
        }
        else{
            int num1, num2;
            
            num1 = nums1[i]<nums2[j]?nums1[i++]:nums2[j++];
            if(j==nums2Size) num2 = nums1[i++];
            else if(i==nums1Size) num2 = nums2[j++];
            else{
                num2 = nums1[i]<nums2[j]?nums1[i++]:nums2[j++];
            }
            
            return ((double)num1 + (double)num2)/2;
        }
    }
}
```
