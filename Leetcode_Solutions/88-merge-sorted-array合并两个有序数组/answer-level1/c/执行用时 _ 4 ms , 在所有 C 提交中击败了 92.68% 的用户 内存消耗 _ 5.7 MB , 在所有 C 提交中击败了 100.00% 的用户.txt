### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int nums3[nums1Size];
    int i,j;
    for(i=0;i<m;i++) nums3[i]=nums1[i];
    i=0;j=0;
    while(1){
        if(i<m&&j<n){
            if(nums3[i]<nums2[j]){
                *nums1=nums3[i];
                i++;
            }
            else{
                *nums1=nums2[j];
                j++;
            }
            nums1++;
        }
        else if(i==m&&j<n){
            *nums1=nums2[j];
            j++;
            nums1++;
        }
        else if(i<m&&j==n){
            *nums1=nums3[i];
            i++;
            nums1++;
        }
        else if(i==m&&j==n){
            break;
        }
    }
}
```