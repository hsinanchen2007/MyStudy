
两个有序数组，利用归并的方法，使前(nums1.size()+nums2.size())/2+1个数有序，再计算(help[mid-1]+help[mid])/2.0f即可。
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> help(nums1.size()+nums2.size());
        float ans;
        int i=0,j=0;
        int k=0;
        int mid=help.size()/2;
        for(;i<nums1.size()&&j<nums2.size();){
            if(k>mid){//中位数在中间，所以只到一半就足够了
                goto enough;
            }
            if(nums1[i]<nums2[j]){
                help[k++]=nums1[i];
                i++;
            }else{
                help[k++]=nums2[j];
                j++;
            }
           
        }
        while(i<nums1.size()){
            if(k>mid){
                goto enough;
            }
            help[k++]=nums1[i];
            i++;
        }
        while(j<nums2.size()){
            if(k>mid){
                goto enough;
            }
            help[k++]=nums2[j];
            j++;
        }
        enough:
        if(help.size()%2==1){//奇数个
            ans=help[mid];
        }else{//偶数个
            ans=(float)(help[mid-1]+help[mid])/2.0f;
        }
        return ans;
    }
};
```