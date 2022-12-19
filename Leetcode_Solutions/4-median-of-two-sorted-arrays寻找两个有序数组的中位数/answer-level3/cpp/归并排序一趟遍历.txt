### 解题思路
归并排序

### 代码

```cpp
class Solution {
public:
    //归并排序
    int merge[10010];
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int mid=(len1+len2)/2;
        int i=0,j=0;
        int k=0;
        while(i<len1&&j<len2){
            //cout<<k<<" "<<nums1[i]<<" "<<nums2[j]<<endl;
            if(nums1[i]<nums2[j]){
                merge[k++]=nums1[i++];
            }
            else if(nums1[i]>=nums2[j]){
                merge[k++]=nums2[j++];
            }
        }
        while(i<len1){
            merge[k++]=nums1[i++];
        }
        
        while(j<len2){
            merge[k++]=nums2[j++];
        }

        if((len1+len2)%2==0){
            return ((double)(merge[mid-1]+merge[mid])/2.0);
        }
        else{
            return (double)(merge[mid]);
        }
    }
};
```