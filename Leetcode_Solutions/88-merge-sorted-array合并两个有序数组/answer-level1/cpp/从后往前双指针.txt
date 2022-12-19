
注意考虑nums2最后如果剩下的话，要合并到nums1中

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,p=m+n-1;
        /*if(m==0){
            nums1=nums2;
            return;
        }
        if(n==0){
            return;
        }*/
        while(p1>=0 && p2>=0){
            if(nums1[p1]>=nums2[p2]){//把大的放到后面
                nums1[p--]=nums1[p1--];
            }
            else{
                nums1[p--]=nums2[p2--];
            }
        }
        while(p2>=0){//nums2还未完全合并到nums1中，此时nums2中的所有数都<num1
            nums1[p--]=nums2[p2--];
        }
        return;
    }
};
```